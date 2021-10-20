/*******************************************************************************
 *
 * Compute for Pi using Raspberry Pi Pico Microcontroller
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

#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"

int main() {
    int i = 0;
    long double n, pi, realpi;

    const uint led = PICO_DEFAULT_LED_PIN;

    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);

    stdio_init_all();

    // get pi using arctangent2 function
    realpi = (16.0 * atan2(1, 5)) - (4.0 * atan2(1, 239));

    n = 1.0;
    pi = 0;

    while (pi < realpi) {
        /* for debugging
        gpio_put(led, 1);
        sleep_ms(20);
        gpio_put(led, 0);
        sleep_ms(20);
        */

        pi = pi + (4.0/n);
        n += 2.0;
        pi = pi - (4.0/n);
        n += 2.0;

        printf("Real Pi: %lf, Pi: %lf\n", realpi, pi);
    }
    printf("ALL DONE.\n");

    return 0;
}
