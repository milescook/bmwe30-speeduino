# Speeduino troubleshooting

Sometimes you can't connect to Speeduino, and it's required to use SpeedyLoader to re-upload the Arduino firmware. No idea why. And the Mac seems picky about which USB cable to use - only Apple worked for me.

Update: Turns out using a newer USB cable *really* helps!

# Motronic 1.3 harness <-> Speeduino pin assignment 
See [motronic-speeduino-map.md](motronic-speeduino-map.md)

# Amazing Motronic 1.3 walkthrough
https://forums.pelicanparts.com/bmw-5-series-e28-e34-e39-e60-f10-gt/534490-motronic-1-1-1-3-details.html

# Speeduino pins - ON HOLD (using a stock Motronic harness for now to reduce risk)
See [speeduino-pins.md](speeduino-pins.md)

# New ECU Loom wiring - ON HOLD (using a stock Motronic harness for now to reduce risk)
See [ecu-pinout.md](new-harness-plans/ecu-pinout.md)

# Good resource
See https://github.com/EFI-Customs/Motronic-1.3-Speeduino-Compatible-Project?tab=readme-ov-file

# Shopping list
## ECU Wiring
* 40pin connector ribbon - https://thepihut.com/products/raspberry-pi-40-pin-gpio-socket-connector-to-labelled-pins-female-150mm
* Standard ecu connectors - [https://www.ebay.co.uk/itm/296055475113?var=594188052033](https://www.ebay.co.uk/itm/296055475113?var=594188052033)

## Sensors
See https://wiki.speeduino.com/en/wiring/system
* Wideband lambda controller and sensor - https://diy-efi.co.uk/product/14point7-spartan2-wideband
* Variable TPS from an E36 plus printed adapter plate
* IAT - https://diy-efi.co.uk/product/m12-iat-sensor
* Coolant temp sensor - will use existing blue sender
* Idle control valve -Will use existing ICV

Stuff
https://www.r3vlimited.com/board/forum/e30-technical-forums/engine-drivetrain/m42/366658-megasquirt-pinout-to-stock-ecu

# TPS Wiring

From https://www.r3vlimited.com/board/forum/e30-technical-forums/general-technical/9909959-tps-wiring

E36 TPS, pin 1 is ground, 2 is signal, and 3 is vref
E30 TPS, pin 1 is closed, 2 is ground, and 3 is open
Swap pins 1 & 2 on the E30 connector

E36 Stock wiring/TPS
1 = BRN(43) - Gnd
2 = BR/SW(12) - sig
3 = RT/GE(59) - vref

E30 Stock wiring/TPS
1 = BR/BU(52) - Closed
2 = BR(-) - Gnd
3 = BR/BK(53) - WOT

Running M5x TPS on E30 harness
1 = BR Gnd - Gnd
2 = BR/BU(52) - Sig
3 = BR/BK(53) - vRef

