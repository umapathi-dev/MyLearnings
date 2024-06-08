#include <iostream>
class Tree {
 int height;
public:
 Tree(int treeHeight) : height(treeHeight) {}
 ~Tree() { std::cout << "*"; }
 friend std::ostream&
 operator<<(std::ostream& os, const Tree* t) {
 return os << "Tree height is: "
 << t->height << std::endl;
 }
};
//: C13:NewAndDelete.cpp
// Simple demo of new & delete
using namespace std;
int main() {
 Tree* t = new Tree(40);
 cout << t;
 delete t;
} ///:~
