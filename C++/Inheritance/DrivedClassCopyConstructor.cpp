//: C14:CopyConstructor.cpp
// Correctly creating the copy-constructor
#include <iostream>
using namespace std;
class Parent {
 int i;
public:
 Parent(int ii) : i(ii) {
 cout << "Parent(int ii)\n";
 }
 Parent(const Parent& b) : i(b.i) {
 cout << "Parent(const Parent&)\n";
 }
 Parent() : i(0) { cout << "Parent()\n"; }
 friend ostream&
 operator<<(ostream& os, const Parent& b) {
 return os << "Parent: " << b.i << endl;
 }
};
class Member {
 int i;
public:
 Member(int ii) : i(ii) {
 cout << "Member(int ii)\n";
 }
 Member(const Member& m) : i(m.i) {
 cout << "Member(const Member&)\n";
 }
 friend ostream&
 operator<<(ostream& os, const Member& m) {
    return os << "Member: " << m.i << endl;
 }
};
class Child : public Parent {
 int i;
 Member m;
public:
 Child(int ii) : Parent(ii), i(ii), m(ii) {
 cout << "Child(int ii)\n";
 }
 friend ostream&
 operator<<(ostream& os, const Child& c){
 return os << (Parent&)c << c.m
 << "Child: " << c.i << endl;
 }
};
int main() {
 Child c(2);
 cout << "calling copy-constructor: " << endl;
 Child c2 = c; // Calls copy-constructor
 cout << "values in c2:\n" << c2;
} ///:~

/*
 * Note: 
 * You can see that Child has no explicitly-defined copy-constructor.
The compiler then synthesizes the copy-constructor (since that is
one of the four functions it will synthesize, along with the default
constructor – if you don’t create any constructors – the operator=
and the destructor) by calling the Parent copy-constructor and the
Member copy-constructor. This is shown in the output

O/p:
Parent(int ii)
Member(int ii)
Child(int ii)
calling copy-constructor:
Parent(const Parent&)
Member(const Member&)
values in c2:
Parent: 2
Member: 2
Child: 2

However, if you try to write your own copy-constructor for Child
and you make an innocent mistake and do it badly:
Child(const Child& c) : i(c.i), m(c.m) {}
********************************************************************************************
then the default constructor will automatically be called for the
base-class part of Child, since that’s what the compiler falls back on
when it has no other choice of constructor to call.
********************************************************************************************
(remember that
some constructor must always be called for every object, regardless
of whether it’s a subobject of another class). The output will then
be:
Parent(int ii)
Member(int ii)
Child(int ii)
calling copy-constructor:
Parent()
Member(const Member&)
values in c2:
Parent: 0
Member: 2
Child: 2

This is probably not what you expect, since generally you’ll want
the base-class portion to be copied from the existing object to the
new object as part of copy-construction.
To repair the problem you must remember to properly call the
base-class copy-constructor (as the compiler does) whenever you
write your own copy-constructor. This can seem a little strangelooking at first but it’s another example of upcasting:

Child(const Child& c)
 : Parent(c), i(c.i), m(c.m) {
 cout << "Child(Child&)\n";
 }

The strange part is where the Parent copy-constructor is called:
Parent(c). What does it mean to pass a Child object to a Parent
constructor? But Child is inherited from Parent, so a Child
reference is a Parent reference. 
********************************************************************
The base-class copy-constructor call
upcasts a reference to Child to a reference to Parent and uses it to
perform the copy-construction.
*********************************************************************
When you write your own copy
constructors you’ll almost always want to do the same thing.
*/
