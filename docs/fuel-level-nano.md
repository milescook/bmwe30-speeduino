# Fuel level with Arduino Nano

This is the simplest way to get the E30 fuel sender into TS Dash without spending a Speeduino analog input.

## Sender range

- `0 ohms` = full
- `60 ohms` = empty

## Wiring

Use the Nano as the analog reader and send the value to the Pi over USB serial.

- Fuel sender one side -> Nano `A0`
- Fuel sender other side -> ground
- `330 ohm` resistor from Nano `5V` to `A0`
- `100 nF` capacitor from `A0` to ground
- Nano USB -> Pi USB

## Why this works

The sender is a variable resistor, so the Nano reads a voltage divider and converts it to a number. The Pi does not read the sender directly; it reads the Nano over serial.

## Suggested serial format

The sketch in `../arduino/fuel-level-nano/fuel-level-nano.ino` prints:

- `fuel_raw=<adc-count> fuel_pct=<0-100>`

## Pi-side bridge

The helper script in `../tools/fuel_level_bridge.py` reads the Nano serial output and prints JSON lines like:

```json
{"fuel_raw": 412, "fuel_pct": 63}
```

That is easy to consume from a Pi-side dashboard process, a small Node script, or any other bridge you want to build around TS Dash.

## Example pipeline

```bash
python3 tools/fuel_level_bridge.py /dev/ttyUSB0 | python3 tools/fuel_level_gauge_example.py
```

That prints lines like `fuel_level_pct=63`, which is easy to adapt into a gauge, file watcher, or dashboard variable.

## Calibration

Measure the raw ADC value at full and empty, then update the constants in the sketch.
