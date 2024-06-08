// Using a singly-rooted hierarchy
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Object {
   public:
      virtual ~Object() = 0;
};
// Required definition:
inline Object::~Object() {}
class Stack {
   struct Link {
      Object* data;
      Link* next;
      Link(Object* dat, Link* nxt) :
         data(dat), next(nxt) {}
   }* head;
   public:
   Stack() : head(0) {}
   ~Stack(){
      while(head)
         delete pop();
   }
   void push(Object* dat) {
      head = new Link(dat, head);
   }
   Object* peek() const {
      return head ? head->data : 0;
   }
   Object* pop() {
      if(head == 0) return 0;
      Object* result = head->data;
      Link* oldHead = head;
      head = head->next;
      delete oldHead;
      return result;
   }
};


/* Note:
 *
 * An issue that has been recurring throughout the usage the container classes with void* Stack and Stash is the ownership problem.” 
 * The “owner” refers to who or what is responsible for calling delete for objects that have been created dynamically (using new). 
 * The problem when using containers is that they need to be flexible enough to hold different types of objects. 
 * To do this, the containers have held void pointers and so they haven’t known the type of object they’ve held. 
 * Deleting a void pointer doesn’t call the destructor, so the container couldn’t be responsible for cleaning up its objects.
 *
 * One solution was presented in the example C14:InheritStack.cpp, in which the Stack was inherited into a new class that accepted and
 * produced only string pointers. Since it knew that it could hold only pointers to string objects, it could properly delete them. 
 * This was a nice solution, but it requires you to inherit a new container class for each type that you want to hold in the container.
 *
 *  The problem is that you want the container to hold more than one type, but you don’t want to use void pointers. 
 *  Another solution is to use polymorphism by forcing all the objects held in the container to be inherited from the same base class. 
 *  That is, the container holds the objects of the base class, and then you can call virtual functions – in particular, 
 *  you can call virtual destructors to solve the ownership problem.
 *
 * This solution uses what is referred to as a singly-rooted hierarchy or an object-based hierarchy 
 * (because the root class of the hierarchy is usually named “Object”). 
 * It turns out that there are many other benefits to using a singly-rooted hierarchy; in fact, 
 * every other object-oriented language but C++ enforces the use of such a hierarchy – when you create a class, 
 * you are automatically inheriting it directly or indirectly from a common base class, a base class that 
 * was established by the creators of the language.
 */

// Use multiple inheritance. We want
// both a string and an Object:
class MyString: public string, public Object {
   public:
      ~MyString() {
         cout << "deleting string: " << *this << endl;
      }
      MyString(string s) : string(s) {}
};

int main(int argc, char* argv[]) {
   ifstream in(argv[1]);
   Stack textlines;
   string line;
   // Read file and store lines in the stack:
   while(getline(in, line))
      textlines.push(new MyString(line));
   // Pop some lines from the stack:
   MyString* s;
   for(int i = 0; i < 10; i++) {
      if((s=(MyString*)textlines.pop())==0) break;
      cout << *s << endl;
      delete s;
   }
   cout << "Letting the destructor do the rest:"
      << endl;
} ///:~

/*
 * Note:
 * if you already have a class such as string that you want to be able to put onto the Stack?
 * In this case, the new class must be both a string and an Object, which means it must be inherited from both classes. 
 * This is called multiple inheritance
 */

