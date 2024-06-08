#include <iostream>
#include <fstream>
using namespace std;
// Member functions (implicit "this"):
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

ofstream out("./ByteTest.out");
void k(Byte& b1, Byte& b2) {
   b1 = b1 * b2 + b2 % b1;
#define TRY2(OP) \
   out << "b1 = "; b1.print(out); \
   out << ", b2 = "; b2.print(out); \
   out << "; b1 " #OP " b2 produces "; \
   out << endl; \
   (b1 OP b2).print(out); \
   out << endl;
   b1 = 9; b2 = 47;
   TRY2(+) TRY2(-) TRY2(*) TRY2(/)
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
      Byte b3 = 92;
   b1 = b2 = b3;
}

int main() {
   out << "member functions:" << endl;
   Byte b1(47), b2(9);
   k(b1, b2);
} ///:~
