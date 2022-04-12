#ifndef _SIMPLE_FACTORY_H
#define _SIMPLE_FACTORY_H
#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

class SimpleAnimalFactory {
public:
    static Animal *createAnimal(string type) {
        if (type == "cat") {
            return new Cat();
        } else if (type == "dog") {
            return new Dog();
        } else {
            cout << "unsupport animal type " << type << endl;
        }
    };
};
#endif