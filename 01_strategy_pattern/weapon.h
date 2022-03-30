#ifndef _WEAPON_H
#define _WEAPON_H

class IWeapon
{
public:
    virtual void useWeapon();
};

class Knife : public IWeapon
{
public:
    void useWeapon() override;
};

class Axe : public IWeapon
{
public:
    void useWeapon() override;
};

class Sword : public IWeapon
{
public:
    void useWeapon() override;
};

#endif