const int fuelPin = A0;
const int sampleCount = 32;
const unsigned long reportIntervalMs = 250;

// Replace these with your measured raw values after installation.
// With DEFAULT (5V) reference: full (0 ohm sender) ~0, empty (60 ohm sender) ~157.
const int fullRaw = 20;
const int emptyRaw = 157;

int readAverageRaw()
{
    long total = 0;

    for (int sample = 0; sample < sampleCount; sample++) {
        total += analogRead(fuelPin);
        delay(2);
    }

    return total / sampleCount;
}

int rawToPercent(int raw)
{
    if (raw <= fullRaw) {
        return 100;
    }

    if (raw >= emptyRaw) {
        return 0;
    }

    long scaled = (long)(emptyRaw - raw) * 100L;
    return (int)(scaled / (emptyRaw - fullRaw));
}

void setup()
{
    Serial.begin(115200);
    // INTERNAL (1.1V) gives better resolution but is ATmega328P-only.
    // Use DEFAULT (5V) for broad compatibility; re-calibrate fullRaw/emptyRaw
    // after fitting — with 5V ref and 330ohm divider, emptyRaw will be ~157.
    analogReference(DEFAULT);
    delay(50);
}

void loop()
{
    int raw = readAverageRaw();
    int percent = rawToPercent(raw);

    Serial.print("fuel_raw=");
    Serial.print(raw);
    Serial.print(" fuel_pct=");
    Serial.println(percent);

    delay(reportIntervalMs);
}