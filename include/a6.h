#ifndef A6_H
#define A6_h

#include <Crypto.h>
#include <AES.h>
#include "tool.h"


void compareAESPerformance6(AES128 *aes128, AES192 *aes192, AES256 *aes256, size_t counter);

#endif