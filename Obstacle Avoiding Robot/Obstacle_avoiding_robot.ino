#include <Servo.h>

Servo Myservo;

// Ultrasonic sensor pins
#define trigPin 9
#define echoPin 8

// Motor driver pins
#define ENA 3
#define ENB 11
#define MLa 4
#define MLb 5
#define MRa 6
#define MRb 7

long duration, distance;
int motorSpeed = 100;   // Speed (0 - 255)

void setup()
{
  Serial.begin(9600);

  pinMode(MLa, OUTPUT);
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Myservo.attach(10);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}

void loop()
{
  // Measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  Serial.println(distance);
  delay(10);

  if (distance > 20)
  {
    // Move Forward
    Myservo.write(90);

    digitalWrite(MRb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, HIGH);
  }

  else if (distance <= 20 && distance > 0)
  {
    // Stop
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);

    delay(200);

    // Scan left
    Myservo.write(0);
    delay(500);

    // Scan right
    Myservo.write(180);
    delay(500);

    // Center
    Myservo.write(90);
    delay(500);

    // Move backward
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);
    digitalWrite(MLa, LOW);

    delay(500);

    // Stop
    digitalWrite(MRb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MLa, LOW);

    delay(200);

    // Turn Left
    digitalWrite(MRb, HIGH);
    digitalWrite(MRa, LOW);
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);

    delay(500);
  }
}