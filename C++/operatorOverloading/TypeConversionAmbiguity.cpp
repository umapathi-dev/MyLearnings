//: C12:TypeConversionAmbiguity.cpp
class Orange; // Class declaration
class Apple {
   public:
      operator Orange() const; // Convert Apple to Orange
};
class Orange {
   public:
      Orange(Apple); // Convert Apple to Orange
};
void f(Orange) {}
int main() {
   Apple a;
   //! f(a); // Error: ambiguous conversion
} ///:~

/*
 * Note: A simple and obvious situation occurs with a class X that can convert itself to an object of class Y with an operator Y(). 
 * If class  Y has a constructor that takes a single argument of type X, this represents the identical type conversion.
 * The compiler now has two ways to go from X to Y, so it will generate an ambiguity error when that conversion occurs: 
 *
 * The obvious solution to this problem is not to do it. Just provide a single path for automatic conversion from one type to another.
 * A more difficult problem to spot occurs when you provide automatic conversion to more than one type. This is sometimes called fan-out:
  
//: C12:TypeConversionFanout.cpp

class Orange {};
class Pear {};

class Apple {
   public:
      operator Orange() const;
      operator Pear() const;
};
// Overloaded eat():
void eat(Orange);
void eat(Pear);


   int main() {
   Apple c;
//! eat(c);
// Error: Apple -> Orange or Apple -> Pear ???
} ///:

Class Apple has automatic conversions to both Orange and Pear.
The insidious thing about this is that there’s no problem until someone innocently comes along and creates two overloaded
versions of eat( ). (With only one version, the code in main( ) works fine.) 
Again, the solution – and the general watchword with automatic type conversion – is to provide only a single automatic conversion
from one type to another. You can have conversions to other types; they just shouldn’t be automatic. You can create explicit function
calls with names like makeA( ) and makeB( ).
*/
