#include <Arduino.h>

/*

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
	Serial.println("Serial set up -> OK");

  
  pinMode(8, OUTPUT); // LED
  pinMode(9, OUTPUT); // LED
  pinMode(10, OUTPUT); // LED
  pinMode(11, OUTPUT); // LED
  pinMode(4,INPUT_PULLUP); // BOTON
  pinMode(5,INPUT_PULLUP); // BOTON
  pinMode(6,INPUT_PULLUP); // BOTON
  pinMode(7,INPUT_PULLUP); // BOTON
}

void enciendeLed(int led) {
  digitalWrite(led, HIGH);
  delay(200);
  digitalWrite(led, LOW);
}

bool botonApretado(int boton) {
  int apretado = digitalRead(boton);
  //delay(50);
  if (apretado==LOW)
  {
    return true;
  }else {
    return false;
  }

  
  return apretado;
}

void esperaBoton() {
  while (true) {
    if(botonApretado(4) == true) {
      enciendeLed(8);
    }
    if(botonApretado(5) == true) {
      enciendeLed(9);
    }
    if(botonApretado(6) == true) {
      enciendeLed(10);
    }
    if(botonApretado(7) == true) {
      enciendeLed(11);
    }
  }
}
void loop() {
  esperaBoton();
}

*/