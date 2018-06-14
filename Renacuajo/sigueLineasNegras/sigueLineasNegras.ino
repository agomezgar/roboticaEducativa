//ROBOT sigueLuz
#include<Servo.h>
Servo mDerecha, mIzquierda;
int sDerecha, sIzquierda;
//El blanco son valores altos, y el negro bajos.
int umbralBlanco=650;
int umbralNegro=450;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mDerecha.attach(7);
mIzquierda.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print(analogRead(A4));
Serial.print("\t");
Serial.print(analogRead(A5));
Serial.print("\t");
Serial.print(analogRead(A2));
Serial.print("\t");
Serial.println(analogRead(A3));
sDerecha=analogRead(A4);
sIzquierda=analogRead(A5);
if ((sDerecha<umbralNegro)&&(sIzquierda<umbralNegro)){
  adelante();
}
if ((SDerecha<umbralNegro)&&(sIzquierda>umbralBlanco)){
  giraDerecha();
}
if ((sDerecha>umbralBlanco)&&(sIzquierda<umbralNegro)){
  giraIzquierda();
}

delay(100);
}
void adelante(){
  mDerecha.write(120);
mIzquierda.write(60);
}
void paro(){
    mDerecha.write(90);
mIzquierda.write(90);
}
void giraDerecha(){
  mDerecha.write(90);
  mIzquierda.write(60);
}

void giraIzquierda(){
  mDerecha.write(120);
  mIzquierda.write(90);
}

