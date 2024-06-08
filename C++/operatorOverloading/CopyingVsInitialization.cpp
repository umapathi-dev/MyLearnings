//: C12:CopyingVsInitialization2.cpp
class Fi {};
class Fee {
public:
 Fee(int) {}
 Fee(const Fi&) {}
};
class Fo {
 int i;
public:
 Fo(int x = 0) : i(x) {}
 operator Fee() const { return Fee(i); }
};
int main() {
 Fo fo;
 Fee fee = fo;
} ///:~

/*
 * Note:
 * There is no constructor to create the Fee fee from a Fo object.However, Fo has an automatic type conversion to a Fee. 
 * There’s no copy-constructor to create a Fee from a Fee, but this is one of the special functions the compiler can create for you. 
 * (The default constructor, copy-constructor, operator=, and destructor can be synthesized automatically by the compiler.) 
 * So for the relatively innocuous statement Fee fee = fo;
 * the automatic type conversion operator is called, and a copyconstructor is created. 
 * Use automatic type conversion carefully. As with all operator overloading, it’s excellent when it significantly reduces a coding task, 
 * but it’s usually not worth using gratuitously
 */
