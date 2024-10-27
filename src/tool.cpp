#include "tool.h"

void fillRandomBytes(byte* array, size_t size) {

    for (size_t i = 0; i < size; i++) {
        array[i] = random(0, 256);  // zufälliger Wert zwischen 0 und 255
    }
    
}