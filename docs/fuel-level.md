# Fuel level via Speeduino analog input

The fuel sender feeds directly into Speeduino pin 14 (Proto Area 1, Arduino `A6`). TunerStudio reads it natively and TS Dash can display it as a gauge — no separate microcontroller needed.

## Sender range - readings at the gauge

- `0 ohms` = full
- `60 ohms` = empty

BMW use a 68 ohm resistor in the cluster, so 128 ohms was empty.
After filling with 15L it read 98 ohms (then ran the engine 10 mins and read 106 — remember the swirl pot would have taken 1 litre).

Maybe 20 ohms per 15L? I do have dents in my tank.

## Wiring

- Fuel sender one side - White plug pin 4 -> Speeduino pin `14` (Proto Area 1)
- Fuel sender other side -> ground
- `330 ohm` resistor from Speeduino `5V` to pin `14`
- `100 nF` capacitor from pin `14` to ground

## Why this works

The sender is a variable resistor. The 330 ohm resistor forms a voltage divider with it, producing 0–0.77V at pin 14 as the tank goes from full to empty. The 100 nF capacitor filters noise before the ADC samples. Speeduino reads this as a standard analog input and TunerStudio exposes it as a loggable channel.

## TunerStudio setup

1. In TunerStudio go to *Tools → Calibrate Analog Inputs*
2. Assign pin 14 (A6) as a generic analog channel (e.g. "Fuel Level")
3. Set the calibration curve: measure the raw ADC value with a known-full and known-empty tank and enter those as the endpoints
4. Add a gauge in TS Dash pointing at that channel

## Calibration

With the 5V reference and 330 ohm divider, expected ADC range:

- Full (0 ohm sender): ~0
- Empty (60 ohm sender): ~157

Measure the actual values at known fuel levels and use those for the calibration curve in TunerStudio.
