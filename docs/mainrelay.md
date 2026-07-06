# ECU Relays

We use a relay here - nothing special just one from Halfords. The reason we do this is to work with the perfectly good E30 main relay system.

![Main Relay](../images/relay.png)

The Motronic ECU when it gets power on pin 27, turns on the relay in the engine bay which in turn powers up most of the car (injectors, coil, ICV etc.). With this setup we're getting our ECU to do the same.



## How it works

When ignition is powered on (before cranking), 12v comes from Motronic pin 27. This goes to pin 86 on our relay, which in turn grounds Motronic pin 36, like the original ECU. This activates the main relay (in the engine bay). This in turn switches on power to Motronic pin 37, which is where the Speeduino live gets power from (not 27).

It may seem a bit of a roundabout way to power the Speeduino... But remember: we're powering up the car from the relay under the bonnet, and the Speeduino is simply on this main circuit. It also means if your injectors and coil have no power then neither does the Speeduino, so less potential troubleshooting headaches.

- ECU Pin - Relay pin - Destination / Description
- 27 - 86 - Ignition on 12v
- 19 - 85 - Motronic 19 (main gnd)
- 36 - 87 - Motronic pin 36 main relay trigger output (grounded via relay)
- 2 - 30 - Motronic 2 (gnd)