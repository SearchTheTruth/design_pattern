#include "Pizza.h"
#include "abstract_factory.h"

int main()
{
    PizzaStore *nyp = new NYPPizzaStore();
    PizzaStore *chigo = new CHIGOPizzaStore();

    cout << "++++++++++Enter NYP Pizza Store++++++++++++" << endl;
    nyp->orderPizza("meat");

    cout << "++++++++++Enter CHIGO Pizza Store++++++++++" << endl;
    chigo->orderPizza("vegtable");

    return 0;
}