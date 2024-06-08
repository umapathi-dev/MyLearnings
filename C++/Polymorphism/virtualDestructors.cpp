//: C15:VirtualDestructors.cpp
// Behavior of virtual vs. non-virtual destructor
#include <iostream>
using namespace std;
class Base1 {
public:
 ~Base1() { cout << "~Base1()\n"; }
};
class Derived1 : public Base1 {
public:
 ~Derived1() { cout << "~Derived1()\n"; }
};
class Base2 {
public:
 virtual ~Base2() { cout << "~Base2()\n"; }
};
class Derived2 : public Base2 {
public:
 ~Derived2() { cout << "~Derived2()\n"; }
};
int main() {
 Base1* bp = new Derived1; // Upcast
 delete bp;
 Base2* b2p = new Derived2; // Upcast
  delete b2p;
} ///:~

/*
 * Note:
 * When you run the program, you’ll see that delete bp only calls the base-class destructor, 
 * while delete b2p calls the derived-class destructor followed by the base-class destructor, 
 * which is the behavior we desire. Forgetting to make a destructor virtual is an insidious bug because 
 * it often doesn’t directly affect the behavior of your program, but it can quietly introduce a memory leak. 
 * Also, the fact that some destruction is occurring can further mask the problem.
 *
 * Even though the destructor, like the constructor, is an “exceptional” function, it 
 * is possible for the destructor to be virtual because the object already knows what type it is 
 * (whereas it doesn’t during construction). Once an object has been constructed, its VPTR is initialized, 
 * so virtual function calls can take place.
 */
