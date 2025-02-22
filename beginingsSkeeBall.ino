#include "LedControl.h"

LedControl lc=LedControl(12,11,10,1);

unsigned long gotOne = 500;
unsigned long updated;
int score = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  Serial.println("Score!");
  Serial.println(score);

  lc.shutdown(0,false);
  lc.setIntensity(0,2);
  lc.clearDisplay(0);
  lc.setDigit(0, 0, 0, false);
  lc.setDigit(0, 1, 0, false);
  lc.setDigit(0, 2, 0, false);
}

void displayNumber(int num) {
    // Extract individual digits
    int hundreds = (num / 100) % 10;
    int tens = (num / 10) % 10;
    int ones = num % 10;

    // Update each digit on the display
    lc.setDigit(0, 0, hundreds, false);  // Hundreds place
    lc.setDigit(0, 1, tens, false);      // Tens place
    lc.setDigit(0, 2, ones, false);      // Ones place
}

void loop() {
  if ((digitalRead(2) == LOW) && (millis() > gotOne + 500)) {
    gotOne = millis();
    score += 50;
    Serial.println(score);
    displayNumber(score);
  }

}
