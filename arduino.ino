#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
//i2c pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // 

#include <dht.h>
#define dht_apin A0 // Analog Pin sensor is connected to
dht DHT;
void setup() 
{
//WE define our LCD 16 columns and 2 rows
lcd.begin(16,2);
lcd.backlight();//Power on the back light
//lcd.backlight(); Power off the back light

Serial.begin(9600);
delay(500);//Delay to let system boot
Serial.println("DHT11 Humidity & temperature Sensor\n\n");
delay(1000);//Wait before accessing Sensor

}

  

void loop() {
  // put your main code here, to run repeatedly:
    DHT.read11(dht_apin);

    lcd.setCursor(0,0);
    //Serial.print("Current humidity = ");
    lcd.print("Hum: ");
    lcd.print(DHT.humidity);
    lcd.print("%");
    //Serial.print(DHT.humidity);
    //Serial.print("%  ");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(DHT.temperature);
    lcd.print(" degC");
    //Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.print(" , ");
    Serial.println(DHT.humidity);
    //Serial.println("C  ");
    
    delay(2000);//Wait 5 seconds before accessing sensor again.
}
