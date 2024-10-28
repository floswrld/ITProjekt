#include "a8.h"

CTR<AES128> ctr128;
CTR<AES192> ctr192;
CTR<AES256> ctr256;

EAX<AES128> eax128;
EAX<AES192> eax192;
EAX<AES256> eax256;

GCM<AES128> gcm128;
GCM<AES192> gcm192;
GCM<AES256> gcm256;

XTS<AES128> xts128;
XTS<AES192> xts192;
XTS<AES256> xts256;





byte key[32];
byte encryptBuffer[16];
byte decryptBuffer[16];
byte iv[16];
byte tweak[16] = {0x00};
String strings[12];
byte plaintext[1024];

String* testPerformance8(size_t counter, size_t plaintextSize){

    unsigned long ctr128Time= 0;
    unsigned long ctr192Time= 0;
    unsigned long ctr256Time= 0;
    unsigned long eax128Time= 0;
    unsigned long eax192Time= 0;
    unsigned long eax256Time= 0;
    unsigned long gcm128Time= 0;
    unsigned long gcm192Time= 0;
    unsigned long gcm256Time= 0;
    unsigned long xts128Time= 0;
    unsigned long xts192Time= 0;
    unsigned long xts256Time= 0;

    unsigned long start;

    for (size_t i = 0; i < counter; ++i){

        fillRandomBytes(plaintext,  plaintextSize);
        prepareCiphers();

        start = micros();
        ctr128.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        ctr128.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        ctr128Time += micros() - start;
        start = micros();
        ctr192.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        ctr192.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        ctr192Time += micros() - start;
        start = micros();
        ctr256.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        ctr256.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        ctr256Time += micros() - start;

        start = micros();
        eax128.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        eax128.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        eax128Time += micros() - start;
        start = micros();
        eax192.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        eax192.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        eax192Time += micros() - start;
        start = micros();
        eax256.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        eax256.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        eax256Time += micros() - start;

        start = micros();
        gcm128.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        gcm128.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        gcm128Time += micros() - start;
        start = micros();
        gcm192.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        gcm192.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        gcm192Time += micros() - start;
        start = micros();
        gcm256.encrypt(encryptBuffer, plaintext, sizeof(plaintext));
        gcm256.decrypt(plaintext, decryptBuffer, sizeof(plaintext));
        gcm256Time += micros() - start;

        start = micros();
        xts128.encryptSector(encryptBuffer, plaintext);
        xts128.decryptSector(plaintext, decryptBuffer);
        xts128Time += micros() - start;
        start = micros();
        xts192.encryptSector(encryptBuffer, plaintext);
        xts192.decryptSector(plaintext, decryptBuffer);
        xts192Time += micros() - start;
        start = micros();
        xts256.encryptSector(encryptBuffer, plaintext);
        xts256.decryptSector(plaintext, decryptBuffer);
        xts256Time += micros() - start;

        yield();

    }

    strings[0] = String(ctr128Time/counter);
    strings[1] = String(ctr192Time/counter);
    strings[2] = String(ctr256Time/counter);
    strings[3] = String(eax128Time/counter);
    strings[4] = String(eax192Time/counter);
    strings[5] = String(eax256Time/counter);
    strings[6] = String(gcm128Time/counter);
    strings[7] = String(gcm192Time/counter);
    strings[8] = String(gcm256Time/counter);
    strings[9] = String(xts128Time/counter);
    strings[10] = String(xts192Time/counter);
    strings[11] = String(xts256Time/counter);

    return strings;

}

void prepareCiphers(){

    fillRandomBytes(key, sizeof(key));
    fillRandomBytes(iv, sizeof(iv));
    ctr128.setKey(key, ctr128.keySize());
    ctr128.setIV(iv, ctr128.ivSize());
    ctr128.setCounterSize(4);

    ctr192.setKey(key, ctr192.keySize());
    ctr192.setIV(iv, ctr192.ivSize());
    ctr192.setCounterSize(4);

    ctr256.setKey(key, ctr256.keySize());
    ctr256.setIV(iv, ctr256.ivSize());
    ctr256.setCounterSize(4);

    eax128.setKey(key, eax128.keySize());
    eax128.setIV(iv, eax128.ivSize());

    eax192.setKey(key, eax192.keySize());
    eax192.setIV(iv, eax192.ivSize());

    eax256.setKey(key, eax256.keySize());
    eax256.setIV(iv, eax256.ivSize());

    gcm128.setKey(key, gcm128.keySize());
    gcm128.setIV(iv, gcm128.ivSize());

    gcm192.setKey(key, gcm192.keySize());
    gcm192.setIV(iv, gcm192.ivSize());

    gcm256.setKey(key, gcm256.keySize());
    gcm256.setIV(iv, gcm256.ivSize());

    xts128.setSectorSize(16);
    xts128.setKey(key, xts128.keySize());
    xts128.setTweak(iv, xts128.tweakSize());

    xts192.setSectorSize(16);
    xts192.setKey(key, xts192.keySize());
    xts192.setTweak(iv, xts192.tweakSize());

    xts256.setSectorSize(16);
    xts256.setKey(key, xts256.keySize());
    xts256.setTweak(iv, xts256.tweakSize());
}