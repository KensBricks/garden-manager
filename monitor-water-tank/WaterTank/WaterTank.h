/*

<FloatSwitch.h>
Description

    The WaterTank holds both a FloatSwitch and a WaterPump. By monitoring the
    FloatSwitch, the WaterTank can decide whether or not it is safe to run the
    WaterPump. This sketch is a header for a the WaterTank class

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

#ifndef WaterTank_h
#define WaterTank_h

#include "Arduino.h"
#include "FloatSwitch.h"
#include "WaterPump.h"

class WaterTank{
  public:
    // Constructor will create an instance of FloatSwitch at the designated pin
    WaterTank(FloatSwitch, WaterPump);
    ~WaterTank();

    void waterPlants(int);

    private:
      FloatSwitch _floatSwitch;
      WaterPump _waterPump;
};

#endif
