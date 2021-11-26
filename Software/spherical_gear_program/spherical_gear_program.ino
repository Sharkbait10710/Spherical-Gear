//Bottom Stepper Motor Pins
const int botMotDir = 6;
const int botMotStp = 7;

//Top Stepper Motor Pins
const int topMotDir = 4;
const int topMotStp = 5;

//DEFAULT STEP: 1 step out of 200 step

void setup()
{
  // Declare pins as Outputs
  pinMode(botMotDir, OUTPUT);
  pinMode(botMotStp, OUTPUT);
  pinMode(topMotDir, OUTPUT);
  pinMode(topMotStp, OUTPUT);
  Serial.begin(9600);
}

//Directionality Functions - Sets rotation direction
void botDirCW() {digitalWrite(botMotDir, HIGH);}
void botDirCCW() {digitalWrite(botMotDir, LOW);}
void topDirCW() {digitalWrite(topMotDir, HIGH);}
void topDirCCW() {digitalWrite(topMotDir, LOW);}

//Step Functions - Rotates motor shaft
void botStp_HIGH() {digitalWrite(botMotStp, HIGH);}
void botStp_LOW() {digitalWrite(botMotStp, LOW);}
void topStp_HIGH() {digitalWrite(topMotStp, HIGH);}
void topStp_LOW() {digitalWrite(topMotStp, LOW);}

//Speed Functionalities - Increase the time to decrease speed; converse is true
void StepDelay() {delayMicroseconds(8000);}

//Rotation Functions
void Drive() {botStp_HIGH(); topStp_HIGH(); StepDelay(); botStp_LOW(); topStp_LOW();}
void aboutSkyAxis_CW() {botDirCW(); topDirCCW(); Drive();}
void aboutSkyAxis_CCW() {botDirCCW(); topDirCW(); Drive();}
void aboutDriveAxis_CW() {botDirCW(); topDirCW(); Drive();}
void aboutDriveAxis_CCW() {botDirCCW(); topDirCCW(); Drive();}

void loop()
{
    for (int i = 0; i < 2000; i++) aboutSkyAxis_CW();
    delay(100);
    for (int i = 0; i < 2000; i++) aboutSkyAxis_CCW();
    delay(100);
    for (int i = 0; i < 2000; i++) aboutDriveAxis_CW();
    delay(100);
    for (int i = 0; i < 2000; i++) aboutDriveAxis_CCW();
    delay(100);
}
