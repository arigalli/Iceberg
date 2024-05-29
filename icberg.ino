/*este sketch permite medir temperatura con el sensor DB18B20
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  //




#include<OneWire.h>                
#include<DallasTemperature.h>
OneWire ourWire(5);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire);//Se declara una variable u objeto para nuestro sensor
const int pinRELE = 7;
float setpoint=13;

void setup() {
delay(1000);
Serial.begin(115200);
sensors.begin();   //Se inicia el sensor
  pinMode(pinRELE, OUTPUT);
  // Inicializar el LCD
  lcd.init();
  
  //Encender la luz de fondo.
  lcd.backlight();
  //lcd.noBacklight();
  // Escribimos el Mensaje en el LCD.
   lcd.setCursor(6, 0);
  lcd.print("CUEM");
  delay(4000); 
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("ICEBERG 1.0");
  delay(4000);
  lcd.clear(); 
  lcd.setCursor(2, 0);
  lcd.print("REFRIGERADOR");
  delay(4000); 
  
}
void loop() {
sensors.requestTemperatures();//Se envía el comando para leer la temperatura
float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC

Serial.print("Temperatura= ");
Serial.print(temp);
Serial.println("C");
delay(100);  

if(temp>setpoint){
  digitalWrite(pinRELE, HIGH);
  }
  else
  {
  digitalWrite(pinRELE, LOW);
  }
  delay(5000);
  lcd.setCursor(0, 0);
  lcd.print("Temp: "); 
  lcd.print(temp);   
  lcd.print(" ");
  lcd.print((char)223);  
  lcd.print("C"); 
  lcd.setCursor(0, 1);
  lcd.print("setpoint:"); 
  lcd.print(setpoint);   
  lcd.print((char)223);  
  lcd.print("C"); 
}
