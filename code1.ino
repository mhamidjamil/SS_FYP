#include <SoftwareSerial.h>
#include <stdio.h>

SoftwareSerial XBee(2, 3); // RX, TX
int forword = 6;
int back = 7;
int left = 8;
int right = 9;
void setup()
{
    Serial.begin(9600);
    
    XBee.begin(9600);
    Serial.println("Starting XBee Comunication");
    pinMode(forword, OUTPUT);
    pinMode(back, OUTPUT);
    pinMode(left, OUTPUT);
    pinMode(right, OUTPUT);
}
void loop()
{
    if (XBee.available())
    { // If data comes in from XBee, send it out to serial monitor

        char DO, buf[100], cmd[5];
        DO = XBee.read();
        int i = 0;
        if (DO == 'r' || DO == 'R')
        {
            i = 0;
            Serial.println(""); // uncomment to print floating point result
            // Serial.println("*Received: " + String(cmd) + "*");
        }
        else if ((DO >= 'a' && DO <= 'z') || (DO >= 'A' && DO <= 'Z'))
        {
            // cmd[] += DO;
            // i++;
        }
            // DO_float = atof((char *)buf);

        Serial.print(DO);
    }
}