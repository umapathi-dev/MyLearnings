#include <iostream>
#include <string>

using namespace std;

class Pet {
   string pname;
   public:
   Pet(const string& name) : pname(name) {}
   virtual string name() const { return pname; }
   virtual string description() const {
      return "This is " + pname;
   }
};

class Dog : public Pet {
   string favoriteActivity;
   public:
   Dog(const string& name, const string& activity)
      : Pet(name), favoriteActivity(activity) {}
   string description() const {
      return Pet::name() + " likes to " +
         favoriteActivity;
   }
};

void describe(Pet p) { // Slices the object
   cout << p.description() << endl;
}

int main() {
   Pet p("Alfred");
   Dog d("Fluffy", "sleep");
   describe(p);
   describe(d);
} ///:~

/*
 * Note:
 * Two things are happening in this program. First, because describe( )accepts a Pet object (rather than a pointer or reference),
 * any calls to describe( ) will cause an object the size of Pet to be pushed on the stack and cleaned up after the call. 
 * This means that if an object of a class inherited from Pet is passed to describe( ), 
 * the compiler accepts it, but it copies only the Pet portion of the object.It slices the derived portion off of the object.
 *
 * Now you may wonder about the virtual function call. 
 * Dog::description( )makes use of portions of both Pet (which still exists) and 
 * Dog, which no longer exists because it was sliced off! So what happens when the virtual function is called?
 * You’re saved from disaster because the object is being passed by value. 
 * Because of this, the compiler knows the precise type of the object because the derived object
 * has been forced to become a base object. 
 *
 * When passing by value, the copy-constructor for a Pet object is used, which initializes 
 * the VPTR to the Pet VTABLE and copies only the Pet parts of the object. 
 *
 * There’s no explicit copy-constructor here, so the compiler synthesizes one. Under all interpretations, 
 * the object truly becomes a Pet during slicing.
 *
 * Object slicing actually removes part of the existing object as it copies it into the new object, 
 * rather than simply changing the meaning of an address as when using a pointer or reference.
 *
 * Because of this, upcasting into an object is not done often; in fact,it’s usually something to watch out for and prevent. 
 * Note that, in this example, if description(were made into a pure virtual) function in the base class 
 * (which is not unreasonable, since it doesn’t really do anything in the base class), then the compiler
 * would prevent object slicing because that wouldn’t allow you to “create” an object of the base type 
 * (which is what happens when you upcast by value). 
 * This could be the most important value of pure virtual functions: to prevent object slicing by generating a
 * compile-time error message if someone tries to do it.
*/
