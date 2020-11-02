
#include <Servo.h>  //Inkludere servo bibleotek

Servo myservo;  // navngiver vores servo

void setup() {
  myservo.attach(A3);  // monter servo på ben A3 (Tænder for servo)
}

void loop() {
  int sensorValue = analogRead(A0); //Læs knock sensor værdi på analog ben A0
  if (sensorValue > 5) { //hvis sensorværdi > 5, kør servo
    myservo.attach(A3); //monter servo på ben A3 (Tænder for servo)
    myservo.write(180); //Send signal til at servo skal køre til 180 grader           
    delay(1000);        //vent 1 sekund              
    myservo.detach();   //sluk for servo
    delay(2000);        //vent 2 sekunder mere             

    myservo.attach(A3);//monter servo på ben A3 (Tænder for servo)
    myservo.write(0); //Send signal til at servo skal køre til 0 grader                        
    delay(1000);      //vent 1 sekund                     
    myservo.detach(); //sluk for servo
    delay(4000);      //vent 2 sekunder mere                 

  }
  delay(100);          //lille delay så der ikke læses på analog porten hele tiden, og starter loopen forfra
}
