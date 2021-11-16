#define MAXLEN          1024
#define MAXSIZE         4096

#ifndef LED_BUILTIN
    #define LED_BUILTIN    2
#endif

void blinkOnboardLED(void * parameter);
unsigned long fib(unsigned int n);
unsigned long fib2(unsigned int n);
void runFibonacci();

extern TaskHandle_t blinkOnboardLED_handle;
