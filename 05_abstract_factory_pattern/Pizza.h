#ifndef _PIZZA_H
#define _PIZZA_H

#include <string>
#include <iostream>
#include "ingredient.h"

using namespace std;

class Pizza
{
public:
    Dough dough;
    Vegtable vegtable;
    Meat meat;

    virtual void prepare() {};

    virtual void cook() {
        cout << "cook pizza" << endl;
    }

    virtual void package() {
        cout << "package pizza" << endl;
    }
};

class MeatPizza : public Pizza
{
public:
    MeatPizza(PizzaIngredintFactory *fac) : factory(fac) {};

    void prepare() override {
        dough = factory->createDough();
        vegtable = factory->createVegtable();
        meat = factory->createMeat();

        cout << "Meat Pizza" << endl;
        cout << "meat: " << meat.get() << endl;
        cout << "vegtable: " << vegtable.get() << endl;
        cout << "dough: " << dough.get() << endl;
    };
private:
    PizzaIngredintFactory *factory;
};

class VegtablePizza : public Pizza
{
public:
    VegtablePizza(PizzaIngredintFactory *fac) : factory(fac) {};

    void prepare() override {
        dough = factory->createDough();
        vegtable = factory->createVegtable();

        cout << "Vegtable Pizza" << endl;
        cout << "vegtable: " << vegtable.get() << endl;
        cout << "dough: " << dough.get() << endl;
    };

private:
    PizzaIngredintFactory *factory;
};

#endif