#include <Arduino.h>
#include "tool.h"
#include "a6.h"
#include "a7.h"
#include "a8.h"

AES128 aes128;
AES192 aes192;
AES256 aes256;

void setup() {
  delay(1000);
  Serial.begin(9600);
  compareAESPerformance6(&aes128, &aes192, &aes256, 100);
  compareAESPerformance7(&aes128, &aes192, &aes256, 100);
  testPerformance8(100);
}

void loop() {
  // put your main code here, to run repeatedly:
}