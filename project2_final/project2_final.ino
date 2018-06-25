/*
 * Name: Gusti Scarlett Halima
 * Date: 23rd October 2017
 * class: Engr 102
 * Software version: Arduino 1.8.2
 * What it does: The circuit has an RGB LED that can change color based on the temperature
 * from a thermistor and have a blink rate based on the heartrate sensor.
 */

#include <Math.h>

//Setting constants for pins
const int temperaturePin = A0;
const int heartRatePin = A3;

/*
 * The RGB LED only uses the red and green LED
 * therefore we don't need to connect the blue LED
 */
const int RED_PIN = 11;
const int GREEN_PIN = 10;

void setup() {
  Serial.begin(9600);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

}

void loop() {
 
  /*
   * Variable 'getValue' will read the raw value from the analog pin.
   * To see the change in temperature, the red and green LED values will 
   * balance out each other by taking the tenths place from 'getValue'.
   * Red LED will have an initial value of 300 while the Green LED is 0.
   * While the tenths place will subtract the Red LED value, it will add the 
   * Green LED value.
  */
  int getValue = analogRead(temperaturePin);
  int subtract = getValue % 100;
  int red = 300 - subtract;
  int green = subtract;

  /*
   * variable 'heartRate' will receive its raw value from the heart rate sensor
   */
   int heartRate = analogRead(heartRatePin);

   /*
    * The following code will read the values in the serial print
    */
    Serial.print("Raw temperature sensor value: ");
    Serial.println(getValue);
    Serial.print("Red LED value: ");
    Serial.println(red);
    Serial.print("Green LED value: ");
    Serial.println(green);
    Serial.print("Raw heart rate sensor value: ");
    Serial.println(heartRate);

    /*
     * The values of red, green, and heartRate are passed in the 
     * following method to display the color and blink rate
     */
     colorAndBlink(red, green, heartRate);
}

/*
 * Method colorAndBlink displays a single loop of the LEDs being turned
 * on then off with the heartRate value as the delay
 */
void colorAndBlink(int r, int g, int hR) {
  setColor(r, g);
  delay(hR);
  setColor(0, 0);
  delay(hR);
}

  /*
   * Method setColor sets the color of the LED 
   */
void setColor(int r, int g) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
}
   
