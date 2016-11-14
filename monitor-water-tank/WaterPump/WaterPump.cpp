/*

<WaterPump.cpp>
Description

    The purpose of the WaterPump is to move water out of the WaterTank and into the
    irrigation lines of the garden. This sketch is the source file for
    the WaterPump class.

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
#include "WaterPump.h"

/* The water pump should be instantiated outside void setup() and void loop()
 *  of the main program. The integer input corresponds to the Arduino digital
 *  output pin connected to the pump relay.
 *  e.g.
 *
 *  // Create a waterPump at pin 3
 *  WaterPump waterPump = WaterPump(3);
 *
 *  void setup(){
 *    // Setup steps
 *  }
 *
 *  void loop(){
 *    // Main Arduino operation
 *  }
 *
 *
 */
 WaterPump::WaterPump(byte pin){
     _pin = pin;
     pinMode(_pin, OUTPUT);
     _isRunning = false;
     digitalWrite(_pin, LOW);
     _stopTime = millis();
   }

   WaterPump::~WaterPump(){
     // Do nothing
   }

/* Make sure to include the WaterPump.loop() function at the start of the main
 * Arduino void loop(){}. This will make sure the pump is run asynchronously with
 * the rest of the program.
 *
 * e.g.
 * // Create a WaterPump at digital pin 3.
 * WaterPump waterPump = WaterPump(3);
 *
 * void setup(){
 *  // Your Arduino sketch setup
 * }
 *
 * void loop(){
 * // Arduino loop
 *
 *  waterPump.loop();
 * }
 */

 void WaterPump::loop(){

   if(_isRunning == false){

   }else
   {
     // Turn on the pump
     pumpOn();

   }

 isRunning = _isRunning;

   // Output status every 1000ms (1s)
   if(millis() % 1000 == 0) {
     Serial.print("The WaterPump at pin ");
     Serial.print(_pin);
     Serial.print(" has WaterPump.isRunning = ");
     Serial.println(_isRunning);
   }
 }

/* Use WaterPump.runPump to trigger the water pump on for a supplied time interval.
* Do not use this function without having WaterPump.loop() included in your
* Arduino void loop() function.
*/

 void WaterPump::runPump(int interval){
   _isRunning = true;
   _stopTime = millis() + interval;
 }

// Turns the pump off
 void WaterPump::stopPump(){
   _isRunning = false;
   digitalWrite(_pin, LOW);
 }

/* Private function used by WaterPump.runPump() to turn pump on for supplied
* time interval. Again, imperative to have WaterPump.loop() included in the
* regular Arduino void loop() function.
*/
 void WaterPump::pumpOn(){
   unsigned long currentTime = millis();

   if(currentTime <= _stopTime){
     digitalWrite(_pin, HIGH);
   }else{
     stopPump();
   }

 }
