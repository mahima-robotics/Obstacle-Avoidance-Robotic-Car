// Ultrasonic sensor pins
#define trigPin 9
#define echoPin 8

// Motor driver pins
#define ENA 3
#define ENB 11
#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7

long duration, distance;
int motorSpeed = 100;   // Speed (0 - 255)

void setup()
{
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

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

  if (distance > 30)
  {

    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
  }

  else if (distance <= 30 && distance > 0)
  {
    // Stop
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, LOW);

    delay(200);

    // Move backward
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN1, LOW);

    delay(500);

    // Stop
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, LOW);

    delay(200);

    // Turn Left
    digitalWrite(IN4, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, LOW);

    delay(500);
  }
}