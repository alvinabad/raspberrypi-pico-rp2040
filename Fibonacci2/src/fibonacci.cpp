#include <Arduino.h>
#include <SPI.h>
#include <limits.h>
#include "common.h"

void runFibonacci() {
    Serial.println("Begin Fibonacci Benchmark.");
    Serial.println(INT_MAX);
    Serial.println(UINT_MAX);
    Serial.println(LONG_MIN);
    Serial.println(LONG_MAX);

    unsigned long start, i, F;
    double diff;
    char buf[MAXLEN+1];

    start = millis();

    for (i=0; i <= MAXSIZE; i++) {
        F = fib(i);
        diff = (double) (millis() - start);
        diff /= 1000.0;

        snprintf(buf, MAXLEN, "Fib(%2ld) = %-10ld, %f sec", i, F, diff);
        Serial.println(buf);

        if (i < 36)
            continue;

        if (i%2 == 0) {
            if (blinkOnboardLED_handle != NULL) {
                vTaskSuspend(blinkOnboardLED_handle);
                Serial.println("Stop blinking.");
            }
        } else {
            if (blinkOnboardLED_handle != NULL) {
                vTaskResume(blinkOnboardLED_handle);
                Serial.println("Resume blinking.");
            }
        }
    }
}

unsigned long fib(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

unsigned long cache[MAXSIZE];

unsigned long fib2(unsigned int n) {
    if (n == 0) {
        cache[n] = n;
    } else if (n == 1) {
        cache[n] = n;
    } else if (cache[n-1] != 0) {
        cache[n] = cache[n-1] + cache[n-2];
    }
    return cache[n];
}
