#include <SoftwareSerial.h>
#include <stdio.h>
int forword = 6;
int back = 7;
int left = 8;
int right = 9;

SoftwareSerial XBee(2, 3); // RX, TX

float DO_float = 0; // used to hold a floating point number that is the D.O.

void setup()
{
    XBee.begin(9600);
    Serial.begin(9600);
    pinMode(forword, OUTPUT);
    pinMode(back, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(right, OUTPUT);
}
void turnOFF()
{
    analogWrite(forword, 0);
    analogWrite(back, 0);
    analogWrite(left, 0);
    analogWrite(right, 0);
}
void loop()
{
    if (XBee.available())
    { // If data comes in from XBee, send it out to serial monitor

        char DO, buf[100];
        DO = XBee.read();
        if (DO == 'r' || DO == 'R')
        {
            // i = 0;
            Serial.println(""); // uncomment to print floating point result
            // Serial.println("*Received: " + String(cmd) + "*");
        }
        else if (DO == 'w' || DO == 'W')
        {
            turnOFF();
            digitalWrite(forword, HIGH);
            Serial.println(DO);
        }
        else if (DO == 's' || DO == 'S')
        {
            turnOFF();
            digitalWrite(back, HIGH);
            Serial.println(DO);
        }
        else if (DO == 'd' || DO == 'D')
        {
            turnOFF();
            digitalWrite(right, HIGH);
            Serial.println(DO);
        }
        else if (DO == 'a' || DO == 'A')
        {
            turnOFF();
            digitalWrite(left, HIGH);
            Serial.println(DO);
        }
        else
        {
            turnOFF();
            Serial.print("No response assigned ");
            Serial.println(DO);
        }
        delay(50);
        turnOFF();
        DO_float = atof((char *)buf);
        // Serial.print(DO);
        // Serial.println(DO_float); //uncomment to print floating point result
    }
}