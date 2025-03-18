#include <Arduino.h>

/*
void showSequence();
int waitForButtonPress();
bool playerTurn();
void generateSequence();

#define LED_COUNT 4
#define SEQUENCE_LENGTH 5  // Número de pasos en la secuencia

// Pines de LEDs y botones
const int ledPins[LED_COUNT] = {3, 4, 5, 6}; 
const int buttonPins[LED_COUNT] = {7, 8, 9, 10};  

int sequence[SEQUENCE_LENGTH];  // Almacena la secuencia de juego
int playerInput[SEQUENCE_LENGTH]; // Entrada del jugador




// Generar secuencia aleatoria
void generateSequence() {
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        sequence[i] = random(0, LED_COUNT);  // Números entre 0 y 3 (LEDs disponibles)
    }
}

// Mostrar la secuencia al jugador
void showSequence() {
    Serial.println("Mostrando secuencia...");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int led = sequence[i];
        digitalWrite(ledPins[led], HIGH);
        delay(500);
        digitalWrite(ledPins[led], LOW);
        delay(250);
    }
}

// Leer entrada del jugador
bool playerTurn() {
    Serial.println("Tu turno...");
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        int pressedButton = waitForButtonPress();
        playerInput[i] = pressedButton;
        if (playerInput[i] != sequence[i]) {
            return false;  // Jugador se equivocó
        }
    }
    return true;  // Jugador acertó la secuencia
}

// Esperar hasta que el jugador presione un botón
int waitForButtonPress() {
    while (true) {
        for (int i = 0; i < LED_COUNT; i++) {
            if (digitalRead(buttonPins[i]) == LOW) {
                digitalWrite(ledPins[i], HIGH);
                delay(300);  // Pequeña pausa
                digitalWrite(ledPins[i], LOW);
                return i;  // Retorna índice del botón presionado
            }
        }
    }
}


void setup() {
    Serial.begin(9600);  // Para depuración

    // Configurar LEDs y botones
    for (int i = 0; i < LED_COUNT; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonPins[i], INPUT_PULLUP);  // Botones con resistencias internas de pull-up
    }

    randomSeed(analogRead(0));  // Semilla aleatoria
    generateSequence();  // Generar la secuencia aleatoria
}

void loop() {
    showSequence();
    if (!playerTurn()) {
        Serial.println("Game Over!");
        delay(2000);
        generateSequence();  // Nueva secuencia si el jugador falla
    } else {
        Serial.println("Correcto! Avanza...");
        delay(1000);
    }
}
*/