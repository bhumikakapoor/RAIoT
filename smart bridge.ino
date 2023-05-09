#include <Servo.h>

const int trigPin = 12;
const int echoPin = 13;
const int servoPin = 6;
const int servo2 = 7;
long duration;
int distance;

Servo myservo;
Servo myservo2;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  myservo2.attach(servo2);
  Serial.begin(9600);
}

void loop() {
  // send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);

  // move servo if distance within range
  if (distance >= 20 && distance <= 40) {
    myservo.write(90); // move servo to 90 degrees
  } else {
    myservo.write(0); // move servo to 0 degrees
  }
  if (distance >= 40 && distance <= 60) {
    myservo2.write(90); // move servo to 90 degrees
  } else {
    myservo2.write(0); // move servo to 0 degrees
  }
  
  delay(100); // wait for 100 milliseconds before next measurement
}
