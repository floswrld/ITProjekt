#ifndef TOOL_H
#define TOOL_H

#include <Arduino.h>

void fillRandomBytes(byte* array, size_t size);
float calculateMedian(size_t* array, size_t size);
void calculateStats(size_t* array, size_t size, size_t* stats);

#endif