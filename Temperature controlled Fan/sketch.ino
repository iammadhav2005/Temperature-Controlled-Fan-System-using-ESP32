#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

#define DHTPIN 15
#define DHTTYPE DHT22
#define SERVOPIN 4

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo fan;

void setup() {
  Serial.begin(115200);
  dht.begin();
  lcd.init();
  lcd.backlight();
  fan.attach(SERVOPIN);
  lcd.setCursor(0, 0);
  lcd.print("Temp Controlled");
  lcd.setCursor(0, 1);
  lcd.print("Fan System");
  delay(2000);
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT22 read failed!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  // Fan control logic
  int angle = 0;
  if (temp <= 25) {
    angle = 0; // Fan off
  } else if (temp >= 50) {
    angle = 180; // Max speed
  } else {
    angle = map(temp, 25, 50, 0, 180); // proportional speed
  }

  fan.write(angle);

  // LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(hum, 0);
  lcd.print("% Fan:");
  lcd.print(map(angle, 0, 180, 0, 100));
  lcd.print("%");

  // Serial monitor output
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C, Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Fan Angle: ");
  Serial.println(angle);

  delay(2000);
}
