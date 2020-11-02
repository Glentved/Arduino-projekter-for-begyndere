void setup() {
pinMode(10, OUTPUT); //Signalben til motordriver som styrer magnetventil
pinMode(11, OUTPUT); //Signalben til motordriver som styrer magnetventil
pinMode(12, OUTPUT); //Udgang til at vælge hvilken vej strømmen skal gå i motordriveren
pinMode(13, OUTPUT); //Udgang til at vælge hvilken vej strømmen skal gå i motordriveren
digitalWrite(12,HIGH); //få strømmen til at løbe en vej. LOW vælger den modsatte vej
digitalWrite(13,HIGH); //få strømmen til at løbe en vej. LOW vælger den modsatte vej
}

void loop() {
  byte temp = random(1,4);  // Vælg et tilfældigt tal imellem 1 og 3 (den tæller ikke 4 med)
  if (temp == 1){  // Hvis tallet er 1, gå til funktion sving_side_1();
    sving_side_1();
  }
  if (temp == 2){  // Hvis tallet er 2, gå til funktion sving_side_2();
    sving_side_2();
  }
  if (temp == 3){  // Hvis tallet er 3, gå til funktion sving_frem();
    sving_frem();
  }
delay(random(200,1500));  // Vent imellem 200 til 1500  milli sekunder og start loopen forfra
}

void sving_side_1(){
  digitalWrite(10,HIGH);  //  Tænd for motor driver 1
  delay(random(300,500)); // Vent imellem 300 til 500  milli sekunder
  digitalWrite(10,LOW);   //  Sluk for motor driver 1
}
void sving_side_2(){
  digitalWrite(11,HIGH);  //  Tænd for motor driver 2
  delay(random(300,500)); // Vent imellem 300 til 500  milli sekunder
  digitalWrite(11,LOW);   //  Sluk for motor driver 2
}
void sving_frem(){
  digitalWrite(10,HIGH);  //  Tænd for motor driver 1
  digitalWrite(11,HIGH);  //  Tænd for motor driver 2
  delay(random(300,700)); // Vent imellem 300 til 700  milli sekunder
  digitalWrite(10,LOW);   //  Sluk for motor driver 1
  digitalWrite(11,LOW);   //  Sluk for motor driver 2
}
