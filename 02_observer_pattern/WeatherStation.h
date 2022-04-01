#ifndef _WEATHERSTATION_H
#define _WEATHERSTATION_H

#include <list>
#include <iostream>

using namespace std;

class Observer
{
public:
    virtual int update() {};
};

class Observerable
{
public:
    int add(Observer *obs) {
        listener.push_back(obs);
    }

    int remove(Observer *obs) {
        listener.remove(obs);
    }

    int notify() {
        for (auto &it : listener) {
            it->update();
        }
    }

    virtual int getTemp() {};
    virtual int getWet() {};

private:
    list<Observer *> listener;
};



class WeatherStation : public Observerable
{
public:
    int getTemp() {
        return temp;
    }

    int getWet() {
        return wet;
    }

    int setState(int lastTemp, int lastWet) {
        temp = lastTemp;
        wet = lastWet;
        notify();
    }

private:
    int temp = 0;
    int wet = 0;
};

class TempDashBoard : public Observer
{
public:
    TempDashBoard(Observerable *sub) : subject(sub) {
        subject->add(this);
    };

    int update() {
        temp = subject->getTemp();
        cout << "TempDashBoard: temp " << temp << " C" << endl;
    }

    int unreg() {
        subject->remove(this);
    }

private:
    Observerable *subject = nullptr;
    int temp;
};

class WetDashBoard : public Observer
{
public:
    WetDashBoard(Observerable *sub) : subject(sub) {
        subject->add(this);
    };
    int update() {
        wet = subject->getTemp();
        cout << "WetDashBoard: wet " << wet << endl;
    }

private:
    Observerable *subject = nullptr;
    int wet;
};

#endif