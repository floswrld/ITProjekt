#include "tool.h"

void fillRandomBytes(byte* array, size_t size) {

    for (size_t i = 0; i < size; i++) {
        array[i] = random(0, 256);  // zufälliger Wert zwischen 0 und 255
    }
    
}

float calculateMedian(size_t* array, size_t size) {

    
    byte temp[size];
    memcpy(temp, array, size);

    std::sort(temp, temp + size);

    if (size % 2 == 0) {
        return (temp[size / 2 - 1] + temp[size / 2]) / 2.0;
    } else {
        return temp[size / 2];
    }
}

void calculateStats(size_t* array, size_t size, size_t* stats) {

    if (size == 0) {
        return;
    }

    float sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += array[i];
    }
    float mean = sum / size;

    float median = calculateMedian(array, size);

    float variance = 0;
    for (size_t i = 0; i < size; i++) {
        variance += pow(array[i] - mean, 2);
    }
    variance /= size;
    float stdDev = sqrt(variance);

    stats[0] = mean;
    stats[1] = median;
    stats[2] = stdDev;

    yield();

}