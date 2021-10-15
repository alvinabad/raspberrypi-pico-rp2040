/*******************************************************************************
 *
 * Compute for Pi and display on ssd1306 128x64 i2c OLED
 *
 * MIT License
 *
 * Copyright (c) 2021 Alvin Abad
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ******************************************************************************/

/*
  Blink
*/

#include "Arduino.h"

#define DELAY           1000

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);

    Serial.println();
    Serial.print("Begin LED_BUILTIN BLINKER: ");
    Serial.println(LED_BUILTIN);

    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    Serial.print("LED_BUILTIN ON: ");
    Serial.println(LED_BUILTIN);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(DELAY);
  
    Serial.print("LED_BUILTIN OFF: ");
    Serial.println(LED_BUILTIN);

    digitalWrite(LED_BUILTIN, LOW);
    delay(DELAY);
}
