//: C14:FName1.cpp
// An fstream with a file name
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class FName1 {
 ifstream file;
 string fileName;
 bool named;
public:
 FName1() : named(false) {}
 FName1(const string& fname)
 : fileName(fname), file(fname.c_str()) {
 if(!fileName.empty());
 named = true;
 }
 string name() const { return fileName; }
 void name(const string& newName) {
 if(named) return; // Don't overwrite
 fileName = newName;
 named = true;
 }
 operator ifstream&() { return file; }
};
int main() {
 FName1 file("FName1.cpp");
 cout << file.name() << endl;
 // Error: close() not a member:
//! file.close();
} ///:~

/*
 * Note:
 * There’s a problem here, however. An attempt is made to allow the
use of the FName1 object anywhere an ifstream object is used by
including an automatic type conversion operator from FName1 to
an ifstream&. But in main, the line

file.close();

will not compile because automatic type conversion happens only
in function calls, not during member selection. So this approach
won’t work.

A second approach is to add the definition of close( ) to FName1:
void close() { file.close(); }
This will work if there are only a few functions you want to bring
through from the ifstream class. In that case you’re only using part
of the class, and composition is appropriate.

But what if you want everything in the class to come through? This
is called subtyping because you’re making a new type from an
existing type, and you want your new type to have exactly the
same interface as the existing type (plus any other member
functions you want to add), so you can use it everywhere you’d use
the existing type. This is where inheritance is essential. You can see
that subtyping solves the problem in the preceding example
perfectly: 
 */
