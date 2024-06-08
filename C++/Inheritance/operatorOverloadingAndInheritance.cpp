//: C14:OperatorInheritance.cpp
// Inheriting overloaded operators
#include <fstream>
using namespace std;
ofstream out("ByteTest.out");

class Byte {
   unsigned char b;
   public:
   Byte(unsigned char bb = 0) : b(bb) {}
   // No side effects: const member function:
   const Byte
      operator+(const Byte& right) const {
         return Byte(b + right.b);
      }
   const Byte
      operator-(const Byte& right) const {
         return Byte(b - right.b);
      }
   const Byte
      operator*(const Byte& right) const {
         return Byte(b * right.b);
      }
   const Byte
      operator/(const Byte& right) const {
         return Byte(b / right.b);
      }   
   const Byte
      operator%(const Byte& right) const {
         return Byte(b % right.b);
      }
   const Byte
      operator^(const Byte& right) const {
         return Byte(b ^ right.b);
      }
   const Byte
      operator&(const Byte& right) const {
         return Byte(b & right.b);
      }
   const Byte
      operator|(const Byte& right) const {
         return Byte(b | right.b);
      }
   const Byte
      operator<<(const Byte& right) const {
         return Byte(b << right.b);
      }
   const Byte
      operator>>(const Byte& right) const {
         return Byte(b >> right.b);
      }
   // Assignments modify & return lvalue.
   // operator= can only be a member function:
   Byte& operator=(const Byte& right) {
      // Handle self-assignment:
      if(this == &right) return *this;
      b = right.b;
      return *this;
   }
   Byte& operator+=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b += right.b;
      return *this;
   }
   Byte& operator-=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b -= right.b;
      return *this;
   }
   Byte& operator*=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b *= right.b;
      return *this;
   }
   Byte& operator/=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b /= right.b;
      return *this;
   }
   Byte& operator%=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b %= right.b;
      return *this;
   }
   Byte& operator^=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b ^= right.b;
      return *this;
   }
   Byte& operator&=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b &= right.b;
      return *this;
   }
   Byte& operator|=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b |= right.b;
      return *this;
   }
   Byte& operator>>=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b >>= right.b;
      return *this;
   }
   Byte& operator<<=(const Byte& right) {
      if(this == &right) {/* self-assignment */}
      b <<= right.b;
      return *this;
   }
   // Conditional operators return true/false:
   int operator==(const Byte& right) const {
      return b == right.b;
   }
   int operator!=(const Byte& right) const {
      return b != right.b;
   }
   int operator<(const Byte& right) const {
      return b < right.b;
   }
   int operator>(const Byte& right) const {
      return b > right.b;
   }
   int operator<=(const Byte& right) const {
      return b <= right.b;
   }
   int operator>=(const Byte& right) const {
      return b >= right.b;
   }
   int operator&&(const Byte& right) const {
      return b && right.b;
   }
   int operator||(const Byte& right) const {
      return b || right.b;
   } 
   // Write the contents to an ostream:
   void print(std::ostream& os) const {
      os << "0x" << std::hex << int(b) << std::dec;
   }
};

class Byte2 : public Byte {
   public:
      // Constructors don't inherit:
      Byte2(unsigned char bb = 0) : Byte(bb) {}
      // operator= does not inherit, but
      // is synthesized for memberwise assignment.
      // However, only the SameType = SameType
      // operator= is synthesized, so you have to
      // make the others explicitly:
      Byte2& operator=(const Byte& right) {
         Byte::operator=(right);
         return *this;
      }
      Byte2& operator=(int i) {
         Byte::operator=(i);
         return *this;
      }
};
// Similar test function as in C12:ByteTest.cpp:
void k(Byte2& b1, Byte2& b2) {
   b1 = b1 * b2 + b2 % b1;
#define TRY2(OP) \
   out << "b1 = "; b1.print(out); \
   out << ", b2 = "; b2.print(out); \
   out << "; b1 " #OP " b2 produces "; \
   (b1 OP b2).print(out); \
   out << endl;
   b1 = 9; b2 = 47;
   TRY2(+) 
      TRY2(-) TRY2(*) TRY2(/)
      TRY2(%) TRY2(^) TRY2(&) TRY2(|)
      TRY2(<<) TRY2(>>) TRY2(+=) TRY2(-=)
      TRY2(*=) TRY2(/=) TRY2(%=) TRY2(^=)
      TRY2(&=) TRY2(|=) TRY2(>>=) TRY2(<<=)
      TRY2(=) // Assignment operator
      // Conditionals:
#define TRYC2(OP) \
      out << "b1 = "; b1.print(out); \
      out << ", b2 = "; b2.print(out); \
      out << "; b1 " #OP " b2 produces "; \
      out << (b1 OP b2); \
      out << endl;
      b1 = 9; b2 = 47;
   TRYC2(<) TRYC2(>) TRYC2(==) TRYC2(!=) TRYC2(<=)
      TRYC2(>=) TRYC2(&&) TRYC2(||)
      // Chained assignment:
      Byte2 b3 = 92;
   b1 = b2 = b3;
}
int main() {
   out << "member functions:" << endl;
   Byte2 b1(47), b2(9);
   k(b1, b2);
} ///:~'

/*
 * Note:
 * you’ll see that the constructor must be explicitly defined, and that only the operator= that 
 * assignsa Byte2 to a Byte2 is synthesized; any other assignment operators that you need you’ll have to synthesize on your own.
 */
