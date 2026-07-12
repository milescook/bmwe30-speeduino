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
