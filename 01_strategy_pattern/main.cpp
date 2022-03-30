#include "weapon.h"
#include <string>
#include <iostream>

using namespace std;

class Character
{
public:
    Character(IWeapon *initWeap) : weap(initWeap) {};
    virtual void fight();
    void setWeapon(IWeapon *newWeap);
    IWeapon *weap;
};

void Character::setWeapon(IWeapon *newWeap)
{
    cout << "Change Weap!" << endl;
    weap = newWeap;
}

void Character::fight()
{
    weap->useWeapon();
}


class King : public Character
{
public:
    King(IWeapon *initWeap) : Character(initWeap) {};
    void fight() override;
};

class Queen : public Character
{
public:
    Queen(IWeapon *initWeap) : Character(initWeap) {};
    void fight() override;
};

class Knight : public Character
{
public:
    Knight(IWeapon *initWeap) : Character(initWeap) {};
    void fight() override;
};

void King::fight()
{
    cout << "===King Round===" << endl;
    weap->useWeapon();
}

void Queen::fight()
{
    cout << "===Queen Round===" << endl;
    weap->useWeapon();
}

void Knight::fight()
{
    cout << "===Knight Round===" << endl;
    Character::fight();
}



int main()
{
    Character *player_1 = new King(new Sword());
    Character *player_2 = new Queen(new Knife());

    cout << "Opps, we meet the goblin" << endl;
    player_1->fight();
    player_2->fight();

    cout << "King find a new weapon: Axe atk+5" << endl;
    player_1->setWeapon(new Axe());
    player_1->fight();
    player_2->fight();

    return 0;
}