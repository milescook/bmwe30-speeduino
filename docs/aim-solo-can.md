# Speeduino engine data to AiM SOLO 2 DL over CAN

## Objective and status

Send live Speeduino engine data to the AiM SOLO 2 DL so it can record engine channels alongside its GPS and lap data. Sending lap-time data back to the Pi is not required.

This is an installation plan, not a tested end-to-end configuration. The CarPiHAT CAN hardware is documented, but the Pi data source, bridge software, AiM protocol and bitrate still need to be selected and verified.

## Hardware and data path

- Speeduino connected to the Raspberry Pi by USB.
- Raspberry Pi running TS Dash and fitted with the TJD CarPiHAT linked below.
- AiM SOLO 2 DL with its ECU CAN/power cable, already available for this build.
- Suitable CAN twisted-pair cable and a mating CarPiHAT CAN connector/pigtail.

The standard SOLO 2 does not have the ECU CAN input; this plan is for the SOLO 2 DL.

```text
Speeduino --USB--> Pi ECU-data source --+--> TS Dash
                                      |
                                      +--> CAN bridge --> CarPiHAT --> SOLO 2 DL
```

The ECU-data source and bridge arrangement are to be determined. The CarPiHAT provides the CAN controller and transceiver; it does not automatically translate Speeduino USB data into AiM-compatible CAN messages.

## Wiring

Use the CarPiHAT's dedicated CAN connector, not the Raspberry Pi GPIO header. The manufacturer's connector diagram gives:

| CarPiHAT CAN connector pin | Connect to SOLO 2 DL ECU cable signal |
| --- | --- |
| 1 - CAN L | CAN- / CAN L |
| 2 - CAN H | CAN+ / CAN H |
| 3 - GND | GND |
| 4 - switched 12 V | Leave disconnected in this plan |

Check connector orientation against the manufacturer's diagram before identifying pin 1. Do not infer pin positions or signals from pigtail wire colours. AiM connector pin numbers and cable colours must be checked against the documentation for the actual ECU cable; they are not specified here.

Use the AiM ECU CAN connection, not an accessory/expansion connection. Supply the SOLO through its designated power input from an appropriately fused supply meeting AiM's voltage requirements. Do not power it from the Pi's GPIO or assume the unused CarPiHAT 12 V pin is suitable without checking its rating and protection.

Use a twisted pair for CAN H and CAN L, with a ground connection between the devices. Keep wiring away from coils, ignition leads and other high-current wiring. If routed through the custom dash connector, reserve and document the CAN H, CAN L and ground pins in [the cluster wiring notes](cluster.md); those assignments are currently unresolved.

## CAN termination

The CarPiHAT documentation states that a 120 ohm resistor is already fitted between CAN H and CAN L. For this two-device bus, it should be at one physical end of the cable.

Check whether the SOLO or its cable provides termination at the other end. Add a 120 ohm resistor there only if it is absent. Do not add another resistor at the CarPiHAT end.

With both devices and any other bus power sources switched off, measure resistance between CAN H and CAN L:

| Approximate reading | Interpretation |
| --- | --- |
| 60 ohms | Consistent with two 120 ohm terminators in parallel |
| 120 ohms | Consistent with only one terminator |
| 40 ohms | Consistent with three terminators; check for an extra one |

These are diagnostic expectations, not proof of correct wiring or communication. Never use the resistance range on a powered circuit.

## Raspberry Pi CAN configuration

The linked CarPiHAT uses an MCP2515 controller with an 8 MHz crystal and its interrupt on BCM23. Linux exposes it as a SocketCAN interface, normally `can0`.

The relevant boot configuration settings from the maker's guide are:

```ini
dtparam=spi=on
dtoverlay=mcp2515-can0,oscillator=8000000,interrupt=23
```

The boot configuration file is typically `/boot/config.txt` on older Raspberry Pi OS releases or `/boot/firmware/config.txt` on newer releases. Check the installed OS, existing overlays and maker's guide before changing it, then reboot. The guide also notes a possible SPI CS1 conflict with the reverse input on BCM7.

After reboot, check that the interface exists:

```sh
ip -details link show can0
```

Configure and bring up `can0` using the bitrate required by the chosen AiM ECU protocol. Do not copy the maker's example 100 kbit/s value unless that protocol requires it. Persistent network configuration depends on the Pi's OS and network manager.

## Bridge software and AiM configuration

The bridge must obtain live Speeduino engine readings and encode them as the CAN messages expected by an ECU protocol supported by the SOLO 2 DL.

1. Confirm the installed TS Dash version and whether it offers a suitable live-data interface. No particular export API is assumed here.
2. If a separate ECU-data service is needed, verify that it can serve TS Dash and the bridge together. Do not let two independent programs open and poll the same Speeduino USB serial port.
3. Select an AiM-supported ECU CAN protocol with an available message specification. Confirm that the SOLO 2 DL supports that protocol, not just another AiM product.
4. Document the protocol's bitrate, message IDs, standard/extended identifiers, payload layout, byte order, units, scaling and transmission rates before implementing the bridge.
5. In AiM Race Studio, select the matching ECU manufacturer/model/protocol and send the configuration to the SOLO. Verify the channels available in that configuration.
6. Implement the bridge using SocketCAN and test it against known input values before connecting it to a running engine.

The bridge should stop publishing engine data when its source becomes stale or disconnected, or use the selected protocol's documented invalid-data representation. It must not keep broadcasting the last readings as though they were current.

Candidate channels include RPM, coolant temperature, intake temperature, TPS, MAP, battery voltage and AFR/lambda. Actual availability depends on both the live-data source and the selected AiM protocol. Check units explicitly, especially Celsius/Fahrenheit, kPa/bar and AFR/lambda.

## Commissioning checks

1. With power off, verify connector orientation, continuity, CAN H/L polarity and termination.
2. Power the equipment and check `can0` for errors using `ip -details -statistics link show can0`. Resolve bus-off or increasing error counts before proceeding.
3. Use a CAN monitor such as `candump can0` from `can-utils` to check message IDs and rates. Seeing transmitted frames locally alone does not prove the SOLO is receiving or decoding them.
4. With the engine stopped, compare displayed/logged temperature, TPS, MAP and battery voltage against TS Dash. Confirm zero RPM.
5. With the car stationary and safe to run, compare RPM and other changing values at idle. Check that TS Dash continues working while the bridge is active.
6. Disconnect the ECU data source and confirm stale readings are not presented as current.
7. Record a short SOLO session, download it and verify the engine channels, units and sample rates in the recorded data, not just on the live display.

## Outstanding decisions

- Exact AiM ECU cable pinout and SOLO-end termination.
- Custom dash connector assignments for CAN H, CAN L and ground.
- TS Dash live-data interface or shared ECU-data service.
- AiM ECU protocol, message specification, bitrate and channel mapping.
- Bridge implementation, startup service and stale-data behavior.

## References

- [CarPiHAT product used in this build](https://thepihut.com/products/carpihat-car-interface-hat-for-raspberry-pi?variant=41600908460227)
- [CarPiHAT maker's quick start guide, pinout and CAN configuration](https://github.com/gecko242/CarPiHat/wiki/Quick-Start-Guide)
- [CarPiHAT connector diagram](https://raw.githubusercontent.com/SamT-J/CarPiHat/master/Datasheet_latest.png)
- [Cluster conversion and dash wiring](cluster.md)