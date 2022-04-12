#include "StarBuzz.h"
#include <iostream>

using namespace std;

int main()
{
    BaseDrink *coffe = new DarkCoffee();
    cout << coffe->getDescription() << endl;
    cout << coffe->cost() << " $" << endl;

    BaseDrink *addSugger = new Sugger(coffe);
    cout << addSugger->getDescription() << endl;
    cout << addSugger->cost() << " $" << endl;

    BaseDrink *doubleSugger = new Sugger(addSugger);
    cout << doubleSugger->getDescription() << endl;
    cout << doubleSugger->cost() << " $" << endl;

    BaseDrink *muxCoffe = new Sugger(new Milk(new ExtractCoffee()));
    cout << muxCoffe->getDescription() << endl;
    cout << muxCoffe->cost() << " $" << endl;
    return 0;
}