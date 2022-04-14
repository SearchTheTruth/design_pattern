#ifndef _INGREDIENT_H
#define _INGREDIENT_H

#include <string>

using namespace std;

class Dough {
public:
    string dough;
    const string &get() {
        return dough;
    }
};

class Vegtable {
public:
    string vegtable;
    const string &get() {
        return vegtable;
    }
};

class Meat {
public:
    string meat;
    const string &get() {
        return meat;
    }
};

class PizzaIngredintFactory {
public:
    virtual Dough createDough() {};
    virtual Vegtable createVegtable() {};
    virtual Meat createMeat() {};
};

class NYPPizzaIngredintFactory : public PizzaIngredintFactory {
public:
    Dough createDough() override {
        Dough nypDough;
        nypDough.dough = "NYP Dough";
        return nypDough;
    }

    Vegtable createVegtable() override {
        Vegtable nypVeg;
        nypVeg.vegtable = "NYP Vegtable";
        return nypVeg;
    }

    Meat createMeat() override {
        Meat nypMeat;
        nypMeat.meat = "NYP Meat";
        return nypMeat;
    }
};

class CHIGOPizzaIngredintFactory : public PizzaIngredintFactory {
public:
    Dough createDough() override {
        Dough chigoDough;
        chigoDough.dough = "CHIGO Dough";
        return chigoDough;
    }

    Vegtable createVegtable() override {
        Vegtable chigoVeg;
        chigoVeg.vegtable = "CHIGO Vegtable";
        return chigoVeg;
    }

    Meat createMeat() override {
        Meat chigoMeat;
        chigoMeat.meat = "CHIGO Meat";
        return chigoMeat;
    }
};
#endif