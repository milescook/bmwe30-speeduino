# TPS

Note: TPS ground is being moved from chassis ground to ECU sensor ground to reduce analog noise.
Use the shared sensor ground path (Motronic pin 26 -> Speeduino pin 9) for TPS ground.

E36 TPS Pin - E30 Pin - Purpose - Motronic pin - Speeduino Pin - IDC Pin
- 1 - 2 - GND (sensor ground) - 26 - 9 - 24
- 2 - 1 - Signal - 52 - 22 - 3
- 3 - 3 - Vref (5v) 53 - 13 - 16

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
