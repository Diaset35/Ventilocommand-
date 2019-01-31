#include <IRremote.h>
IRrecv irReceiver(2);
decode_results results;

#include <L293D.h>
L293D motor(6,5,4);



void setup() {
  Serial.begin(9600);
  motor.set(0);
  irReceiver.enableIRIn();

}

void loop() {
    if (irReceiver.decode(&results)) {
    // le code infrarouge est dans la variable results.value
    Serial.println(results.value);
    irReceiver.resume();
    
    if(results.value == 16769565) {
    motor.set(0);  
    
    }else if (results.value == 16753245) {
    motor.set(120);
    
    }else if(results.value == 16724175) {
    motor.set(140);
    
    }else if (results.value== 16718055) {
    motor.set(190);
   
   }else if (results.value == 16743045)  {
    motor.set(230);
  }
    }
}
    
  
