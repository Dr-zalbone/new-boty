// pins
#define ena 2
#define in1 3
#define in2 4
#define in3 5
#define in4 6
#define enb 7

#define leftSensor A0
#define centerSensor A1
#define rightSensor A2

// defenitions for sensors and motor speeds
int const black_line = 70;
int const on = 200;
int const off = 0;
// Values of on(true) and off(false) of the right and left motors
bool rightMotorValue = false;
bool leftMotorValue = false;
// Line folloeing sensor inputs
int leftInput; 
int centerInput;
int rightInput;


void setup() {
  delay(5000); // wait 5 seconds to let people move away

  setupPins();
  
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);

  Serial.begin(9600);
}

void setupPins(){
  pinMode(leftSensor, INPUT);
  pinMode(centerSensor, INPUT);
  pinMode(rightSensor, INPUT);


  pinMode(ena, OUTPUT);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enb, OUTPUT);
}

void loop() {
  leftInput = analogRead(leftSensor);
  centerInput = analogRead(centerSensor);
  rightInput = analogRead(rightSensor);

  Serial.print(leftInput);
  Serial.print("\t");
  Serial.print(centerInput);
  Serial.print("\t");
  Serial.println(rightInput);


  if (isBlack(leftInput))  
  { 
    leftMotorValue = false;  
  }
  else                     
  { 
    leftMotorValue = true;   
  }

  if (isBlack(rightInput)) 
  {
    rightMotorValue = false; 
  }
  else                     
  {
    rightMotorValue = true;  
  }
  if (not isBlack(centerInput) and not isBlack(rightInput) and not isBlack(leftInput))
  {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
  }
  else
  {
  motor(leftMotorValue, rightMotorValue);not isBlack(centerInput);
  }

  }
  

bool isBlack(int value) {
  if (value < black_line) { return true;  }
  else                    { return false; }
}

void motor(int right_motor, int left_motor) {

  if (right_motor) { analogWrite(ena, on);  }
  else             { analogWrite(ena, off); }

  if (left_motor)  { analogWrite(enb, on);  }
  else             { analogWrite(enb, off); }
}

void TurnUntilMiddleSensor(bool direction, bool SwitchTrackDirection){
  
}