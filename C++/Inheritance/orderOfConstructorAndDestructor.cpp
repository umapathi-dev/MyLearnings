//: C14:Order.cpp
// Constructor/destructor order
#include <fstream>

using namespace std;
ofstream out("order.out");

#define CLASS(ID) class ID { \
   public: \
           ID(int) { out << #ID " constructor\n"; } \
   ~ID() { out << #ID " destructor\n"; } \
};

CLASS(Base1);
CLASS(Member1);
CLASS(Member2);
CLASS(Member3);
CLASS(Member4);

class Derived1 : public Base1 {
   Member1 m1;
   Member2 m2;
   public:

   Derived1(int) : m2(1), m1(2), Base1(3) {
      out << "Derived1 constructor\n";
   }
   ~Derived1() {
      out << "Derived1 destructor\n";
   }
};

class Derived2 : public Derived1 {
   Member3 m3;
   Member4 m4;
   public:
   Derived2() : m3(1), Derived1(2), m4(3) {
      out << "Derived2 constructor\n";
   }
   ~Derived2() {
      out << "Derived2 destructor\n";
   }
};

int main() {
   Derived2 d2;
} ///:~ 

/*
 * Note:
 * You can see that construction starts at the very root of the class hierarchy, and that at each level the base class constructor is called
 * first, followed by the member object constructors. The destructors are called in exactly the reverse order of the constructors – this is 
 * important because of potential dependencies (in the derived-class constructor or destructor, you must be able to assume that the baseclass subobject is still
 * available for use, and has already been constructed – or not destroyed yet).
 *
 */
