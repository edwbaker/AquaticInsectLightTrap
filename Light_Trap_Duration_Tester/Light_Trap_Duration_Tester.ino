#include <SD.h>

const int chipSelect = 4;

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed.");
    return;
  }
  Serial.println("Card OK.");
}

void loop() {
    String line = "";
    int reading = analogRead(0);
    line.concat(millis());
    line.concat(",");
    line.concat(reading);
    Serial.println(reading);
    File dataFile = SD.open("DATA.TXT", FILE_WRITE);
    if (dataFile) {
     dataFile.println(line);
     dataFile.close();
    } else {
      Serial.println("File Unavailable.");
    }
    delay(60000);
}
