// #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gateServo;

const int IR_PIN = 5;
const int IR_1 = 2;
const int IR_2 = 3;
const int IR_3 = 4;



void setup() {
  pinMode(IR_PIN, INPUT);
  pinMode(IR_1, INPUT);
  pinMode(IR_2, INPUT);
  pinMode(IR_3, INPUT);

  gateServo.attach(9);
  gateServo.write(0); 
  
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Parking lot system");

  lcd.setCursor(0, 1);
  lcd.print("Abdalla project");
  delay(5000); 
  lcd.clear();
  
}



void loop() {

  int sensor = digitalRead(IR_PIN);
  int sensor_1 = digitalRead(IR_1);
  int sensor_2 = digitalRead(IR_2);
  int sensor_3 = digitalRead(IR_3);
   
  
   
  
  int counter = 0;
  if (sensor_1 == LOW) counter++;
  if (sensor_2 == LOW) counter++;
  if (sensor_3 == LOW) counter++;
  
  int available = 3 - counter;

  if (sensor == LOW  ) 
  {
    if (available > 0  )
    {
     // car detected
    gateServo.write(90);
     
    lcd.setCursor(0, 0);
    lcd.print("Gate Opening   ");
    lcd.setCursor(0, 1);
    lcd.print("spots left; ");
    lcd.print(available);
    }

  } else {
    gateServo.write(0); 
    lcd.setCursor(0, 0);
    lcd.print("gate closed");

  }




  delay(10);
  


}



/*
void servoTest()
{
   gateServo.write(90);
  delay(1000); 
  gateServo.write(0);
  delay(1000); 
  gateServo.write(60);
  delay(1000); 
  gateServo.write(0);
  delay(1000); 
}

void sensorTest()
{
  Serial.print("Entrance Sensor: "); 
  Serial.println(sensor); 
  delay(200);
  
  Serial.print("parking lot 1: "); 
  Serial.println(sensor_1); 
  delay(200);

  Serial.print("parking lot 2: "); 
  Serial.println(sensor_2); 
  delay(200);

  Serial.print("parking lot 3: "); 
  Serial.println(sensor_3); 
  delay(200);
}*/
