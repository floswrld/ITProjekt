#include <Arduino.h>
#include "tool.h"
#include "a6.h"
#include "a7.h"
#include "a8.h"

AES128 aes128;
AES192 aes192;
AES256 aes256;

String ctr128Time = "CTR128,";
String ctr192Time = "CTR192,";
String ctr256Time = "CTR256,";
String eax128Time = "EAX128,";
String eax192Time = "EAX192,";
String eax256Time = "EAX256,";
String gcm128Time = "GCM128,";
String gcm192Time = "GCM192,";
String gcm256Time = "GCM256,";
String xts128Time = "XTS128,";
String xts192Time = "XTS192,";
String xts256Time = "XTS256,";

size_t dataSize = 5;

void setup() {
  
  Serial.begin(9600);
  delay(1000);
  Serial.println("ZAI ZAI ZAI");
  compareAESPerformance6(&aes128, &aes192, &aes256, 100);
  compareAESPerformance7(&aes128, &aes192, &aes256, 100);
  
  String* array = testPerformance8(100, 16);
  ctr128Time+=array[0];
  ctr128Time+=",";
  ctr192Time+=array[1];
  ctr192Time+=",";
  ctr256Time+=array[2];
  ctr256Time+=",";
  eax128Time+=array[3];
  eax128Time+=",";
  eax192Time+=array[4];
  eax192Time+=",";
  eax256Time+=array[5];
  eax256Time+=",";
  gcm128Time+=array[6];
  gcm128Time+=",";
  gcm192Time+=array[7];
  gcm192Time+=",";
  gcm256Time+=array[8];
  gcm256Time+=",";
  xts128Time+=array[9];
  xts128Time+=",";
  xts192Time+=array[10];
  xts192Time+=",";
  xts256Time+=array[11];
  xts256Time+=",";

  array = testPerformance8(100, 1024);
  ctr128Time+=array[0];
  ctr128Time+=",";
  ctr192Time+=array[1];
  ctr192Time+=",";
  ctr256Time+=array[2];
  ctr256Time+=",";
  eax128Time+=array[3];
  eax128Time+=",";
  eax192Time+=array[4];
  eax192Time+=",";
  eax256Time+=array[5];
  eax256Time+=",";
  gcm128Time+=array[6];
  gcm128Time+=",";
  gcm192Time+=array[7];
  gcm192Time+=",";
  gcm256Time+=array[8];
  gcm256Time+=",";
  xts128Time+=array[9];
  xts128Time+=",";
  xts192Time+=array[10];
  xts192Time+=",";
  xts256Time+=array[11];
  xts256Time+=",";

  Serial.println(ctr128Time);
  Serial.println(ctr192Time);
  Serial.println(ctr256Time);
  Serial.println(eax128Time);
  Serial.println(eax192Time);
  Serial.println(eax256Time);
  Serial.println(gcm128Time);
  Serial.println(gcm192Time);
  Serial.println(gcm256Time);
  Serial.println(xts128Time);
  Serial.println(xts192Time);
  Serial.println(xts256Time);


  
  

  Serial.println("end");
}

void loop() {
  // put your main code here, to run repeatedly:
}