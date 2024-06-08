//: C14:Inheritance.cpp
// Simple inheritance
#include <iostream>

using namespace std;

class X {
   int i;
   public:
   X() { i = 10; }
   void set(int ii) { i = ii; }
   int read() const { return i; }
   int permute() { return i = i * 47; }
};

class Y : public X {
   int i; // Different from X's i
   public:
   Y() 
   { i = 0;
     X(); 
   }
   int change() {
      i = permute(); // Different name call
      return i;
   }
   void set(int ii) {
      i = ii;
      X::set(ii); // Same-name function call
   }
};

int main() {
   cout << "sizeof(X) = " << sizeof(X) << endl;
   cout << "sizeof(Y) = "
      << sizeof(Y) << endl;
   Y D;
   cout << "X = " << D.read() << endl;
   D.change();
   // X function interface comes through:
   D.read();
   D.permute();
   // Redefined functions hide base versions:
   D.set(12);
} ///:~ 
