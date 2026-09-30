# Fuel level via Speeduino analog input

The fuel sender feeds directly into IDC pin 15. TunerStudio reads it natively and TS Dash can display it as a gauge — no separate microcontroller needed.

## Sender range - readings at the gauge

- `0 ohms` = full
- `60 ohms` = empty

BMW use a 68 ohm resistor in the cluster, so 128 ohms was empty.
After filling with 15L it read 98 ohms (then ran the engine 10 mins and read 106 — remember the swirl pot would have taken 1 litre).1

Maybe 20 ohms per 15L? I do have dents in my tank.

## Wiring

- Fuel sender one side - White plug pin 4 -> Motronic 32, Arduino pin A9
- Fuel sender other side -> ground
- `1k ohm` resistor from Speeduino pin 13 (idc 16) for 5v to pin Arudino A9

Speeduino 40-Pin Harness
       +---------------------
       |                       
       | Speeduino Pin 13 IDC 16 (5V VREF)--+
       |                                    |
       |                                    |
       |                                  [1k Ω]  Pull-Up Resistor
       |                                    |
       | Pin Analog A9* --------------------| <--- (Splice Point)
       |                                    |
       | Speedunio Pin 9 IDC 24 (Sensor GND)|
       +---------------------    |          |
                                 |          |
                                 v          v Motronic 32 (Econometer)
                            [=== Fuel Sender ===]
                            (Mounted in E30 Tank)

Pin A9 -> Proto 47 -> Speeduino 15 idc 12 -> Motronic 32
## Why this works

The sender is a variable resistor. The 1km ohm resistor forms a voltage divider with it, producing 0.28–0.57V at pin 14 as the tank goes from full to empty. The 100 nF capacitor filters noise before the ADC samples. Speeduino reads this as a standard analog input and TunerStudio exposes it as a loggable channel.

## TunerStudio setup

1. In TunerStudio go to *Tools → Calibrate Analog Inputs*
2. Assign pin 15 (A9) as a generic analog channel (e.g. "Fuel Level")
3. Set the calibration curve: measure the raw ADC value with a known-full and known-empty tank and enter those as the endpoints
4. Add a gauge in TS Dash pointing at that channel

## Calibration

With the 5V reference and 330 ohm divider, expected ADC range:

- Full (0 ohm sender): ~0
- Empty (60 ohm sender): ~157

Measure the actual values at known fuel levels and use those for the calibration curve in TunerStudio.
