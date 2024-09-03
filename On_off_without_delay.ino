const int ledPin = 13;

int ledState= LOW;

unsigned long previousMilliSec= 0;

const int interval = 1000;

// To count the itrations for each second
unsigned long startTime= 0;
unsigned long count= 0;

// Controlling led using push button
const int button = 9;
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
 buttonState = digitalRead(button);
 unsigned long currentMilliSec = millis();

// count++;
// if ( currentMilliSec - startTime >= interval){
//  startTime = currentMilliSec;
//  Serial.print("loops per second = ");
//  Serial.println(count);
//  count = 0;
// }

  if (buttonState == HIGH){
      ledState = HIGH;
  }

 else if ( currentMilliSec - previousMilliSec >= interval) {
 
  Serial.print("Previous milliSecond= ");
  Serial.print(previousMilliSec);
  Serial.print("\t current milliSecond= ");
  Serial.println(currentMilliSec);
  
  previousMilliSec = currentMilliSec;

  if (ledState == LOW){
    ledState = HIGH;
  }
  else {
    ledState = LOW;
  }
 
 Serial.println(ledState);
  
 }
digitalWrite(ledPin, ledState);
}
