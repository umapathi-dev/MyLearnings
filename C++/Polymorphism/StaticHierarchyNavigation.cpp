//: C15:StaticHierarchyNavigation.cpp
// Navigating class hierarchies with static_cast
#include <iostream>
#include <typeinfo>
using namespace std;
class Shape { public: virtual ~Shape() {}; };
class Circle : public Shape {};
class Square : public Shape {};
class Other {};
int main() {
   Circle c;
   Shape* s = &c; // Upcast: normal and OK
   // More explicit but unnecessary:
   s = static_cast<Shape*>(&c);
   // (Since upcasting is such a safe and common
   // operation, the cast becomes cluttering)
   Circle* cp = 0;
   Square* sp = 0;
   // Static Navigation of class hierarchies
   // requires extra type information:
   if(typeid(s) == typeid(cp)) // C++ RTTI
      cp = static_cast<Circle*>(s);
   if(typeid(s) == typeid(sp))
      sp = static_cast<Square*>(s);
   if(cp != 0)
      cout << "It's a circle!" << endl;
   if(sp != 0)
      cout << "It's a square!" << endl;
   // Static navigation is ONLY an efficiency hack;
   // dynamic_cast is always safer. However:
   // Other* op = static_cast<Other*>(s);
   // Conveniently gives an error message, while
   Other* op2 = (Other*)s;
   // does not
} ///:~

/* 
 * Note:
 * C++’s run-time type information (RTTI) mechanism. RTTI allows you to discover type information that has been lost by upcasting. 
 * The dynamic_castis actually one form of RTTI. Here, the typeid
keyword (declared in the header file <typeinfo>) is used to detect
the types of the pointers. You can see that the type of the upcast
Shape pointer is successively compared to a Circle pointer and a
Square pointer to see if there’s a match.C++’s run-time type information (RTTI) mechanism. RTTI allows you
to discover type information that has been lost by upcasting. The
dynamic_castis actually one form of RTTI. Here, the typeid
keyword (declared in the header file <typeinfo>) is used to detect
the types of the pointers. You can see that the type of the upcast
Shape pointer is successively compared to a Circle pointer and a
Square pointer to see if there’s a match.

If a class hierarchy has no virtual functions (which is a questionable
design) or if you have other information that allows you to safely
downcast, it’s a tiny bit faster to do the downcast statically than
with dynamic_cast. In addition, static_cast won’t allow you to cast
out of the hierarchy, as the traditional cast will, so it’s safer.
However, statically navigating class hierarchies is always risky and
you should use dynamic_cast unless you have a special situation.
*/
