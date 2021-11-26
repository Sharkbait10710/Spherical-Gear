// Define pin connections & motor's steps per revolution
const int dirPin = 6;
const int dirPin2 = 4;
const int stepPin = 7;
const int stepPin2 = 5;
const int stepsPerRevolution = 1600;

void setup()
{
  // Declare pins as Outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
}
void loop()
{
//  // Set motor direction clockwise
//  digitalWrite(dirPin, HIGH);
//
//  // Spin motor slowly
//  for(int x = 0; x < stepsPerRevolution; x++)
//  {
//    digitalWrite(stepPin, HIGH);
//    delayMicroseconds(2000);
//    digitalWrite(stepPin, LOW);
//    delayMicroseconds(2000);
//  }
//  delay(1000); // Wait a second
  
  // Set motor direction counterclockwise
  digitalWrite(dirPin, LOW);
  digitalWrite(dirPin2, HIGH);
  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1000);
  }
  delay(100); // Wait a second

  digitalWrite(dirPin, LOW);
  digitalWrite(dirPin2, LOW);
  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1000);
  }
  delay(100); // Wait a second
}
