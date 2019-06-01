#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>


// LCD connected to A4, A5, GND, 5V
// Acelerometer connected to A0, A1, GND, 5V



const int analogInPin1 = A0; // A0. Analog input pin that the Accelerometer's first pin is attached to
const int analogInPin2 = A1; // A1. Analog input pin that the Accelerometer's second pin is attached to
int sensorValue1 = 0; // value read from the Accelerometer's first pin
int sensorValue2 = 0; // value read from the Accelerometer's second pin
int outputValue1 = 0;
int outputValue2 = 0;

byte LCD_I2C_ADDRESS = 0x27;


// 
LiquidCrystal_I2C             lcd(LCD_I2C_ADDRESS, 2, 1, 0, 4, 5, 6, 7);


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(57600);
  lcd.begin (16, 2);   // Inicializar el display con 16 caraceres 2 lineas
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
}
void loop() {
  // read the both analog in values:
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  // map it to the range of the analog out:
  //outputValue1 = map(sensorValue1, 0, 1023, 0, 255);
  //outputValue2 = map(sensorValue2, 0, 1023, 0, 255);

  // print the results to the serial monitor:
  /*
    Serial.write(sensorValue1);
    Serial.write(sensorValue2);

    Serial.print(sensorValue1);
    Serial.print("\n");
    Serial.print(sensorValue2);
    Serial.print("\n");
  */
  lcd.clear();
  lcd.home();                   // go home
  lcd.print(sensorValue1);
  lcd.setCursor ( 0, 1 );        // go to the 2nd line
  lcd.print(sensorValue2);


  // wait 10 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(10);
}
