//: C14:FName2.cpp
// Subtyping solves the problem
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class FName2 : public ifstream {
 string fileName;
 bool named;
public:
 FName2() : named(false) {}
 FName2(const string& fname)
 : ifstream(fname.c_str()), fileName(fname) {
 if(!fileName.empty());
 named = true;
 }
 string name() const { return fileName; }
 void name(const string& newName) {
 if(named) return; // Don't overwrite
 fileName = newName;
 named = true;
 }
};
int main() {
 FName2 file("FName2.cpp");
 cout << "name: " << file.name() << endl;
 string s;
 getline(file, s); // These work too!
 file.seekg(-200, ios::end);
 file.close();
} ///:~


/*
 * Note:
 * d you want your new type to have exactly the
same interface as the existing type (plus any other member
functions you want to add), so you can use it everywhere you’d use
the existing type. This is where inheritance is essential. You can see
that subtyping solves the problem.
*/
