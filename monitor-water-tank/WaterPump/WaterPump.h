/*

<WaterPump.h>
Description

    The purpose of the WaterPump is to move water out of the WaterTank and into the
    irrigation lines of the garden. This sketch is a header for the WaterPump
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

#ifndef WaterPump_H
#define WaterPump_H

#include "Arduino.h"

class WaterPump{
  public:
    WaterPump(byte);
    ~WaterPump();
    bool isRunning;

    void loop();
    void runPump(int);
    void stopPump();

  private:
    void pumpOn();
    byte _pin;
    bool _isRunning;
    unsigned long _stopTime;
};

#endif
