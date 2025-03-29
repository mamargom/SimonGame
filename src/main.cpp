
#include <Arduino.h>
#include "pitches.h"
#include <time.h>

int ronda = 0;

// Define un vector de posiciones de leds (4 cajitas: 0,1,2,3)
uint8_t patron_de_leds[5];
uint8_t longitud_de_patron = 5;


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
    Serial.println("Ronda: " + (String) ronda + " Boton: " + (String) boton);

    if(boton == 4) {
      enciende_led(9,1);
    }
    if(boton == 7) {
      enciende_led(8,1);
    }
    if(boton == 5) {
      enciende_led(10,1);
    }
    if(boton == 6) {
      enciende_led(11,1);
    }
    contador=contador+1;
  }

  ronda = ronda + 1;
}

uint8_t led_aleatorio() {

  // calculo numero
  return (rand() % 4 ) + 8 ;
}

void genera_patron() {

  for (uint8_t i = 0; i < longitud_de_patron; i=i+1)
  {
    patron_de_leds[i] = led_aleatorio();
  }

}

void muestra_patron(){

  for (uint8_t i = 0; i < longitud_de_patron; i = i+1)
  {
    enciende_led (patron_de_leds[i], 1);
  }
  
}


/*
Genera Patron aleatorio y lo muestra al Jugador
*/
void turno_de_maquina() {

  genera_patron();
  muestra_patron();

/*
  enciende_led(9,1);
  enciende_led(8,1);
  enciende_led(10,1);
  enciende_led(11,1);
  */
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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
	Serial.println("Serial set up -> OK");

  srand(time(NULL));

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


void loop() {
  soniditito();
  turno_de_maquina();
  turno_de_jugador();
}



