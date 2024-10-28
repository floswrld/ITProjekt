#include "a7.h"

void compareAESPerformance7(AES128 *aes128, AES192 *aes192, AES256 *aes256, size_t counter){

    unsigned long start;
    byte plaintext[16];
    byte key[32];
    byte encryptBuffer[16];
    byte decryptBuffer[16];

    unsigned long aes128Time= 0;
    unsigned long aes192Time= 0;
    unsigned long aes256Time= 0;

    for(size_t i = 0; i < counter; ++i){

        fillRandomBytes(plaintext, sizeof(plaintext));
        fillRandomBytes(key,  sizeof(key));
        aes128->setKey(key, aes128->keySize());
        aes192->setKey(key, aes192->keySize());
        aes256->setKey(key, aes256->keySize());

        start = micros();
        aes128->encryptBlock(encryptBuffer, plaintext);
        aes128->decryptBlock(decryptBuffer, encryptBuffer);
        aes128Time += micros() - start;

        start = micros();
        aes192->encryptBlock(encryptBuffer, plaintext);
        aes192->decryptBlock(decryptBuffer, encryptBuffer);
        aes192Time += micros() - start;

        start = micros();
        aes256->encryptBlock(encryptBuffer, plaintext);
        aes256->decryptBlock(decryptBuffer, encryptBuffer);
        aes256Time += micros() - start;

        yield();

    }

    Serial.println("AES128," + String(aes128Time/counter));
    Serial.println("AES192," + String(aes192Time/counter));
    Serial.println("AES256," + String(aes256Time/counter));

    

}