#include <iostream>
#include <string>

using namespace std;

class Base {
   public:
      int f() const {
         cout << "Base::f()\n";
         return 1;
      }
      int f(string) const { return 1; }
      void g(int) {

         cout << "Base::g()\n";
      }
};
class Derived1 : public Base {
   public:
      void g() const {

         cout << "Derived1::g()\n";
      }
};
class Derived2 : public Base {
   public:
      // Redefinition:
      int f() const {
         cout << "Derived2::f()\n";
         return 2;
      }
};
class Derived3 : public Base {
   public:
      // Change return type:
      void f() const { cout << "Derived3::f()\n"; }
};
class Derived4 : public Base {
   public:
      // Change argument list:
      int f(int) const {
         cout << "Derived4::f()\n";
         return 4;
      }
};

int main() {
   string s("hello");
   Derived1 d1;
   // ! d1.g(10); // redefined g() in derived1
   int x = d1.f();
   d1.f(s);
   Derived2 d2;
   x = d2.f();
   //! d2.f(s); // string version hidden
   Derived3 d3;
   //! x = d3.f(); // return int version hidden
   Derived4 d4;
   //! x = d4.f(); // f() version hidden
   x = d4.f(1);
} ///:~

/*
 * Note:
 * If you change the interface of the base class by modifying the
signature and/or return type of a member function from the base
class, then you’re using the class in a different way than inheritance
is normally intended to support. It doesn’t necessarily mean you’re
doing it wrong, it’s just that the ultimate goal of inheritance is to
support polymorphism, and if you change the function signature or
return type then you are actually changing the interface of the base
class. If this is what you have intended to do then you are using
inheritance primarily to reuse code, and not to maintain the
common interface of the base class (which is an essential aspect of
polymorphism). In general, when you use inheritance this way it
means you’re taking a general-purpose class and specializing it for 
a particular need – which is usually, but not always, considered the
realm of composition.
*/
