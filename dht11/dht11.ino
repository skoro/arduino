// Library https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

#include <DFRobot_DHT11.h>

DFRobot_DHT11 DHT;

// I2C address pool for chips:
// PCF8574T - 0x20-0x27
// CF8574AT - 0x38-0x3f
LiquidCrystal_I2C lcd(0x3f, 16, 2);

#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println("Test DHT11");
  lcd.init();
  lcd.backlight();
}

void loop() {
  DHT.read(DHT11_PIN);
  Serial.print("T=");
  Serial.print(DHT.temperature);
  Serial.print(", ");
  Serial.print("H=");
  Serial.println(DHT.humidity);
  lcd.setCursor(0,0);
  lcd.print("Temp=");
  lcd.print(DHT.temperature);
  lcd.setCursor(0,1);
  lcd.print("Humidity=");
  lcd.print(DHT.humidity);
  delay(1000);
}
