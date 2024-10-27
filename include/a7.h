#ifndef A7_H
#define A7_h

#include <Crypto.h>
#include <AES.h>
#include "tool.h"


void compareAESPerformance7(AES128 *aes128, AES192 *aes192, AES256 *aes256, size_t counter);

#endif