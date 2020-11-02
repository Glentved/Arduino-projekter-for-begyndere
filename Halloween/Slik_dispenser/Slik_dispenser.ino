#include <Servo.h>   //Inkludere servo bibleotek

Servo myservo;   // navngiver vores servo

#define mund_lukket 14    // Servo position hvor munden er lukket
#define mund_snak 22      // Servo position hvor munden er åben, men der ikke falder slik ud
#define mund_giv_slik 33  // Servo position hvor slik falder ud af munden

void setup() {
  pinMode(A1, OUTPUT);   // Lav A1 til en udgang, her er en led fra øjet monteret
  pinMode(A2, OUTPUT);   // Lav A1 til en udgang, her er en led fra øjet monteret
  digitalWrite(A3, LOW); // Stop MP3 afspiller (fjerner/Disabler pull-up modstand på benet)
  myservo.attach(A0);    // monter servo på ben A0 (Tænder for servo)
  myservo.write(mund_lukket);  // Beder servo om at køre til position mund_lukket (14)
}

void loop() {
  int PIR = digitalRead(A4);  // Læs værdi på indgang A4 ( signal fra PIR sensoren )
  if (PIR == HIGH) {          // Hvis PIR signal er HIGH, så gå til funktion snak()
    snak();
  }
  delay(100);                 // Vent 100 milli sekunder og start loopen forfra
}


void snak() {
  digitalWrite(A1, HIGH);    // Tænd for udgang A1, en af LEDerne i øjnene
  digitalWrite(A2, HIGH);    // Tænd for udgang A2, en af LEDerne i øjnene
  pinMode(A3, OUTPUT);       // Gør A3 til en udgang, dette trækker udgangen lav og starter MP3 afspilleren
  delay(500);                // Vent 500 milli sekunder
  pinMode(A3, INPUT);        // Gør A3 til en indgang, dette stopper signalet til MP3 afspilleren
  unsigned long currentMillis = millis() + 5000;    // Kopieret fra blink without delay, vent 5000 milli sekunder
  while (currentMillis > millis() ) {               //  Imens der ikke er gået 5000 milli sekunder kør denne While loop
    myservo.write(random(mund_lukket, mund_snak));  //  Bed servo om at køre til en tilfældig position imellem mund_lukket og mund_snak (14 - 21)
    delay(100);                                     // Vent 100 milli sekunder og køre While loopen igen

  }
  myservo.write(mund_giv_slik);    // Bed servo om at køre til position mund_giv_slik ( 33 ) så der falder slik ud af munden
  delay(60);                       // Vent i 60 milli sekunder
  myservo.write(mund_lukket);      // Bed servo om at køre til position mund_lukket ( 14 )
  delay(2000);                     // Vent i 2000 milli sekunder
  digitalWrite(A1, LOW);           // Sluk for udgang A1, en af LEDerne i øjnene
  digitalWrite(A2, LOW);           // Sluk for udgang A2, en af LEDerne i øjnene
}
