const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4; // Corrected variable name
const int onOffSwitchPin = 5; // Corrected variable name
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0; // Added missing variable
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchPin, INPUT); // Corrected variable name
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, LOW); // Corrected variable name
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitchPin); // Corrected variable name
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4; // Corrected variable name

  if (onOffSwitchState != previousOnOffSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  } else {
    analogWrite(enablePin, 0);
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}