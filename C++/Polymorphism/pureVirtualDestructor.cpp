//: C15:UnAbstract.cpp
// Pure virtual destructors
// seem to behave strangely
class AbstractBase {
   public:
      virtual ~AbstractBase() = 0;
};

AbstractBase::~AbstractBase() {}

class Derived : public AbstractBase 
{
};

// No overriding of destructor necessary?

int main() { Derived d; } ///:~ 

/*
 * Note:
 *  The pure virtual destructors are legal in Standard C++, there is an added constraint when using them: you must provide a 
 *  function body for the pure virtual destructor.
 *  If you could leave off the definition for a pure virtual destructor, what function body would be called during destruction? 
 *  Thus, it’s absolutely necessary that the compiler and linker enforce the existence of a function body for a pure virtual destructor.
 *
 *  The only difference you’ll see between the pure and non-pure virtual destructor is that the pure virtual destructor 
 *  does cause the base class to be abstract, so you cannot create an object of the base class (although this would also be true 
 *  if any other member function of the base class were pure virtual).
 *
 *  Normally, a pure virtual function in a base class would cause the derived class to be abstract unless 
 *  it (and all other pure virtualfunctions) is given a definition. But here, this seems not to be the case. 
 *  However, remember that the compiler automatically creates a destructor definition for every class if you don’t create one. 
 *  That’s what’s happening here – the base class destructor is being quietly overridden, and thus the definition 
 *  is being provided by the compiler and Derived is not actually abstract.
 *
 *
 */
