//ROBOT HUYELUZ
#include<Servo.h>
Servo mDerecha, mIzquierda;
int luzDerecha, luzIzquierda;
//A más luz ambiente, subir la luz umbral (hasta 800 0 así)
int umbral=200;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mDerecha.attach(7);
mIzquierda.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(analogRead(A0));
Serial.print("\t");
Serial.print(analogRead(A1));
Serial.print("\t");
Serial.print(analogRead(A2));
Serial.print("\t");
Serial.println(analogRead(A3));
luzDerecha=analogRead(A2);
luzIzquierda=analogRead(A3);
if (luzDerecha>200){
  mIzquierda.write(0);
}else{
  mIzquierda.write(90);
}
if (luzIzquierda>200){
  mDerecha.write(180);
}else{
  mDerecha.write(90);
}
delay(100);
}
void adelante(){
  mDerecha.write(180);
mIzquierda.write(0);
}
void paro(){
    mDerecha.write(90);
mIzquierda.write(90);
}
void giraDerecha(){
  mDerecha.write(90);
  mIzquierda.write(00);
}

void giraIzquierda(){
  mDerecha.write(180);
  mIzquierda.write(90);
}

