
//: C15:DynamicCast.cpp
#include <iostream>
using namespace std;
class Pet { public: virtual ~Pet(){}};
class Dog : public Pet {};
class Cat : public Pet {};
int main() {
 Pet* b = new Cat; // Upcast
 // Try to cast it to Dog*:
 Dog* d1 = dynamic_cast<Dog*>(b);
 // Try to cast it to Cat*:
 Cat* d2 = dynamic_cast<Cat*>(b);
 cout << "d1 = " << (long)d1 << endl;
 cout << "d2 = " << (long)d2 << endl;
} ///:~ 

/* 
 * Note:
 * When you use dynamic_cast, you must be working with a true
polymorphic hierarchy – one with virtual functions – because
dynamic_cast uses information stored in the VTABLE to determine
the actual type. Here, the base class contains a virtual destructor
and that suffices. In main( ), a Cat pointer is upcast to a Pet, and
then a downcast is attempted to both a Dog pointer and a Cat
pointer. Both pointers are printed, and you’ll see when you run the
program that the incorrect downcast produces a zero result. Of
course, whenever you downcast you are responsible for checking to
make sure that the result of the cast is nonzero. Also, you should
not assume that the pointer will be exactly the same, because
sometimes pointer adjustments take place during upcasting and
downcasting (in particular, with multiple inheritance).
*/
