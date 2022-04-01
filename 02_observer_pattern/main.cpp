#include <iostream>
#include "WeatherStation.h"

using namespace std;

int main()
{
    WeatherStation *station = new WeatherStation();
    TempDashBoard *tempBoard = new TempDashBoard(station);
    WetDashBoard *wetBoard = new WetDashBoard(station);

    station->setState(30, 59);

    tempBoard->unreg();
    
    station->setState(40, 59);

    return 0;
}