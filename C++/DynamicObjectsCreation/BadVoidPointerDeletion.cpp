// Deleting void pointers can cause memory leaks
#include <iostream>
using namespace std;
class Object {
 void* data; // Some storage
 const int size;
 const char id;
public:
 Object(int sz, char c) : size(sz), id(c) {
 data = new char[size];
 cout << "Constructing object " << id
 << ", size = " << size << endl;
 }
 ~Object() {
 cout << "Destructing object " << id << endl;
 
delete []data;  // OK, just releases storage,no destructor calls are necessary
//Fix for the above warning issue we have to typecast it to right type. 
//delete static_cast<char *>(data); 
 }
};
int main() {
 Object* a = new Object(40, 'a');
 delete a;
 void* b = new Object(40, 'b');
 free(b);
 //b = nullptr; if not initalized with 0 or nullptr then it crashes when it call delete or free() again. 
 delete b;
 //Fix for the above warning issue we have to typecast it to right type. 
 //delete static_cast<Object *>(b);
} ///:~
