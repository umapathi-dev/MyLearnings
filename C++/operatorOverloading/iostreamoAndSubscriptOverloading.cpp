//: C12:IostreamOperatorOverloading.cpp
// Example of non-member overloaded operators
#include <iostream>
#include <sstream> // "String streams"
#include <cstring>
using namespace std;
class IntArray {
   enum { sz = 5 };
   int i[sz];
   public:
   IntArray() { memset(i, 0, sz* sizeof(*i)); }
   int& operator[](int x) {
      return i[x];
   }
   friend ostream&
      operator<<(ostream& os, const IntArray& ia);
   friend istream&
      operator>>(istream& is, IntArray& ia);
};
ostream&
operator<<(ostream& os, const IntArray& ia) {
   for(int j = 0; j < ia.sz; j++) {
      os << ia.i[j];
      if(j != ia.sz -1)
         os << ", ";
   }
   os << endl;
   return os;
}
istream& operator>>(istream& is, IntArray& ia){
   for(int j = 0; j < ia.sz; j++)
      is >> ia.i[j];
   return is;
}
int main() {
   stringstream input("47 34 56 92 103");
   IntArray I;
   input >> I;
   I[4] = -1; // Use overloaded operator[]
   cout << I;
} ///:~
