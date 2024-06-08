//: C15:VariantReturn.cpp
// Returning a pointer or reference to a derived
// type during ovverriding
#include <iostream>
#include <string>

using namespace std;

class PetFood {
   public:
      virtual string foodType() const = 0;
};

class Pet {
   public:
      virtual string type() const = 0;
      virtual PetFood* eats() = 0;
};

class Bird : public Pet {
   public:
      string type() const { return "Bird"; }
      class BirdFood : public PetFood {
         public:
            string foodType() const {
               return "Bird food";
            }
      };
      // Upcast to base type:
      PetFood* eats() { return &bf; }
   private:
      BirdFood bf;
};

class Cat : public Pet {
   public:
      string type() const { return "Cat"; }
      class CatFood : public PetFood {
         public:
            string foodType() const { return "Birds"; }
      };
      // Return exact type instead:
      CatFood* eats() { return &cf; }
   private:
      CatFood cf;
};

int main() {
   Bird b;
   Cat c;
   Pet* p[] = { &b, &c, };
   for(int i = 0; i < sizeof p / sizeof *p; i++)
      cout << p[i]->type() << " eats "
         << p[i]->eats()->foodType() << endl;
   // Can return the exact type:
   Cat::CatFood* cf = c.eats();
   Bird::BirdFood* bf;
   // Cannot return the exact type:
   //! bf = b.eats();
   // Must downcast:
   bf = dynamic_cast<Bird::BirdFood*>(b.eats());
} ///:~

/*
 * Note:
 * The Pet::eats( member function returns a pointer to a ) PetFood. 
 * In Bird, this member function is overloaded exactly as in the base class, including the return type. 
 * That is, Bird::eats( upcasts the) BirdFood to a PetFood.
 * But in Cat, the return type of eats( ) is a pointer to CatFood, a type derived from PetFood. 
 * The fact that the return type is inherited from the return type of the base-class function is the only reason this compiles. 
 * That way, the contract is still fulfilled; eats( ) always returns a PetFood pointer.
 *
 * If you think polymorphically, this doesn’t seem necessary. Why not just upcast all the return types to PetFood*, just as Bird::eats( did? )
 * This is typically a good solution, but at the end of main( ), you see the difference: Cat::eats( can return the exact type of ) PetFood, 
 * whereas the return value of Bird::eats( must be downcast to the ) exact type.
 * So being able to return the exact type is a little more general, and doesn’t lose the specific type information by automatically upcasting. 
 * However, returning the base type will generally solve your problems so this is a rather specialized feature.
 */
