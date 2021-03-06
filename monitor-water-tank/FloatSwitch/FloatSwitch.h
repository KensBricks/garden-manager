/*

<WaterTank.h>
Description

    The purpose of the WaterTank is to hold water for use in the garden.
    The WaterTank has both a FloatSwitch and a WaterPump. The WaterTank
    monitors the FloatSwitch regularly to make sure it's safe to operate the
    WaterPump.

    Copyright (C) 2016  Kenneth M Moorhead

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef WaterTank_H
#define WaterTank_H

#include "Arduino.h"
#include "FloatSwitch.h"

class WaterTank{
  public:
    // Constructor will create an instance of WaterTank using previously created
    // FloatSwitch and WaterPump.

    WaterTank(FloatSwitch);
    ~WaterTank();

    // The isSafe value can be toggled true or false to signal whether the water
    // level in the tank is high enough for safe operation
    bool isSafe;

    // The monitor function runs at a regular interval to check whether
    // the water level has dropped to an unsafe point
    void monitor(int);

    private:
      int _pin;
      unsigned long _startTime;
};

#endif
