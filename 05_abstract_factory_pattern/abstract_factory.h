#ifndef _ABSTRACT_FACTORY_H 
#define _ABSTRACT_FACTORY_H

#include "Pizza.h"

class PizzaStore
{
public:
    virtual Pizza *createPizza(const string &type) {};
    virtual Pizza *orderPizza(const string &type) {
        Pizza *pizza = createPizza(type);
        pizza->prepare();
        pizza->cook();
        pizza->package();
        return pizza;
    }
};

class NYPPizzaStore : public PizzaStore
{
public:
    Pizza *createPizza(const string &type) {
        PizzaIngredintFactory *factory = new NYPPizzaIngredintFactory();
        if (type == "vegtable") {
            return new VegtablePizza(factory);
        } else if (type == "meat") {
            return new MeatPizza(factory);
        } else {
            cout << "ileagl pizza type" << endl;
        }
    }
};

class CHIGOPizzaStore : public PizzaStore
{
public:
    Pizza *createPizza(const string &type) {
        PizzaIngredintFactory *factory = new CHIGOPizzaIngredintFactory();
        if (type == "vegtable") {
            return new VegtablePizza(factory);
        } else if (type == "meat") {
            return new MeatPizza(factory);
        } else {
            cout << "ileagl pizza type" << endl;
        }
    }
};
#endif