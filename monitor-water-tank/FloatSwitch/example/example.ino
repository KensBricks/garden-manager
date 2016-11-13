#include <FloatSwitch.h>

// Create a floatSwitch at digital port 2
FloatSwitch floatSwitch = FloatSwitch(2);


void setup() {
  // Default Arduino Uno baud
  Serial.begin(9600);
}

void loop() {
  // Serial monitor will display isSafe status every 3s (3000ms)
  floatSwitch.monitor(3000);
}
