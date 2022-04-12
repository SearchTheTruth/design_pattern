#ifndef _FACTORY_H
#define _FACTORY_H
#include "Animal.h"
#include <memory>
#include <iostream>

using namespace std;

class AnimalFactory {
public:
    virtual Animal *createAnimal() {};

    Animal *buyAnimal() {
        Animal *pet = createAnimal();
        pet->whoami();
        return pet;
    }
};

class DogFactory : public AnimalFactory {
public:
    Animal *createAnimal() override {
        cout << "Dog Factory" << endl;
        return new Dog();
    }
};

class CatFactory : public AnimalFactory {
public:
    Animal *createAnimal() override {
        cout << "Cat Factory" << endl;
        return new Cat();
    }
};

#endif