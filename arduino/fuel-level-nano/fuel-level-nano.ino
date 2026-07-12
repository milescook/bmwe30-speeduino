const int fuelPin = A0;
const int sampleCount = 32;
const unsigned long reportIntervalMs = 250;

// Replace these with your measured raw values after installation.
const int fullRaw = 20;
const int emptyRaw = 800;

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
    analogReference(INTERNAL);
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