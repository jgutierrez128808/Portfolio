/*
 * Sony STR-DH130 IR Remote
 * Hardware: Arduino Nano + IR LED (pin 3) + 3 momentary buttons
 *
 * Wiring:
 *   IR LED anode → 100Ω resistor → pin 3 → IR LED cathode → GND
 *   Each button: one leg to GND, other leg to button pin below
 *   (INPUT_PULLUP means no external resistor needed)
 *
 * Protocol: Sony SIRC, 20-bit
 * Codes sourced from Sony SIRC AV amplifier spec (device address 0x030).
 * If a button doesn't work, capture your remote's codes — see README.md.
 */

#include <Arduino.h>
#include <IRremote.hpp>

// IR LED must be on a PWM-capable pin. Pin 3 is IRremote's default on Nano.
#define IR_SEND_PIN     3

// Button pins — wire each button between the pin and GND
#define BTN_POWER       7
#define BTN_VOL_UP      8
#define BTN_VOL_DOWN    9

// Sony SIRC 20-bit codes for AV amplifier class (STR-DH130 / RM-AAU130)
// Address is a 13-bit combined value (5-bit device + 8-bit extended)
#define SONY_ADDR       0x030
#define CMD_POWER       0x015
#define CMD_VOLUME_UP   0x012
#define CMD_VOLUME_DOWN 0x013

// Sony SIRC spec requires the same burst sent 3× minimum.
// IRremote counts repeats *after* the first send, so 2 = 3 total.
#define SONY_REPEATS    2

void sendSonyCmd(uint16_t addr, uint8_t cmd) {
    IrSender.sendSony(addr, cmd, SONY_REPEATS, SIRCS_20_BITS);
}

void setup() {
    IrSender.begin(IR_SEND_PIN);

    pinMode(BTN_POWER,    INPUT_PULLUP);
    pinMode(BTN_VOL_UP,   INPUT_PULLUP);
    pinMode(BTN_VOL_DOWN, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(BTN_POWER) == LOW) {
        sendSonyCmd(SONY_ADDR, CMD_POWER);
        delay(400);  // long gap — prevents double-toggle on a single press
    }

    if (digitalRead(BTN_VOL_UP) == LOW) {
        sendSonyCmd(SONY_ADDR, CMD_VOLUME_UP);
        delay(130);  // short gap so it repeats smoothly while held
    }

    if (digitalRead(BTN_VOL_DOWN) == LOW) {
        sendSonyCmd(SONY_ADDR, CMD_VOLUME_DOWN);
        delay(130);
    }
}
