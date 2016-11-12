/* 

<FloatSwitch.cpp>
Description
  
    The purpose of the float switch is to act as a fail-safe
    for the water pump. If the water level in the tank is too low,
    the pump should never be activated. This sketch is the source file for 
    the FloatSwitch class
    
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

include "Arduino.h"
include "FloatSwitch.h"

/* The switch should be instantiated during void setup() of the main program
 *  e.g.
 *  void setup(){
 *  // Create a floatSwitch at pin 13
 *  FloatSwitch floatSwitch(13);
 *  }
 *  
 * 
 */
FloatSwitch::FloatSwitch(int pin){
  pinMode(pin, INPUT);
  _pin = pin;
  _startTime = millis();
}

/* This function should be called in every iteration of void loop() from the main program
 *  
 *  e.g.
 *  void loop() {
 *    floatSwitch.isSafe = floatSwitch.monitor();
 *    
 *    if(floatSwitch.isSafe == true) {
 *      // Continue normal operations
 *      }
 *     else {
 *      // Stop operations
 *     }
 */

bool FloatSwitch::monitor(const int interval){
  unsigned long currentTime = millis();
  
  // 
  if (_startTime - currentTime >= interval){
    _startTime = currentTime;

    // Read voltage at the pin connected to 
    int switchValue = digitalRead(_pin);

    if (switchValue = LOW){
      return false;
    }
    else{
      return true;
    }
    
  }
  
}


