#include <Arduino.h>
#include <SPI.h>
#include "common.h"

void blinkOnboardLED(void *parameter) {
    Serial.print("Blink OnboardLED is running on Core: ");
    Serial.println(xPortGetCoreID());

    for(;;) {
        digitalWrite(LED_BUILTIN, HIGH);
        vTaskDelay(100 / portTICK_PERIOD_MS);
        digitalWrite(LED_BUILTIN, LOW);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}
