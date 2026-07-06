# ECU pins plug

Status: ON HOLD reference for a custom harness approach. For the current running Motronic-harness setup, use `motronic-speeduino-map.md` as source of truth.

This is a list of functions (see https://wiki.speeduino.com/en/boards/V04) and ECU connector pins - not all correspond to the Speeduino output pins



## Pin no, Function -> (IDC ribbon number) <=> harness wire # & colour
* Pin number corresponds to the Speeduino IDC pin number
* IDC ribbon number is what is labelled (see table after this) as IDC numbering is different to speeduino pin numbers
* Harness wire is where it comes out of the ECU connector
* Some assignments in this file (for example fuel pump output) are plan-level notes and may not match the active Motronic map.

* 1	Injector 1 - Pin 1/2 -> *Injector 1&6* (40) <=> 1 Yellow
* 2	Injector 2 - Pin 1/2 -> *Injector 2&5* (38) <=> 2 Blue
* 3	Injector 3 - Pin 1/2 -> *Injector 3&4* (36) <=> 3 Green
* 4	Injector 3 - Pin 2/2 -> *Injector 3&4* (34) <=> 4 White
* 5	Injector 4 - Pin 1/2 - Unused
* 6	Injector 4 - Pin 2/2 - Unused
* 7	Ignition 1 -> *Coil on plug 1 & 6* (28) <=> 7 Yellow
* 8	Ignition 4 -> *Unused*
* 9	Ground coolant, iat, lambda -> (26) <=> 8 Blue
* 10	Ground - Shield ground <=> 24 White to shield
* 11	MAP Sensor (0v-5v) *N/A - using onboard sensor*
* 12	TPS Ground 
* 13	5v power supply - TPS
* 14	Proto Area 1 (0.4.4b+ Flex Sensor)
* 15	Proto Area 2 (0.4.4b+ Fan)
* 16	Proto Area 3 (0.4.4b+ Fuel Pump) -> Fuel Pump Relay (10) <=> 16 Yellow
* 17	Proto Area 4 (0.4.4b+ Tachometer) -> AIM Dash Tacho (8) <=> 17 Blue
* 18	Proto Area 5 (0.4.4b+ Clutch)
* 19	Coolant (CLT) -> *Blue temp sender* (4) <=> 19 Green
* 20	Inlet Air Temp (IAT) -> *New IAT Sensor* (2) <=> 20 White
* 21	O2 Sensor -> *Exhaust Lambda Sensor* (1) <=> 21 Blue
* 22	TPS input -> *Variable Auto BMW TPS* (3) <=> 22 Black
* 23	Ground -> Crank ground (5) <=> 23 white shielded
* 24	Cam Input / VR2+
* 25	Crank Input / VR1+ (9) <=> 25 red shielded
* 26	VR2- (Not used for hall sensor)
* 27	VR1- (Not used for hall sensor)
* 28	5v
* 29	Idle Stepper 2B
* 30	Idle Stepper 2A
* 31	Idle Stepper 1A
* 32	Idle Stepper 1B
* 33	Ignition 3 -> *Coil on plug 3 & 4* (25) <=> 33 Green
* 34	Ignition 2 -> *Coil on plug 2 & 5* (27) <=> 34 White
* 35	Boost *N/A No snail for us, yet....*
* 36	Idle 2 (For use with 3 wire idle valves)
* 37	PWM Idle
* 38	VVT
* 39	Injector 2 - Pin 2/2 -> *Injector 2&5* (32) <=> 5 Red
* 40	Injector 1 - Pin 2/2 -> *Injector 1&6* (30) <=> 6 Black


