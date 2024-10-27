#include "a6.h"



void compareAESPerformance6(AES128 *aes128, AES192 *aes192, AES256 *aes256, size_t counter){

    unsigned long start;
    byte plaintext[16];
    byte key[32];
    byte encryptBuffer[16];
    byte decryptBuffer[16];

    
    fillRandomBytes(key,  sizeof(key));
    aes128->setKey(key, aes128->keySize());
    aes192->setKey(key, aes192->keySize());
    aes256->setKey(key, aes256->keySize());

    for(size_t i = 0; i < counter; i++){

        fillRandomBytes(plaintext,  sizeof(plaintext));
        
        start = micros();
        aes128->encryptBlock(encryptBuffer, plaintext);
        Serial.println(micros() - start);

        start = micros();
        aes128->decryptBlock(decryptBuffer, encryptBuffer);
        Serial.println(micros() - start);

        start = micros();
        aes192->encryptBlock(encryptBuffer, plaintext);
        Serial.println(micros() - start);

        start = micros();
        aes192->decryptBlock(decryptBuffer, encryptBuffer);
        Serial.println(micros() - start);

        start = micros();
        aes256->encryptBlock(encryptBuffer, plaintext);
        Serial.println(micros() - start);

        start = micros();
        aes256->decryptBlock(decryptBuffer, encryptBuffer);
        Serial.println(micros() - start);

        yield();

    }

    

}
