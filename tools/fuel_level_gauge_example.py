#!/usr/bin/env python3

import json
import sys


def main() -> int:
    for line in sys.stdin:
        line = line.strip()
        if not line:
            continue

        try:
            payload = json.loads(line)
        except json.JSONDecodeError:
            continue

        if "fuel_pct" not in payload:
            continue

        fuel_pct = int(payload["fuel_pct"])
        print(f"fuel_level_pct={fuel_pct}", flush=True)

    return 0


if __name__ == "__main__":
    raise SystemExit(main())