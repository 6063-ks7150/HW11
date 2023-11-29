const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int potentiometerPin = A0; 
const int yellowLedPin = 6;
const int redLedPin = 7;

bool step1Done = false;
bool step2Done = false;

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Step 1: Press Button 1
  if (digitalRead(buttonPin1) == HIGH && !step1Done) {
    step1Done = true;
     

    // Step 2: Turn Potentiometer to the right
    int potValue = analogRead(potentiometerPin);
    if (potValue > 900 && !step2Done) {
      step2Done = true;
      
      // Step 3: Press Button 2
      if (digitalRead(buttonPin2) == HIGH) {
        digitalWrite(redLedPin, LOW);   
        digitalWrite(yellowLedPin, HIGH);
      }
    }
  }

  //  if the sequence is not followed
  if (!(digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH)) {
    step1Done = false;
    step2Done = false;
    digitalWrite(redLedPin, HIGH);   
    digitalWrite(yellowLedPin, LOW); 
  }
}
