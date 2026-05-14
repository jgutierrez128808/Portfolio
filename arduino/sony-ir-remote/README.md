# Sony STR-DH130 IR Remote (Arduino Nano)

IR transmitter for the Sony STR-DH130 audio receiver, using the IRremote library and a bare IR LED.

## Parts

| Part | Value / Notes |
|---|---|
| Arduino Nano | any clone works |
| IR LED | 940 nm (standard, e.g. TSAL6400) |
| Resistor | 100 Ω, in series with the LED |
| Buttons | 3× momentary SPST, NO |

## Wiring

```
Pin 3 ──── 100Ω ──── IR LED (+) ──── IR LED (−) ──── GND

Pin 7 ──── BTN_POWER   ──┐
Pin 8 ──── BTN_VOL_UP  ──┤── GND (other side of each button)
Pin 9 ──── BTN_VOL_DOWN──┘
```

No pull-up resistors needed — the sketch uses `INPUT_PULLUP`.

## Dependencies

Install via Arduino Library Manager: **IRremote** (v4.x by Armin Joachimsmeyer)

## Verifying / Replacing IR Codes

The sketch uses standard Sony SIRC 20-bit AV amplifier codes. If a button
doesn't work with your unit, capture the real codes from the original remote:

1. Wire an IR receiver module (e.g. VS1838B) — signal pin to Arduino pin 2, VCC/GND to 3.3 V or 5 V.
2. Open **File → Examples → IRremote → ReceiveDump** in the Arduino IDE.
3. Point your Sony remote at the receiver, press each button, and read the
   Serial Monitor output. You'll see something like:

   ```
   Protocol=SONY Address=0x030 Command=0x015 Raw-Data=0x... 20 bits
   ```

4. Paste those Address/Command values into the `#define` lines in `sony_ir_remote.ino`.
