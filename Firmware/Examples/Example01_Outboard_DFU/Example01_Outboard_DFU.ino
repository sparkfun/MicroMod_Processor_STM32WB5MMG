/**
 * @file Example01_Outboard_DFU.ino
 * @brief This example performs an Outboard Device Firmware Update.
 * @copyright SPDX-License-Identifier: MIT
 * @author Alex Brudner, SparkFun Electronics
 * @date 2023-04-13
 * @note Based on the DFU example from Blues Wireless. See
 * https://github.com/blues/note-outboard-dfu
 * 
 * ========== HARDWARE CONNECTIONS ==========
 * MicroMod STM32WB5MMG Processor Board => MicroMod Main Board => MicroMod 
 *  Function Board Blues Wireless Notecarrier
 *
 * Feel like supporting open source hardware?
 * Buy a board from SparkFun!
 *      MicroMod Function Board Blues Wireless Notecarrier  
 *        | https://www.sparkfun.com/products/20409
 *      MicroMod STM32WB5MMG Processor Board
 *        | https://www.sparkfun.com/products/21438
 *      MicroMod Main Board - Double                        
 *        | https://www.sparkfun.com/products/18575
 */

#include <Arduino.h>
#include <Notecard.h>

#define PRODUCT_UID "com.your-company.your-name:your_product"

int ledPin = LED_BUILTIN;

Notecard notecard;

void setup()
{
    pinMode(ledPin, OUTPUT);
    
    /* Begin Serial communications */
    Serial.begin(115200);
    Serial.println(F("Begin - STM32WB5MMG MicroMod Notecarrier Example 01: Outboard DFU"));
    notecard.setDebugOutputStream(Serial);

    /* Begin Serial communications */
    Wire.begin();
    notecard.begin();

    /* Configure Notecard */
    J *req = notecard.newRequest("hub.set");
    JAddStringToObject(req, "product", PRODUCT_UID);
    JAddStringToObject(req, "mode", "continuous");
    JAddStringToObject(req, "sn", "stm32wb5mmg-micromod-v01-SN0001");
    notecard.sendRequest(req);

    /* Configure DFU settings */
    req = notecard.newRequest("card.dfu");
    JAddStringToObject(req, "name", "stm32-bi"); /* bi == boot inversion */
    JAddBoolToObject(req, "on", true);
    notecard.sendRequest(req);
}

void loop()
{
    /* Fast Blink LED while waiting for DFU. */
    Serial.println("Hello, world!");
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(400);
}
