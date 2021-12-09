//Bottom Stepper Motor Pins
const int botMotDir = 6;
const int botMotStp = 7;

#define w 119
#define a 97
#define s 115
#define d 100
int accuracy = 2;
String readString;

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
  establishContact();
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

//Rotation Functions; sky-axis relative to top-down. drive-axis relative to non-idle gear starting from top view looking down
void Drive() {botStp_HIGH(); topStp_HIGH(); StepDelay(); botStp_LOW(); topStp_LOW();}
void aboutSkyAxis_CW() {botDirCW(); topDirCCW(); Drive();}
void aboutSkyAxis_CCW() {botDirCCW(); topDirCW(); Drive();}
void aboutDriveAxis_CW() {botDirCW(); topDirCW(); Drive();}
void aboutDriveAxis_CCW() {botDirCCW(); topDirCCW(); Drive();}
void tilt_CW(int stps) {for (int i = 0; i < stps; i++) aboutDriveAxis_CW();}
void run_CW(int stps) {for (int i = 0; i < stps; i++) aboutSkyAxis_CW();}
void tilt_CCW(int stps) {for (int i = 0; i < stps; i++) aboutDriveAxis_CCW();}
void run_CCW(int stps) {for (int i = 0; i < stps; i++) aboutSkyAxis_CCW();}

//For randomizing
bool rand_cond = true;

void loop()
{
  readString = get_Serial();

  if (readString.length() > 0) {
    Serial.println("readString: " + readString);  //so you can see the captured string 
    if (readString == "randomize") rand_cond = true;
    else {rand_cond = false; cmdLine(readString);}
    readString=""; //empty for next input
  } 
  
  if (rand_cond) {randomize(); multistep();}
}

void establishContact() {
  Serial.begin(9600);
}

String get_Serial() {
  String ret = "";
  while (Serial.available()) {
    char c = Serial.read();  //gets one byte from serial buffer
    ret += c; //makes the string readString
    delay(2);  //slow looping to allow buffer to fill with next character
  } return ret;
}

void cmdLine(String str) {
  int n = str.toInt();
  if (n == 0) n = static_cast<int>(readString[0]);
  Serial.println("n: " + readString);  //so you can see the captured string 
  switch(n) {
       case w: tilt_CW(accuracy); break;
       case a: run_CW(accuracy); break;
       case s: tilt_CCW(accuracy); break; 
       case d: run_CCW(accuracy); break; 
       default: accuracy = n; Serial.println("accuracy: " + String(n)); break;
    }
}

void randomize() {
  Serial.println("Program is randomizing spherical motion");
  bool arr[] = {false, false, false, false};
  for (int i = 0; i < 4; i++) {
    int rand_num = random() % 4;
    while (arr[rand_num]) rand_num = random() % 4;
    switch (rand_num) {
      case 0: Serial.println("In progress: tilt_CW"); tilt_CW(random() % 150); arr[0] = true; break;
      case 1: Serial.println("In progress: run_CW"); run_CW(random() % 150); arr[1] = true; break;
      case 2: Serial.println("In progress: tilt_CCW"); tilt_CCW(random() % 150); arr[2] = true; break;
      case 3: Serial.println("In progress: run_CCW"); run_CCW(random() % 150); arr[3] = true; break;
    }
  }
  Serial.println();
}

void multistep() {
  int cond = random() % 4;
  switch (cond) {
    case 0: Serial.println("Multistep 0"); for (int i = 0; i < random() % 500; i++) {tilt_CW(10); run_CW(10);} break;
    case 1: Serial.println("Multistep 1"); for (int i = 0; i < random() % 500; i++) {tilt_CCW(10); run_CCW(10);} break;
    case 2: Serial.println("Multistep 2"); for (int i = 0; i < random() % 500; i++) {tilt_CW(10); run_CCW(10);} break;
    case 3: Serial.println("Multistep 3"); for (int i = 0; i < random() % 500; i++) {tilt_CCW(10); run_CW(10);} break;
    default: Serial.println("No response"); break;
  }
  Serial.println();
}
