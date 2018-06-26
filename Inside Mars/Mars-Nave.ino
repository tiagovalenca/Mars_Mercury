#include <SoftwareSerial.h>
SoftwareSerial BTSerial(10, 11); // RX, TX
char ligar;

int button1Pin = 8;
int button2Pin = 9;
int button3Pin = 10;
int switchPin = 12;

int button1State = 0;
int button2State = 0;
int button3State = 0;
int switchState = 0;

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(switchPin, INPUT);
  BTSerial.begin(38400);
  Serial.begin(9600);
}

void loop() {
  button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);


  if (button1State == HIGH) {
    Serial.print("1");
    delay(1500);
  }

  if (button2State == HIGH) {
    Serial.print("2");
    delay(1500);
  }

  if (button3State == HIGH) {
    Serial.print("3");
    delay(1500);
  }

  if (Serial.available() > 0) {
    ligar = Serial.read();
    BTSerial.write(ligar);
  }

  if (BTSerial.available() > 0) {
    if (BTSerial.read() == 'a') {
      Serial.write('4');
    }

  }
}
