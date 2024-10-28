#ifndef A8_H
#define A8_H

#include <Crypto.h>
#include <AES.h>
#include <CTR.h>
#include <EAX.h>
#include <GCM.h>
#include <XTS.h>
#include "tool.h"

String* testPerformance8(size_t counter, size_t plaintextSize);
void prepareCiphers();


#endif