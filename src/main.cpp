#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <M5StickCPlus.h>

#define SERVOMIN 150  // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 600  // This is the 'maximum' pulse length count (out of 4096)
#define USMIN 600     // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 2400    // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

uint8_t pin = 26;

Adafruit_PWMServoDriver myservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to  store the servo position

void setup()
{
  M5.begin();
  myservo.begin(); // attaches the  servo on pin 26 to the servo object
  myservo.setOscillatorFrequency(27000000);
  myservo.setPWMFreq(SERVO_FREQ);
  delay(10);
}

void setServoPulse(uint8_t n, double pulse)
{
  double pulselength;

  pulselength = 1000000;     // 1,000,000 us per second
  pulselength /= SERVO_FREQ; // Analog servos run at ~60 Hz updates
  Serial.print(pulselength);
  Serial.println(" us per period");
  pulselength /= 4096; // 12 bits of resolution
  Serial.print(pulselength);
  Serial.println(" us per bit");
  pulse *= 1000000; // convert input seconds to us
  pulse /= pulselength;
  Serial.println(pulse);
  myservo.setPWM(n, 0, pulse);
}

void loop()
{

  Serial.println(pin);
  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++)
  {
    myservo.setPWM(pin, 0, pulselen);
  }

  delay(500);
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--)
  {
    myservo.setPWM(pin, 0, pulselen);
  }

  delay(500);

  // Drive each servo one at a time using writeMicroseconds(), it's not precise due to calculation rounding!
  // The writeMicroseconds() function is used to mimic the Arduino Servo library writeMicroseconds() behavior.
  for (uint16_t microsec = USMIN; microsec < USMAX; microsec++)
  {
    myservo.writeMicroseconds(pin, microsec);
  }

  delay(500);
  for (uint16_t microsec = USMAX; microsec > USMIN; microsec--)
  {
    myservo.writeMicroseconds(pin, microsec);
  }

  delay(500);


  /* for (pos = 0; pos <= 60; pos += 1)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
  }
  for (pos = 60; pos >= 0; pos -= 1)
  {                     // goes from 180 degrees to 0 degrees
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
  } */
}