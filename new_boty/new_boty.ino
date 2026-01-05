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

#define LEFT true
#define RIGHT false

// speeds
int const MOTOR_ON = 200;
int const MOTOR_OFF = 0;

bool rightMotorOn = false;
bool leftMotorOn = false;

bool leftInput; 
bool centerInput;
bool rightInput;


void setup() {
  delay(5000); // wait 5 seconds to let people move away

  setupPins();
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

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


void TurnUntilMiddle(bool direction){
  while(!centerInput){
    motor(!direction, direction);
    centerInput = digitalRead(centerSensor);
  }
}

void loop() {
  leftInput = digitalRead(leftSensor);
  centerInput = digitalRead(centerSensor);
  rightInput = digitalRead(rightSensor);

  Serial.print(leftInput);
  Serial.print("\t");
  Serial.print(centerInput);
  Serial.print("\t");
  Serial.println(rightInput);

  if(leftInput)  { TurnUntilMiddle(LEFT);  }
  if(rightInput) { TurnUntilMiddle(RIGHT); }

  motor(leftMotorOn, rightMotorOn);
}

void motor(bool right_motor, bool left_motor) {
  analogWrite(ena, right_motor ? MOTOR_ON : MOTOR_OFF);
  analogWrite(enb, left_motor ? MOTOR_ON : MOTOR_OFF);
}
