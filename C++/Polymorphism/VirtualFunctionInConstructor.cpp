#include<iostream>
using namespace std;

class Base
{
   int a;
   public:

   Base(int aa = 0):a(aa)
   {
      cout<<"Called Base class constructor"<<endl;
   }
   virtual void print()
   {
      cout<<"Base class value : "<< a <<endl;
   }
};

class Drived1 : public Base
{
   int a1;
   public:

   Drived1(int aa = 0):Base(10),a1(aa)
   {
      cout<<"Called Drived1 class constructor"<<endl;
      print(); //Calling Virtual member function inside constructor make call to local version of print.
               //Here vptr is set until to current object type and it is like compiler make early binding with function call.  
   }
   void print()
   {
      cout<<"Drived1 class value : "<< a1 <<endl;
   }
};


class Drived2 : public Drived1
{
   int a2;
   public:

   Drived2(int aa = 0):Drived1(100),a2(aa)
   {
      cout<<"Called Drived2 class constructor"<<endl;
   }
   void print()
   {
      cout<<"Drived2 class value : "<< a2 <<endl;
      
   }
};

int main()
{
   Drived2 d2(1000); 
   Drived1 *dPtr = &d2;
   dPtr->print();
   return 0;
}

/*
 *
 * Note:
 * When a constructor is called, one of the first things it does is initialize its VPTR. 
 * However, it can only know that it is of the “current” type – the type the constructor was written for. 
 * The constructor code is completely ignorant of whether or not the object is in the base of another class.
 * When the compiler generates code for that constructor, it generates code for a constructor of that 
 * class, not a base class and not a class derived from it (because a class can’t know who inherits it). 
 * So the VPTR it uses must be for the VTABLE of that class. 
 * The VPTR remains initialized to that VTABLE for the rest of the object’s lifetime unless this isn’t the last constructor call. 
 * If a more-derived constructor is called afterwards, that constructor sets the VPTR to its VTABLE, and so on, 
 * until the last constructor finishes. The state of the VPTR is determined by the constructor that is called last.
 * This is another reason why the constructors are called in order from base to most-derived.
 *
 * But while all this series of constructor calls is taking place, each constructor has set the VPTR to its own VTABLE. 
 * If it uses the virtual mechanism for function calls, it will produce only a call through its own VTABLE, 
 * not the most-derived VTABLE (as would be the case after all the constructors were called). 
 * In addition, many compilers recognize that a virtual function call is being made inside a constructor, 
 * and perform early binding because they know that late-binding will produce a call only to the local function. 
 * In either event, you won’t get the results you might initially expect from a virtual function call inside a constructor.
 */

