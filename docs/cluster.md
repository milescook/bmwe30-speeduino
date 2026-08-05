# Overview

The objective here is a ts-dash (see http://tunerstudio.com/index.php/products/ts-dash) replacement for the instrument clocks, using the standard E30 wiring.

We use a raspberry pi and lcd touch screen, and custom 3d printed dash cluster.

![Dash](../images/ts-dash.png)

![Cluster](../images/cluster.png)
## Pins

https://www.e30zone.net/e30wiki/images/b/b2/Instrument_Cluster.pdf


## Cluster connectors

There is an stl file for the connector (tested with blue) in the stls folder. Basically it looks like below and the blue connector fits perfectly. The pins themselves are just bent dupont connectors fixed in place with a hot glue gun. Seems to work. At time of writing, more work is needed to get the locking tab to do it's job, but it certainly isn't loose.

Direct serial over the dash connectors is a non starter as pi uses 3.3v arduino uses 5v. If I can find another connection I can go via the usb plugs but can only find 3 ECU pinouts / Dash connectors

![Cluster](../images/clusterconnector.png)



## C1 (Blue)
26 Pins

- 7 Tachometer ~~(now Speeduino USB serial data TX from Motronic pin 6) to Pi 10 RX - Orange~~
- 11 Fuel flow rate ~~(now Speeduino USB serial data RX from Motronic pin 32) to Pi 8 TX - Yellow~~
- 14 Alternator light +
- 16 Alternator lights -
- 18 Oil  
- 20 GND
- 23 Live 12v


## C2 (White)
26 Pins

- 4 Fuel tank sender
- 5 Fuel tank low light
- 8 Speed sensor
- 13 Speed sensor
- 22 Check Light ~~(now Speeduino USB GND from Motronic pin 16) to Pi~~

## Diagrams
![Plug](../images/dash-blue-port-pins.png)
![Plug](../images/dash-blue-plug-pins.png)

## Pi
![Drawing](../images/pi-drawing.png)

