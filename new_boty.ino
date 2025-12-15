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
int const on = 150;
int const off = 0;
// Values of on(true) and off(false) of the right and left motors
bool rightMotorValue = false;
bool leftMotorValue = false;
// Line folloeing sensor inputs
int leftInput; 
int centerInput;
int rightInput;


void setup() {
  Serial.begin(9600);
  
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


  if (isBlack(leftInput)){
    Serial.print("left motor off ");
    leftMotorValue = false;
  } else {
    Serial.print("left motor on ");
    leftMotorValue = true;
  }

  if (isBlack(rightInput)){
    Serial.print("right motor off ");
    rightMotorValue = false;
  } else {
    Serial.print("right motor on ");
    rightMotorValue = true;
  }

  Serial.println();
  Serial.println();
  
  motor(leftMotorValue, rightMotorValue);
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
