#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

double x = 0;
double y = 0;
double a = 0;
double b = 0;

int windSensor = A1;
float voltageMax = 2.0;
float voltageMin = .4;
float voltageConversionConstant = .004882814;
float sensorVoltage = 0;

float windSpeedMin = 0;
float windSpeedMax = 32;

int windSpeed = 0;
int prevWindSpeed = 0;

void.setup(){
  lcd.begin(10,2);
  Serial.begin(9600);
}

void loop(){
  int sensorValue = analogRead(windSensor);
  
  float voltage = sensorValue * (5.0 / 1023.0);
  sensorVoltage = sensorValue * sensorConversionConstant;
  
  if(snesorVoltage <= voltageMin){
    windSpeed = 0;
  } else{
    windSpeed = ((sensorVoltage - voltageMin) * windSpeedmax / (voltageMax - voltageMin)) * 2.232694;
  }
  
  x =windSpeed;
  if(x>=y){
    y = x;
  } else{
    y = y;
  }
  
  a = sensorVoltage;
  if(a >= b){
    b = a;
  } else{
    b = b;
  }
  
  if(windSpeed != prevWindSpeed){
    Serial.println(windSpeed);
    Serial.println(sensorVoltage);
    prevWindSpeed = windSpeed;
  }
  
  lcd.setCursor(0, 0);
  lcd.print("Wind Speed");
  lcd.setCursor(12, 0);
  lcd.print(windSpeed);
  lcd.print(" ");
  lcd.setCursor(11, 2);
  lcd.print("m/s");
  delay(500);
  
}
