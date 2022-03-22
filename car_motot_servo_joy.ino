# include <Servo.h>
// definisco le var del joystik
int pinX=A0;
int pinY=A1;
int pinS=4;
int valX;
int valY;
int valS;
// definisco le variabili del motore
int speedPin=9;
int dir1=12;
int dir2=13;
float mSpeed;
// definisco variabili servo
int servoPin=10;
int servoPos=95;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); //attivo porta serial
// definisco pin joystik
pinMode(pinX,INPUT);
pinMode(pinY,INPUT);
pinMode(pinS,INPUT);
digitalWrite(pinS,HIGH);
//definisco pin DC motor
pinMode(speedPin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
// deinisco servo
myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
// var joystik
valX=analogRead(pinX);
valY=analogRead(pinY);
valS=digitalRead(pinS);
// var motore
if(valX>=503){
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  mSpeed=((valX-503.)*255./520.);
  }
  else if (valX<503){
  digitalWrite(dir2,HIGH);
  digitalWrite(dir1,LOW);
  mSpeed=((503.-valX)*255./503.);
    }
analogWrite(speedPin,mSpeed);
//servo
servoPos=(50.+valY*90./1023.);
myServo.write(servoPos);
//DEBUG
Serial.print("X valor = ");
Serial.print(valX);
Serial.print(" | Y valor = ");
Serial.print(valY);
Serial.print(" | S valor = ");
Serial.println(valS);
Serial.println(mSpeed);
delay(100);
}
