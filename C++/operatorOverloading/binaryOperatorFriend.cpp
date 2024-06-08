//: C12:Integer.h
// Non-member overloaded operators
#ifndef INTEGER_H
#define INTEGER_H
#include <iostream>
#include <fstream>
using namespace std;

// Non-member functions:
class Integer {
   long i;
   public:
   Integer(long ll = 0) : i(ll) {}
   // Operators that create new, modified value:
   friend const Integer
      operator+(const Integer& left,
            const Integer& right);
   friend const Integer
      operator-(const Integer& left,
            const Integer& right);
   friend const Integer
      operator*(const Integer& left,
            const Integer& right);
   friend const Integer
      operator/(const Integer& left,
            const Integer& right);
   friend const Integer
      operator%(const Integer& left,
            const Integer& right);
   friend const Integer
      operator^(const Integer& left,
            const Integer& right);
   friend const Integer
      operator&(const Integer& left,
            const Integer& right);
   friend const Integer
      operator|(const Integer& left,
            const Integer& right);
   friend const Integer
      operator<<(const Integer& left,
            const Integer& right);
   friend const Integer
      operator>>(const Integer& left,
            const Integer& right);
   // Assignments modify & return lvalue:
   friend Integer&
      operator+=(Integer& left,
            const Integer& right);
   friend Integer&
      operator-=(Integer& left,
            const Integer& right);
   friend Integer&
      operator*=(Integer& left,
            const Integer& right);
   friend Integer&
      operator/=(Integer& left,
            const Integer& right);
   friend Integer&
      operator%=(Integer& left,
            const Integer& right);
   friend Integer&
      operator^=(Integer& left,
            const Integer& right);
   friend Integer&
      operator&=(Integer& left,
            const Integer& right);
   friend Integer&
      operator|=(Integer& left,
            const Integer& right);
   friend Integer&
      operator>>=(Integer& left,
            const Integer& right);
   friend Integer&
      operator<<=(Integer& left,
            const Integer& right);
   // Conditional operators return true/false:
   friend int
      operator==(const Integer& left,
            const Integer& right);
   friend int
      operator!=(const Integer& left,
            const Integer& right);
   friend int
      operator<(const Integer& left,
            const Integer& right);
   friend int
      operator>(const Integer& left,
            const Integer& right);
   friend int
      operator<=(const Integer& left,
            const Integer& right);
   friend int
      operator>=(const Integer& left,
            const Integer& right);
   friend int
      operator&&(const Integer& left,
            const Integer& right);
   friend int
      operator||(const Integer& left,
            const Integer& right);
   // Write the contents to an ostream:
   void print(std::ostream& os) const { os << i; }
};
const Integer
operator+(const Integer& left,
      const Integer& right) {
   return Integer(left.i + right.i);
}
const Integer
operator-(const Integer& left,
      const Integer& right) {
   return Integer(left.i - right.i);
}
const Integer
operator*(const Integer& left,
      const Integer& right) {
   return Integer(left.i * right.i);
}
const Integer
operator/(const Integer& left,
      const Integer& right) {
   return Integer(left.i / right.i);
}
const Integer
operator%(const Integer& left,
      const Integer& right) {
   return Integer(left.i % right.i);
}
const Integer
operator^(const Integer& left,
      const Integer& right) {
   return Integer(left.i ^ right.i);
}
const Integer
operator&(const Integer& left,
      const Integer& right) {
   return Integer(left.i & right.i);
}
const Integer
operator|(const Integer& left,
      const Integer& right) {
   return Integer(left.i | right.i);
}
const Integer
operator<<(const Integer& left,
      const Integer& right) {
   return Integer(left.i << right.i);
}
const Integer
operator>>(const Integer& left,
      const Integer& right) {
   return Integer(left.i >> right.i);
}
// Assignments modify & return lvalue:
Integer& operator+=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i += right.i;
   return left;
}
Integer& operator-=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i -= right.i;
   return left;
}
Integer& operator*=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i *= right.i;
   return left;
}
Integer& operator/=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i /= right.i;
   return left;
}
Integer& operator%=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i %= right.i;
   return left;
}
Integer& operator^=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i ^= right.i;
   return left;
}
Integer& operator&=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i &= right.i;
   return left;
}
Integer& operator|=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i |= right.i;
   return left;
}
Integer& operator>>=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i >>= right.i;
   return left;
}
Integer& operator<<=(Integer& left,
      const Integer& right) {
   if(&left == &right) {/* self-assignment */}
   left.i <<= right.i;
   return left;
}
// Conditional operators return true/false:
int operator==(const Integer& left,
      const Integer& right) {
   return left.i == right.i;
}
int operator!=(const Integer& left,
      const Integer& right) {
   return left.i != right.i;
}
int operator<(const Integer& left,
      const Integer& right) {
   return left.i < right.i;
}
int operator>(const Integer& left,
      const Integer& right) {
   return left.i > right.i;
}
int operator<=(const Integer& left,
      const Integer& right) {
   return left.i <= right.i;
}
int operator>=(const Integer& left,
      const Integer& right) {
   return left.i >= right.i;
}
int operator&&(const Integer& left,
      const Integer& right) {
   return left.i && right.i;
}
int operator||(const Integer& left,
      const Integer& right) {
   return left.i || right.i;
} ///:~

ofstream out("./IntegerTest.out");

void h(Integer& c1, Integer& c2) {
   // A complex expression:
   c1 += c1 * c2 + c2 % c1;
#define TRY(OP) \
   out << "c1 = "; c1.print(out); \
   out << ", c2 = "; c2.print(out); \
   out << "; c1 " #OP " c2 produces "; \
   (c1 OP c2).print(out); \
   out << endl;
   TRY(+) TRY(-) TRY(*) TRY(/)
      TRY(%) TRY(^) TRY(&) TRY(|)
      TRY(<<) TRY(>>) TRY(+=) TRY(-=)
      TRY(*=) TRY(/=) TRY(%=) TRY(^=)
      TRY(&=) TRY(|=) TRY(>>=) TRY(<<=)
      // Conditionals:
#define TRYC(OP) \
      out << "c1 = "; c1.print(out); \
      out << ", c2 = "; c2.print(out); \
      out << "; c1 " #OP " c2 produces "; \
      out << (c1 OP c2); \
      out << endl;
      TRYC(<) TRYC(>) TRYC(==) TRYC(!=) TRYC(<=)
      TRYC(>=) TRYC(&&) TRYC(||)
}
int main() {
   cout << "friend functions" << endl;
   Integer c1(47), c2(9);
   h(c1, c2);
} ///:~
#endif // INTEGER_H ///:~
