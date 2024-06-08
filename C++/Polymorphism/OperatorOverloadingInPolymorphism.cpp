//: C15:OperatorPolymorphism.cpp
// Polymorphism with overloaded operators
#include <iostream>
using namespace std;
class Matrix;
class Scalar;
class Vector;
class Math {
   public:
      virtual Math& operator*(Math& rv) = 0;
      virtual Math& multiply(Matrix*) = 0;
      virtual Math& multiply(Scalar*) = 0;
      virtual Math& multiply(Vector*) = 0;
      virtual ~Math() {}
};
class Matrix : public Math {
   public:
      Math& operator*(Math& rv) {
         return rv.multiply(this); // 2nd dispatch
      }
      Math& multiply(Matrix*) {
         cout << "Matrix * Matrix" << endl;
         return *this;
      }
      Math& multiply(Scalar*) {
         cout << "Scalar * Matrix" << endl;
         return *this;
      }
      Math& multiply(Vector*) {
         cout << "Vector * Matrix" << endl;
         return *this;
      }
};
class Scalar : public Math {
   public:
      Math& operator*(Math& rv) {
         return rv.multiply(this); // 2nd dispatch
      }
      Math& multiply(Matrix*) {
         cout << "Matrix * Scalar" << endl;
         return *this;
      }
      Math& multiply(Scalar*) {
         cout << "Scalar * Scalar" << endl;
         return *this;
      }
      Math& multiply(Vector*) {
         cout << "Vector * Scalar" << endl;
         return *this;
      }
};
class Vector : public Math {
   public:
      Math& operator*(Math& rv) {
         return rv.multiply(this); // 2nd dispatch
      }
      Math& multiply(Matrix*) {
         cout << "Matrix * Vector" << endl;
         return *this;
      }
      Math& multiply(Scalar*) {
         cout << "Scalar * Vector" << endl;
         return *this;
      }
      Math& multiply(Vector*) {
         cout << "Vector * Vector" << endl;
         return *this;
      }
};
int main() {
   Matrix m; Vector v; Scalar s;
   Math* math[] = { &m, &v, &s };
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) {
         Math& m1 = *math[i];
         Math& m2 = *math[j];
         m1 * m2;
      }
} ///:~

/*
 * Note:
 * The problem is that, in main( ), the expression m1 * m2 contains two upcast Math references, and thus two objects of unknown type. 
 * A virtual function is only capable of making a single dispatch – that is, determining the type of one unknown object. 
 * To determine both types a technique called multiple dispatching is used in this example, whereby what appears 
 * to be a single virtualfunction call results in a second virtual call. 
 * By the time this secondcall is made, you’ve determined both types of object, and can perform the proper activity.
 *
 * My understanding: 
 * For M*M
 * The multiplilcation operation of Matix called with argument of right hand variable (RHV) argument as matrix (RHV type is identified) which calls 
 * the virtual function of RHV, rv.multiply(this) with left hand argument object whose type is identified in right hand argument virtual member function.
 */
