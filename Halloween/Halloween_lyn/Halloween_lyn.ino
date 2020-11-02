void setup() {
  pinMode(10, OUTPUT);  //Udgang til at tænde og slukke for led strippen
  pinMode(12, OUTPUT);  //Udgang til at vælge hvilken vej strømmen skal gå i motordriveren
  digitalWrite(12, LOW);   //få strømmen til at løbe en vej. HIGH vælger den modsatte vej
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(10, HIGH);   // Tænd for led strippen
  delay(random(30, 110));   // Hold lyset tændt imellem 30 og 110 milli sekunder
  digitalWrite(10, LOW);    // Sluk for led strippen
  delay(random(300, 2000)); // Vent imellem 300 til 2000  milli sekunder og start loopen forfra
}
