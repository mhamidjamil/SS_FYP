#include <SoftwareSerial.h>

int pin1 = 6;
int pin2 = 7;
int pin3 = 8;
int pin4 = 9;

int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;

int valup = 0;
int speed =0;

void setup() {

  Serial.begin(9600);
  Serial.println("Starting XBee Comunication");
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  speed = 200;
}


void loop() {
  char tmp = Serial.read();

  if (tmp == 'f') {
    while (tmp != 's') {
      if (valup <= speed) {
        analogWrite(pin1, val1);
        analogWrite(pin2, val2);
        analogWrite(pin3, val3);
        analogWrite(pin4, val4);
        val1++;
        val4++;
        valup++;
      //  Serial.print(valup);
          Serial.print(val1);
        Serial.print("\n");
      //  delay(100);
      }
      tmp = Serial.read();
    }
    while (valup != 0) {
      analogWrite(pin1, val1);
      analogWrite(pin2, val2);
      analogWrite(pin3, val3);
      analogWrite(pin4, val4);
      val1--;
      val4--;
      --valup;
      //delay(100);
      Serial.print(val1);
      Serial.print("\n");
    }
  }



 else if (tmp == 's') {


    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
    analogWrite(pin4, 0);
    
  
  Serial.print(tmp);


} else if (tmp == 'l') {


  while(valup <= 100) {
    analogWrite(pin1, val1);
    analogWrite(pin2, val2);
    analogWrite(pin3, val3);
    analogWrite(pin4, val4);
    val1++;
    val3++;
    valup++;

          //  Serial.print(valup);
        Serial.print(val1);
        Serial.print("\n");
      //  delay(100);
  }
  delay(100);

    //tmp = Serial.read();
    

    while (valup != 0) {
      analogWrite(pin1, val1);
      analogWrite(pin2, val2);
      analogWrite(pin3, val3);
      analogWrite(pin4, val4);
      val1--;
      val3--;
      --valup;
      //delay(100);
      Serial.print(val1);
      Serial.print("\n");
    }
} else if (tmp == 'r') {
 while(valup <= 100) {
    analogWrite(pin1, val1);
    analogWrite(pin2, val2);
    analogWrite(pin3, val3);
    analogWrite(pin4, val4);
    val2++;
    val4++;
    valup++;

          //  Serial.print(valup);
        Serial.print(val2);
        Serial.print("\n");
      //  delay(100);
  }
  delay(100);

    tmp = Serial.read();
    

    while (valup != 0) {
      analogWrite(pin1, val1);
      analogWrite(pin2, val2);
      analogWrite(pin3, val3);
      analogWrite(pin4, val4);
      val2--;
      val4--;
      --valup;
      //delay(100);
      Serial.print(val2);
      Serial.print("\n");
    }

} else if (tmp == 'b') {

while (tmp != 's') {

  if (valup <= speed) {
    analogWrite(pin1, val1);
    analogWrite(pin2, val2);
    analogWrite(pin3, val3);
    analogWrite(pin4, val4);
    val2++;
    val3++;
    valup++;

          //  Serial.print(valup);
          Serial.print(val2);
        Serial.print("\n");
      //  delay(100);
  }
 

    tmp = Serial.read();
    }

    while (valup != 0) {
      analogWrite(pin1, val1);
      analogWrite(pin2, val2);
      analogWrite(pin3, val3);
      analogWrite(pin4, val4);
      val2--;
      val3--;
      --valup;
      //delay(100);
      Serial.print(val2);
      Serial.print("\n");
    }

    
} else if (tmp == '[') {

  speed =127;
  Serial.print("speedLow");

} else if (tmp == ']') {

  speed = 200;

  Serial.print("speedUp");

}

}
