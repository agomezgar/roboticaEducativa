//ROBOT HUYELUZ
#include<Servo.h>
Servo mDerecha, mIzquierda;
int luzDerecha, luzIzquierda;
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
if (luzDerecha<luzIzquierda+200){
  giraDerecha();
}
if (luzIzquierda<luzDerecha+200){
  giraIzquierda();
}
if (abs(luzIzquierda-luzDerecha)<200){
  adelante();
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

