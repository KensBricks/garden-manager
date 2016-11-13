#include <FloatSwitch.h>

FloatSwitch floatSwitch = FloatSwitch(2);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // Serial monitor will display isSafe status every 3s (3000ms)
  floatSwitch.monitor(3000);
}
