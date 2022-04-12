#ifndef _STARBUZZ_H
#define _STARBUZZ_H

#include <string>

using namespace std;

class BaseDrink
{
public:
    string description = "no base drink";
    virtual double cost() {
        return 0;
    };
    virtual const string getDescription() {
        return description;
    }
};

class ExtractCoffee : public BaseDrink
{
public:
    ExtractCoffee() {
        description = "ExtractCoffee";
    }

    double cost() override {
        return 1;
    }
};

class DarkCoffee : public BaseDrink
{
public:
    DarkCoffee() {
        description = "DarkCoffee";
    }

    double cost() override {
        return 1.5;
    }
};

class AddThings : public BaseDrink
{
public:
    AddThings(BaseDrink *initBase) : base(initBase) {};
    BaseDrink *base;
    string description = "no add things";

    const string getDescription() override {
        return description + " " + base->getDescription();
    }
};

class Milk : public AddThings
{
public:
    Milk(BaseDrink *initBase) : AddThings(initBase) {
        description = "milk";
    }

    double cost() override {
        return 0.5 + base->cost();
    }
};

class Sugger : public AddThings
{
public:
    Sugger(BaseDrink *initBase) : AddThings(initBase) {
        description = "sugger";
    }

    double cost() override {
        return 0.3 + base->cost();
    }
};

#endif