/*

<FloatSwitch.h>
Description

    The purpose of the float switch is to act as a fail-safe
    for the water pump. If the water level in the tank is too low,
    the pump should never be activated. This sketch is a header for a the FloatSwitch
    class

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

#ifndef FloatSwitch_H
#define FloatSwitch_H

#include "Arduino.h"

class FloatSwitch{
  public:
    // Constructor will create an instance of FloatSwitch at the designated pin
    FloatSwitch(int);
    ~FloatSwitch();

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
