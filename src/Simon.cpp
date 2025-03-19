#include <Arduino.h>
#include <Vector.h>
#include <time.h>
#include "abtract_c.h"
#include "pitches.h"

#define NUMERO_DE_LEDS 4
#define NUMERO_DE_BOTONES 4
const uint8_t MAXIMA_SECUENCIA = 10; // Maxima secuencia de pasos en la secuencia a repetir
uint8_t LONGITUD_SECUENCIA = 4;  // Número de pasos en la secuencia a repetir

// Pines de LEDs y botones
const int ledPines[NUMERO_DE_LEDS] = {8, 9, 10, 11}; 
const int botonPines[NUMERO_DE_BOTONES] = {4, 5, 6, 7};

Vector<uint8_t> patron_de_luces = {};

int espera_hasta_boton_apretado();
void muestra_patron_luces(Vector<uint8_t> patron);
void turno_del_jugador(Vector<uint8_t> patron);
void enciende_led(int led, int segundos);
int* genera_patron_luces();
int numero_aleatorio(int max);


void enciende_led(int led, int segundos) {
    digitalWrite(led, HIGH);
    delay(round(abs(segundos)*1000));
    digitalWrite(led, LOW);
}

void muestra_patron_luces(int* patron) {
    for (int led = 0; led<NUMERO_DE_LEDS; led++) {
        enciende_led(ledPines[led], 1);
    }
}


int espera_hasta_boton_apretado() {
    while (true)
        for (int boton = 0; boton<NUMERO_DE_BOTONES; boton++) {
            if (digitalRead(botonPines[boton]) == LOW) {
                Serial.println("Boton apretado...");
                delay(300); // De-bounce
                return boton;
            }
        }
}

void turno_del_jugador(int* patron) {
    
    for (int paso_de_la_secuencia = 0; paso_de_la_secuencia < LONGITUD_SECUENCIA; paso_de_la_secuencia++)
    {
        int boton_apretado = espera_hasta_boton_apretado();
        Serial.println("Numero apretado = " + (String)boton_apretado);
        enciende_led(ledPines[boton_apretado], 1);
    }
    
}

int numero_aleatorio(int max) {
    return rand() % max;
}

int* genera_patron_luces() {

    int* secuencia_de_luces = new int[LONGITUD_SECUENCIA];
    for (int i = 0; i < LONGITUD_SECUENCIA; i++)
    {
        secuencia_de_luces[i] = numero_aleatorio(NUMERO_DE_LEDS);
    }
    return secuencia_de_luces;
}


// ====== PROGRAMA PRINCIPAL ==== //

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    Serial.println("Serial set up -> OK");
    
    for (int i = 0; i<NUMERO_DE_LEDS; i++) 
        pinMode(ledPines[i], OUTPUT); // LEDS
    for (int i = 0; i<NUMERO_DE_BOTONES; i++) 
        pinMode(botonPines[i], INPUT_PULLUP); // Botones

    // Semilla para los numeros aleatorios
    srand(time(NULL));
}

void loop() {
    int* patron_de_luces = genera_patron_luces();
    muestra_patron_luces(patron_de_luces);
    turno_del_jugador(patron_de_luces);
}

