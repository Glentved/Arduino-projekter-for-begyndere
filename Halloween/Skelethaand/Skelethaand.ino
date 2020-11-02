#include <afstandssensor.h>  //Inkludere afstandssensor bibleotek


// AfstandsSensor(triggerPin, echoPin);
AfstandsSensor afstandssensor(7, 6);  // Starter afstandssensoren på ben 7 og 6.

void setup () {
  Serial.begin(9600);  // Opsætter serial kommunikation tilbage til computeren
  pinMode(12, OUTPUT);  //Ben til retning på motoren
  pinMode(10, OUTPUT);  //Ben til hastigheds styring
}

void loop () {
  
  int distance = afstandssensor.afstandCM();  //Læs værdi fra afstandssensoren og gem den i distance
  Serial.println(distance);  //Send værdien til computeren
  if (distance < 300 && distance > 0) {  //Hvis afstanden er under 300cm køres med motoren
    digitalWrite(12, HIGH);  //Kør motor op
    digitalWrite(10, HIGH);  //motor start
    delay(9000);             //tid motoren er om at køre op
    digitalWrite(10, LOW);   //motor stop
    
    delay(2000);            //tid hvor hånden bliver oppe
    
    digitalWrite(12, LOW);   //Kør motor ned
    digitalWrite(10, HIGH);  //motor start
    delay(7000);             //tid motoresn er om at køre ned
    digitalWrite(10, LOW);   //motor stop
    delay(5000);  //tid til næste gang sensoren kan aktiveres
  }
  
  delay(500);  //Lille delay så der ikke læses fra afstandssensoren hele tiden, herefter gentages loopen
}
