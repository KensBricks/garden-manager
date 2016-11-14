#include <WaterPump.h>

WaterPump waterPump = WaterPump(3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  // Watch output in Serial Monitor
  waterPump.loop();

  // Run the water pump for 3 seconds, every six seconds
  if(millis() % 6000 == 0){
  waterPump.runPump(3000);
  }
}
