#!/usr/bin/env python3

import re
import sys
import time

try:
    import serial
except ImportError:
    print("pyserial is required: pip install pyserial", file=sys.stderr)
    raise SystemExit(1)


LINE_RE = re.compile(r"fuel_raw=(\d+)\s+fuel_pct=(\d+)")


def main() -> int:
    port = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"
    baud = int(sys.argv[2]) if len(sys.argv) > 2 else 115200

    with serial.Serial(port, baudrate=baud, timeout=1) as ser:
        while True:
            line = ser.readline().decode("utf-8", errors="replace").strip()
            if not line:
                continue

            match = LINE_RE.search(line)
            if not match:
                continue

            raw = int(match.group(1))
            percent = int(match.group(2))
            print(f"fuel_raw={raw} fuel_pct={percent}")
            time.sleep(0.01)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())