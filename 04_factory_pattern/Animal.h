#ifndef _ANIMAL_H
#define _ANIMAL_H

#include <iostream>

using namespace std;

class Animal {
public:
    virtual void eat() {};
    virtual void whoami() {};
};

class Cat : public Animal {
public:
    void eat() override {
        cout << "I'm Cat, like eat fish!" << endl;
    }

    void whoami() override {
        cout << "whoami: Cat" << endl;
    }
};

class Dog : public Animal {
public:
    void eat() override {
        cout << "I'm Dog, like eat meat!" << endl;
    }

    void whoami() override {
        cout << "whoami: Dog" << endl;
    }
};
#endif