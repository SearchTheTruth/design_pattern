#include "command.h"

int main()
{
    RemoteControler *homeCenter = new RemoteControler();

    Fan *fan = new Fan();
    GarageDoor *garageDoor = new GarageDoor();
    Light *light = new Light();

    shared_ptr<FanMaxCommand> fanMaxCmd = make_shared<FanMaxCommand>(fan);
    shared_ptr<FanMinCommand> fanMinCmd = make_shared<FanMinCommand>(fan);
    shared_ptr<FanOffCommand> fanOffCmd = make_shared<FanOffCommand>(fan);

    shared_ptr<GarageDoorOnCommand> doorOnCmd = make_shared<GarageDoorOnCommand>(garageDoor);
    shared_ptr<GarageDoorOffCommand> doorOffCmd = make_shared<GarageDoorOffCommand>(garageDoor);

    shared_ptr<LightOnCommand> lightOnCmd = make_shared<LightOnCommand>(light);
    shared_ptr<LightOffCommand> lightOffCmd = make_shared<LightOffCommand>(light);

    homeCenter->setCommand(0, doorOnCmd, doorOffCmd);
    homeCenter->setCommand(1, lightOnCmd, lightOffCmd);
    homeCenter->setCommand(2, fanMinCmd, fanOffCmd);
    homeCenter->setCommand(3, fanMaxCmd, fanOffCmd);

    homeCenter->onBtnWasPushed(4);
    homeCenter->onBtnWasPushed(1);
    homeCenter->undoBtnWasPushed();
    homeCenter->onBtnWasPushed(1);
    homeCenter->onBtnWasPushed(0);
    homeCenter->offBtnWasPushed(0);
    homeCenter->undoBtnWasPushed();

    deque<shared_ptr<Command>> backHomeOn;
    backHomeOn.push_back(doorOnCmd);
    backHomeOn.push_back(lightOnCmd);
    backHomeOn.push_back(fanMaxCmd);

    deque<shared_ptr<Command>> backHomeOff;
    backHomeOff.push_back(doorOffCmd);
    backHomeOff.push_back(lightOffCmd);
    backHomeOff.push_back(fanOffCmd);

    shared_ptr<MacroCommand> backHomeOnCmd = make_shared<MacroCommand>(backHomeOn);
    shared_ptr<MacroCommand> backHomeOffCmd = make_shared<MacroCommand>(backHomeOff);

    homeCenter->setCommand(4, backHomeOnCmd, backHomeOffCmd);
    homeCenter->onBtnWasPushed(4);
    homeCenter->offBtnWasPushed(4);
    homeCenter->undoBtnWasPushed();

    return 0;
}