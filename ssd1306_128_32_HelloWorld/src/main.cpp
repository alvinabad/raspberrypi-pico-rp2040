/*******************************************************************************
 *
 * Display Text on ssd1306 128x64 i2c OLED
 *
 ******************************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4
#define SCREEN_ADDRESS 0x3C

#define MAX_MSG_LEN    20
#define MAX_ROW        2

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void write_to_display(const char *);

void setup() {
    Serial.begin(115200);
    pinMode(LED_BUILTIN, OUTPUT);

    delay(2000);

    Serial.println("START Setup");

    // uncomment for serial debugging
    //while (!Serial);

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }

    // Clear buffer
    display.display();
    display.clearDisplay();

    Serial.println("END Setup");
}

void write_to_display(const char *msg) {
    display.clearDisplay();
    display.display();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0);

    display.println(F(msg));
    display.println(msg);
    display.display();

    Serial.println(msg);

/***
    //for (size_t i=0; i<strlen(msg); i++) {
        //display.printf("%c", F(msg[i]));
        delay(200);
    }
***/


    // display for 2.5s minimum until the next one
    delay(2500);
}

void loop() {
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);

    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);

    const char *msg;
 
    //    "12345678901234567890"
    msg = "Hello,    World!    ";
    write_to_display(msg);
}
