class Pet {
public:
 char eat() const { return 'a'; }
 int speak() const { return 2; }
 float sleep() const { return 3.0; }
 float sleep(int) const { return 4.0; }
};
class Goldfish : Pet { // Private inheritance
public:
 Pet::eat; // Name publicizes member
 Pet::sleep; // Both overloaded members exposed
};
int main() {
 Goldfish bob;
 bob.eat();
 bob.sleep();
 bob.sleep(1);
//! bob.speak();// Error: private member function
} ///:~

/*
 * Note:
 * Thus, private inheritance is useful if you want to hide part of the functionality of the base class.
 * Notice that giving the name of an overloaded function exposes all the versions of the overloaded function in the base class.
 * 
 * You should think carefully before using private inheritance instead of composition; private inheritance has particular complications
 * when combined with runtime type identification.
*/
