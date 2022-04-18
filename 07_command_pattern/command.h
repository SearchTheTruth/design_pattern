#ifndef _COMMAND_H
#define _COMMAND_H
//为了简洁，command，invoker，receiver都在此文件中
#include <iostream>
#include <string>
#include <memory>
#include <deque>

using namespace std;

/*******receiver********/
class Light
{
public:
    int on() {
        cout << "turn light on" << endl;
        return 0;
    }

    int off() {
        cout << "turn light off" << endl;
        return 0;
    }
};

class GarageDoor
{
public:
    int up() {
        cout << "GarageDoor up" << endl;
        return 0;
    }

    int down() {
        cout << "GarageDoor down" << endl;
        return 0;
    }

    int stop() {
        cout << "GarageDoor stop" << endl;
        return 0;
    }

    int lightOn() {
        cout << "GarageDoor light turn on" << endl;
        return 0;
    }
    
    int lightOff() {
        cout << "GarageDoor light turn off" << endl;
        return 0;
    }
};

class Fan {
public:
    enum Speed {
        OFF,
        MINIMUM,
        MIDDLE,
        MAXIMUM,
    };

    string SpeedToStr[4] = {"OFF", "MINIMUM", "MIDDLE", "MAXIMUM"};

    Speed getSpeed() {
        return fanSpeed;
    }

    int setSpeed(Speed target) {
        fanSpeed = target;
        cout << "set Fan speed to " << SpeedToStr[target] << endl;
        return 0;
    }

    int off(){
        fanSpeed = OFF;
        cout << "set Fan speed to OFF" << endl;
        return 0;
    }

private:
    Speed fanSpeed = OFF;
};

/*******command********/
class Command
{
public:
    virtual int execute() {};
    virtual int undo() {};
};

class NunCommand : public Command  //NunCommand do nothing
{
public:
    int execute() {
        cout << "cmd is empty, do nothing" << endl;
    }

    int undo() {
        cout << "cmd is empty, do nothing" << endl;
    }
};

class LightOnCommand : public Command
{
public:
    LightOnCommand(Light *inLight) : light(inLight) {};
    int execute() {
        light->on();
        return 0;
    }

    int undo() {
        light->off();
        return 0;
    }
private:
    Light *light;
};

class LightOffCommand : public Command
{
public:
    LightOffCommand(Light *initLight) : light(initLight) {};
    int execute() {
        light->off();
        return 0;
    }

    int undo() {
        light->on();
        return 0;
    }
private:
    Light *light;
};

class GarageDoorOnCommand : public Command 
{
public:
    GarageDoorOnCommand(GarageDoor *initGarage) : garageDoor(initGarage) {};
    int execute() {
        garageDoor->lightOn();
        garageDoor->up();
        return 0;
    }

    int undo() {
        garageDoor->lightOff();
        garageDoor->down();
        return 0;
    }

private:
    GarageDoor *garageDoor;
};

class GarageDoorOffCommand : public Command
{
public:
    GarageDoorOffCommand(GarageDoor *initGarage) : garageDoor(initGarage) {};
    int execute() {
        garageDoor->lightOff();
        garageDoor->down();
        return 0;
    }

    int undo() {
        garageDoor->lightOn();
        garageDoor->up();
        return 0;
    }

private:
    GarageDoor *garageDoor;
};

class FanMinCommand : public Command
{
public:
    FanMinCommand(Fan *initFan) : fan(initFan) {};
    int execute() {
        prevSpeed = fan->getSpeed();
        fan->setSpeed(Fan::MINIMUM);
        return 0;
    }

    int undo() {
        fan->setSpeed(prevSpeed);
        return 0;
    }

private:
    Fan::Speed prevSpeed;
    Fan *fan;
};

class FanMaxCommand : public Command
{
public:
    FanMaxCommand(Fan *initFan) : fan(initFan) {};
    int execute() {
        prevSpeed = fan->getSpeed();
        fan->setSpeed(Fan::MAXIMUM);
        return 0;
    }

    int undo() {
        fan->setSpeed(prevSpeed);
        return 0;
    }

private:
    Fan::Speed prevSpeed;
    Fan *fan;
};

class FanOffCommand : public Command
{
public:
    FanOffCommand(Fan *initFan) : fan(initFan) {};
    int execute() {
        prevSpeed = fan->getSpeed();
        fan->off();
        return 0;
    }

    int undo() {
        fan->setSpeed(prevSpeed);
        return 0;
    }

private:
    Fan::Speed prevSpeed;
    Fan *fan;
};

class MacroCommand : public Command
{
public:
    MacroCommand(deque<shared_ptr<Command>> cmds) : commands(cmds) {};
    int execute() {
        cout << "+++++++++Macro Command execute++++++++++" << endl;
        for(auto &it : commands) {
            it->execute();
        }
        return 0;
    }

    int undo() {
        cout << "+++++++++Macro Command undo++++++++++" << endl;
        for(auto beg = commands.rbegin(); beg != commands.rend(); beg++) {
            (*beg)->undo();
        }
        return 0;
    }
private:
    deque<shared_ptr<Command>> commands;
};

/*******invoker********/
class RemoteControler
{
public:
    RemoteControler() {
        for(int i = 0; i < slotCnt; i++) {
            onCommands[i] = make_shared<NunCommand>();
            offCommands[i] = make_shared<NunCommand>();
        }
    }
    int setCommand(int slot, shared_ptr<Command> onCmd, shared_ptr<Command> offCmd) {
        if (slot > slotCnt) {
            cout << "Slot(" << slot << ") is unsupport" << endl;
            return -1;
        }
        onCommands[slot] = onCmd;
        offCommands[slot] = offCmd;
        return 0;
    }

    int onBtnWasPushed(int slot) {
        cout << "Slot(" << slot << "): ";
        lastCmd = onCommands[slot];
        return onCommands[slot]->execute();
    }
    int offBtnWasPushed(int slot) {
        cout << "Slot(" << slot << "): ";
        lastCmd = offCommands[slot];
        return offCommands[slot]->execute();
    }
    int undoBtnWasPushed() {
        cout << "Undo: ";
        return lastCmd->undo();
    }
private:
    static constexpr int slotCnt = 5;
    shared_ptr<Command> onCommands[slotCnt];
    shared_ptr<Command> offCommands[slotCnt];
    shared_ptr<Command> lastCmd;
};

#endif