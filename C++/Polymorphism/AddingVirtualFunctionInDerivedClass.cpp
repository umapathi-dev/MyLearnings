//: C15:AddingVirtuals.cpp
// Adding virtuals in derivation
#include <iostream>
#include <string>
using namespace std;
class Pet {
 string pname;
public:
 Pet(const string& petName) : pname(petName) {}
 virtual string name() const { return pname; }
 virtual string speak() const { return ""; }
};
class Dog : public Pet {
 string name;
public:
 Dog(const string& petName) : Pet(petName) {}
 // New virtual function in the Dog class:
 virtual string sit() const {
 return Pet::name() + " sits";
 }
 string speak() const { // Override
 return Pet::name() + " says 'Bark!'";
 }
};
int main() {
 Pet* p[] = {new Pet("generic"),new Dog("bob")};
 cout << "p[0]->speak() = "
 << p[0]->speak() << endl;
 cout << "p[1]->speak() = "
 << p[1]->speak() << endl;

 //! cout << "p[1]->sit() = "
//! << p[1]->sit() << endl; // Illegal
 
 cout << "p[1]->sit() = "
 << ((Dog*)p[1])->sit() << endl; // Here Downcasting back to specific object type.
} ///:~

/*
 *
 * Note:
 * In this case, however, the compiler is working only with a pointer to a base-class object. 
 * The base class has only the speak( ) and name( ) functions, so those is the only functions the compiler will allow you to call.
 * How could it possibly know that you are working with a Dog object, if it has only a pointer to a base-class object?
 * That pointer might point to some other type, which doesn’t have a sit( ) function. 
 * So the compiler is doing its job by protecting you from making virtual calls to functions that exist only in derived classes.
 *
 * There are some less-common cases in which you may know that the pointer actually points to an object of a specific subclass. 
 * If you want to call a function that only exists in that subclass, then you must cast the pointer. 
 * You can remove the error message produced by the previous program like this:
 
((Dog*)p[1])->sit()

* Here, you happen to know that p[1] points to a Dog object, but in general you don’t know that. 
* If your problem is set up so that you must know the exact types of all objects, you should rethink it,because 
* you’re probably not using virtual functions properly. 
* However, there are some situations in which the design works best (or you have no choice) if you know the exact type of all objects
* kept in a generic container. This is the problem of run-time type identification (RTTI).
*
* RTTI is all about casting base-class pointers down to derived-class pointers 
* (“up” and “down” are relative to a typical class diagram, with the base class at the top). 
* Casting up happens automatically, with no coercion, because it’s completely safe. 
* Casting down is unsafe because there’s no compile time information about the actual types, so you must know exactly what type the object is.
* Ifyou cast it into the wrong type, you’ll be in trouble.
*/
