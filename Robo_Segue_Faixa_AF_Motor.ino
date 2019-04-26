/*
 * Colégio Univap - CTI - Curso Técnico em Eletrônica
 * Código do Robô segue Faixa utilizando a Ponte H modelo AFMotor
 */

#include <AFMotor.h>

AF_DCMotor motor4(2);
AF_DCMotor motor1(1);

#define sensor_L  3
#define sensor_R  5

void frente(void)
{
  motor4.run(FORWARD);
  motor1.run(FORWARD);
}

void tras(void)
{
  motor4.run(BACKWARD);
  motor1.run(BACKWARD);
}

void direita(void)
{
  motor4.run(FORWARD);
  motor1.run(BACKWARD);
}

void esquerda(void)
{
  motor4.run(BACKWARD);
  motor1.run(FORWARD);
}

void parar(void)
{ 
  motor4.run(RELEASE);
  motor1.run(RELEASE);
  
}

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps

  pinMode(sensor_L, OUTPUT);
  pinMode(sensor_R, OUTPUT);

  // turn on motor
  motor4.setSpeed(200);
  motor1.setSpeed(200);

  parar();

  Serial.println("OK");
}

void loop() {

  if(digitalRead(sensor_L))
  {
    esquerda();
  }
  else if (digitalRead(sensor_R))
  {
    direita();
  }else frente();

  delay(50);

  if(Serial.available() > 0)
  {
    char dado;

    dado = Serial.read();

    switch(dado)
    {
      case 'F' :  motor4.run(FORWARD);
                  motor1.run(FORWARD);
                  break;

      case 'B' :  motor4.run(BACKWARD);
                  motor1.run(BACKWARD);
                  break;

      case 'S' :  motor4.run(RELEASE);
                  motor1.run(RELEASE);
                  break;
    }
  }
}
