#include "Animal.h"
#include "simple_factory.h"
#include "factory.h"
#include <iostream>

using namespace std;

int main ()
{
    cout << "++Simple Factory++" << endl;
    Animal *pet_1 = SimpleAnimalFactory::createAnimal("cat");
    pet_1->eat();

    cout << "++Factory++" << endl;
    AnimalFactory *f = new DogFactory();
    Animal *pet_2 = f->buyAnimal();
    pet_2->eat();

    return 0;
}