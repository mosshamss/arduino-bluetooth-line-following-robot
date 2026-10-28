#define IRL A0 //output 2
#define IRR A2 //output 4
#define IN1 9
#define IN2 8
#define IN3 5
#define IN4 4
#define ENB 3
#define ENA 11
String x;
bool R, L;
int speed = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // initialize serial communication with baud rate 9600 bit/s
  Serial.setTimeout(100);
  pinMode(IRL, INPUT);
  pinMode(IRR, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) { // if arduino received data through RX pin
    x = Serial.readStringUntil('\n'); // then read the data
    Serial.println(x);
  }
  if (x == "IR0") // line follower mode
  {
    analogWrite(ENA, 65);
    analogWrite(ENB, 65);
    R = digitalRead (IRR);
    L = digitalRead (IRL);
    Serial.println(R);
    // Serial.println(L);
    if (L == 1 && R == 1)
    {
      forward();
    }
    else if (L == 1 && R == 0)
    {
      right();
    }
    else if (L == 0 && R == 1)
    {
      left();
    }
  }
  else // controller mode (bluetooth module)
  {
    // forward
    if (x == "F0")
    {
      forward();
    }
    // backward
    if (x == "B0") {
      backward();
    }
    // right
    if (x == "R0") {
      right();
    }
    // left
    if (x == "L0") {
      left();
    }
    // stop
    if (x == "S0") {
      stop();
    }
    // Increment speed
    if (x == "I0") {
      speed += 50;
      if (speed > 250) {
        speed = 250;
      }
    }
    // Decrement speed
    if (x == "D0") {
      speed -= 50;
      if (speed < 0) {
        speed = 0;
      }
    }
    x = "A";
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
    Serial.println(speed);
  }
  
}
void forward ()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void left()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void backward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void stop()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
