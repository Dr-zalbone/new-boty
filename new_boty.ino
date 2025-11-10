#define ena 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define enb 10

int const black_line = 100;
int const on_right = 70;
int const on_left = 50;
int const off = 0;

bool right_motor = false;
bool left_motor = false;

int left;
int center;
int right;


void setup() {
  Serial.begin(9600);
  
  pinMode(OUTPUT, ena);
  pinMode(OUTPUT, in1);
  pinMode(OUTPUT, in2);
  pinMode(OUTPUT, in3);
  pinMode(OUTPUT, in4);
  pinMode(OUTPUT, enb);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void loop() {
  left = analogRead(A0);
  center = analogRead(A1);
  right = analogRead(A2);

  Serial.print(left);
  Serial.print("\t");
  Serial.print(center);
  Serial.print("\t");
  Serial.println(right);

  if (isBlack(left)){
    Serial.print("left motor off ");
    left_motor = false;
  }
  else {
    Serial.print("left motor on ");
    left_motor = true;
  }
  if (isBlack(right)){
    Serial.print("right motor off ");
    right_motor = false;
  }
  else{
    Serial.print("right motor on ");
    right_motor = true;
  }
  Serial.println();
  Serial.println();
  
  motor(left_motor, right_motor);
}

bool isBlack(int value) {
  if(value < black_line){
    return true;
  }
  else {
    return false;
  }
}

void motor(int right_motor, int left_motor) {
  if (right_motor) {
    analogWrite(ena, on_right);
  }
  else {
    analogWrite(ena, off);
  }
  if (left_motor) {
    analogWrite(enb, on_left);
  }
  else {
    analogWrite(enb, off);
  }
}
