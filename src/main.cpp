
#include <Arduino.h>
#include "pitches.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
	Serial.println("Serial set up -> OK");

  pinMode(3, OUTPUT); // BUZZER
  
  pinMode(8, OUTPUT); // LED
  pinMode(9, OUTPUT); // LED
  pinMode(10, OUTPUT); // LED
  pinMode(11, OUTPUT); // LED
  pinMode(4,INPUT_PULLUP); // BOTON
  pinMode(5,INPUT_PULLUP); // BOTON
  pinMode(6,INPUT_PULLUP); // BOTON
  pinMode(7,INPUT_PULLUP); // BOTON
}

void enciende_led(int led, int segundos) {
  digitalWrite(led, HIGH);
  delay(round(abs(segundos)*1000));
  digitalWrite(led, LOW);
}

bool boton_apretado(int boton) {
 return digitalRead(boton) == LOW;
}

int espera_boton_pulsado() {

  while (true) {
   
    if (boton_apretado(4)) {
      Serial.println("Boton apretado...");
      delay(300); // De-bounce
      return 4;
    }
    if (boton_apretado(5)) {
      Serial.println("Boton apretado...");
      delay(300); // De-bounce
      return 5;
    }
    if (boton_apretado(6)) {
      Serial.println("Boton apretado...");
      delay(300); // De-bounce
      return 6;
    }
    if (boton_apretado(7)) {
      Serial.println("Boton apretado...");
      delay(300); // De-bounce
      return 7;
    } 
  }
}


void turno_de_jugador() {

  int contador = 0;
  while (contador<4 ) {

    int boton=espera_boton_pulsado();

    if(boton == 4) {
      enciende_led(8,1);
    }
    if(boton == 5) {
      enciende_led(9,1);
    }
    if(boton == 6) {
      enciende_led(10,1);
    }
    if(boton == 7) {
      enciende_led(11,1);
    }
    contador=contador+1;
  }
}

void muestra_patron() {

  enciende_led(8,1);
  enciende_led(9,1);
  enciende_led(10,1);
  enciende_led(11,1);
}

void soniditito(){

  tone(3, NOTE_C4,1000);
  delay(500);
  noTone(3);

  tone(3, NOTE_D4,1000);
  delay(500);
  noTone(3);

  tone(3, NOTE_E4,1000);
  delay(500);
  noTone(3);
/*
  tone(3, NOTE_F4,1000);
  delay(1000);
  noTone(3);

  tone(3, NOTE_G4,1000);
  delay(1000);
  noTone(3);

  tone(3, NOTE_A4,1000);
  delay(1000);
  noTone(3);

  tone(3, NOTE_B4,1000);
  delay(1000);
  noTone(3);

  tone(3, NOTE_C5,1000);
  delay(1000);
  noTone(3);
  */

}

void loop() {
  soniditito();
  muestra_patron();
  turno_de_jugador();
}

