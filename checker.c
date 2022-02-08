#include <stdio.h>
#include <assert.h>

int CheckTemperatureOutOfRange(float temperature){
  if(temperature < 0 || temperature > 45) {
    return 1;
  }
  return 0;
}

int CheckSOCOutOfRange(float soc){
   if(soc < 20 || soc > 80){
      return 1;
   }
   return 0;
}

int CheckChargeRateOutOfRange(float chargeRate){
    if(chargeRate > 0.8){
        return 1;
    }
    return 0;
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
  if (CheckTemperatureOutOfRange(temperature)) {
    printf("Temperature out of range!\n");
    return 0;
  } 
  if(CheckSOCOutOfRange(soc)) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  if(CheckChargeRateOutOfRange(chargeRate)) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
