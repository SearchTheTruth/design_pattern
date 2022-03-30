#include "weapon.h"
#include <string>
#include <iostream>

using namespace std;


void IWeapon::useWeapon()
{
    cout << "use HAND atk moster" << endl;
    cout << "You got hurt, Player HP -5" << endl;
    cout << "===Round Over===" << endl;
}

void Knife::useWeapon()
{
    for (int i = 0; i < 3; i++) {
        cout << "use KNIFE atk monster" << endl;
        cout << "Monster HP -1!" << endl;
    }
    cout << "===Round Over===" << endl;
}

void Axe::useWeapon()
{
    cout << "use AXE atk monster" << endl;
    cout << "Monster HP -5!" << endl;
    cout << "===Round Over===" << endl;
}

void Sword::useWeapon()
{
    cout << "use SWORD atk monster" << endl;
    cout << "Monster HP -10!" << endl;
    cout << "===Round Over===" << endl;
}