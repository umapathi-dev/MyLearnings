//: C12:Strings2.cpp
// With auto type conversion
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
class Stringc {
 string s;
public:
 Stringc(const string& str = "") : s(str) {}
 operator const char*() const {
 return s.c_str();
 }
};
int main() {
 Stringc s1("hello"), s2("there");
 strcmp(s1, s2); // Standard C function
 strspn(s1, s2); // Any string function!
} ///:~

/*
 * Note:
 * you’d have to create a corresponding function for every one in <cstring> that might be needed. 
 * Fortunately, you can provide an automatic type conversion allowing access to all the functions in <cstring>:
 * Now any function that takes a char* argument can also take a Stringc argument because the compiler knows how to make a char* from a Stringc.
 *
 * /
