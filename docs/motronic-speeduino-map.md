# How to map standard Motronic 1.3 harness to Speeduino pins (Work in progress)

Status: This is the active wiring map for the current running setup.

WARNING: This is my wiring map, and WILL NOT work for you without harness modification. I'm re-purposing some of the ECU pins for a start, and changing the injector sub loom completely (from 2 batched to 6 individual but running as 3 pairs). I'm trying to use as much of the ECU connector as possible without changing the wiring where I can. For ignition timing I'll need a new loom anyway, as M20s used a single ignition coil and distributor running off the cam. I'll keep this initially for simplicity.

See https://wiki.speeduino.com/en/boards/V04 for Speeduino pins.


For the Motronic pins see  https://www.e30zone.net/e30wiki/index.php?title=ECU_Pinouts#Motronic_1.3


For comparison, see the megasquirt map here for the Megasquirt map see https://www.e30zone.net/e30wiki/index.php?title=Megasquirting_Your_M20


# Pin assignments

Note: Some mappings here differ from `speeduino-pins.md` and `new-harness-plans/ecu-pinout.md` because those files describe on-hold custom harness plans.

So you see here the map for my Motronic 1.3 harness ECU pin, to Speeduino pin, followed lastly by IDC pin. IDC is the dupont ribbon connector https://thepihut.com/products/raspberry-pi-40-pin-gpio-socket-connector-to-labelled-pins-female-150mm I have going to the Speeduino which handily labels all its wires. Took me a while to realise that the numbers labelled have no correlation to the Speeduino pins... ah well. I did make a handy map [idc-numberedpins.md](idc-numberedpins.md)

- Motronic pin  - Description - Speeduino Pin - Speeduino description - {Purpose} - IDC Pin
- 1 - Ignition Coil Output (Channel 1 - 1.1) - 7 | Ignition 1 | 28
- 2 - Ground - N/A - ECU Power relay ground, pin 30
- 3 - Fuel Pump Relay Control - 38 - Boost control (swap from 16 fuel pump as I have no ULN chip) - 35
- 4 - Idle out - 37 - PWM Idle - 33
- 5 - NA
- 6 - Tachometer output - N/A (Arduino pin 0) - ~~Speeduino USB Serial data TX (via dash plug) C1 plug pin 7 (Pi RX)~~
- 7 - AFM input pin 2 - 19 - Coolant (CLT) - 4
- 10 - Oxygen sensor (ground) - 10 - Ground - 22
- 14 - Injector gnd (???) - 12 - Ground - 18
- 16 - Injectors 1,3,5 - 2 - Injector 2 Pin 1/2 - Injector 2 - 38
- 16 - Injectors 1,3,5 - 39 - Injector 2 Pin 2/2 - Injector 5 - 37
- 17 - Injectors 2,4,6 - 3 - Injector 3 Pin 1/2 - Injector 3 - 36
- 17 - Injectors 2,4,6 - 4 - Injector 3 Pin 2/2 - Injector 4 - 34
- 19 - Main ground - ECU Power relay 85 & Speeduino power -ve
- 22 - Idle out - 36 - PWM Idle 2 - 31
- 24 - Ground - 23 - Ground - 5
- 26 - AFM Common ground - 9 - Ground - IAT  / CLT Ground / TPS gnd - 24
- 27 - Start input- to ignition switch and coil - N/A - ECU Power relay pin 86
- 28 - O2 input - 21 - O2 Sensor - 1
- 32 - Econometer - N/A (14 (Proto Area 1) - fuel level (via dash plug) C1 plug pin 11 - N/A
- 36 - Main relay output - N/A - ECU Power relay pin 87
- 37 - Switched power from main relay - NA - Speeduino power +ve in - NA
- 44 - AFM air inlet temp pin 1 - 20 - Inlet Air Temp (IAT) - 2
- 45 - Coolant Temp input - 1 - Injector 1 Pin 1/2 - Injector 1 - 40
- 45 - Coolant Temp input - 40 - Injector 1 Pin 2/2 - Injector 6 - 39
- 47 - CPS Signal - 25 - Crank Input / VR1+ - 9
- 48 - CPS gnd - 27 VR1- - 13
- 52 - Closed throttle - 22 - TPS Input - 3
- 53 - WOT Input - 13 - 5V (TPS Live) - 16


# Other Motronic pins

- 18 - Constant 12V from Battery - 12v positive (temporary power but will become unused)
- 19 - Main ground - 12v negative
- 27 - Start input - Goes to the main power relay in the new ECU case
- 36 - Main relay ground
- 37 - Speeduino power




# Harness side to o2 side
- Green to white
- Brown to white
- black to gray
- yellow to black



# FOR REFERENCE: Original injector subloom wiring C191 plug

- C191 plug pin no | ECU Pin | description
- 1 - 45 - Coolant Temperature Sensor
- 2 - NA - Coolant Temperature Sensor
- 3 - NA - Coolant Temperature Sensor
- 4 - NA - Coolant Temperature Sensor
- 5 - NA - DME relay (live for Fuel Injectors)
- 6 - 16 - Fuel Injectors 1, 3, 5
- 7 - 17 - Fuel Injectors 2, 4, 6


