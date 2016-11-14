/*

<WaterTank.cpp>
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

#include "Arduino.h"
#include "FloatSwitch.h"
#include "WaterPump.h"

/* The switch should be instantiated outside void setup() and void loop()
 *  of the main program, after corresponding FloatSwitch and WaterPump declarations
 *  have been made.
 *
 *  e.g.
 *  FloatSwitch floatSwitch = FloatSwitch(2);
 *  WaterPump waterPump = WaterPump(3);
 *  WaterTank waterTank = WaterTank(floatSwitch, waterPump);
 *
 *  void setup(){
 *
 *  }
 *
 *
 */
WaterTank::WaterTank(FloatSwitch floatSwitch, WaterPump waterPump){
  _floatSwitch = floatSwitch;
  _waterPump = waterPump;
}

WaterTank::~WaterTank(){
  //Do nothing
}

void WaterTank::waterPlants(int interval){

  if (_floatSwitch.isSafe == true) {
    _waterPump.runPump(millis(), interval);  
  }

}
