#include <Arduino.h>
#include <time.h>

#include "pitches.h"

int ronda = 0;

// Define un vector de posiciones de leds (4 cajitas: 0,1,2,3)
uint8_t patron_de_leds[5];
uint8_t longitud_de_patron = 5;

#define TIEMPO_ESPERA_DEBOUNCE 30


enum LED {
  LED_AZUL = 9,
  LED_BLANCO = 8,
  LED_ROJO = 10,
  LED_AMARILLO = 11
};

enum BOTON {
  BOTON_AZUL = 4,
  BOTON_BLANCO= 7,
  BOTON_ROJO = 5,
  BOTON_AMARILLO = 6
};

#define BUZZER               3

#define TIEMPO_ENCENDIDO_LED      400
#define TIEMPO_NOTA_MUSICAL_LARGO 500
#define TIEMPO_NOTA_MUSICAL_CORTO 200
#define ESPERA_CORTA         100
#define ESPERA_LARGA         300


void genera_semilla_random() {

  unsigned long seed = 0;
  for(int i = A0; i <= A5; i++)
  {
    seed += analogRead(i); 
  }
  randomSeed(seed);
}


void enciende_led(int led, int milisegundos) {
  digitalWrite(led, HIGH);
  delay(milisegundos);
  digitalWrite(led, LOW);
  delay(milisegundos);
}

String numero_led_a_color(uint8_t led) {
  
  if (led == LED_AZUL) return "LED_AZUL";
  if (led == LED_BLANCO) return "LED_BLANCO";
  if (led == LED_ROJO) return "LED_ROJO";
  if (led == LED_AMARILLO) return "LED_AMARILLO";

  return "?";
}

String numero_boton_a_color(uint8_t led) {
  
  if (led == BOTON_AZUL) return "BOTON_AZUL";
  if (led == BOTON_BLANCO) return "BOTON_BLANCO";
  if (led == BOTON_ROJO) return "BOTON_ROJO";
  if (led == BOTON_AMARILLO) return "BOTON_AMARILLO";

  return "?";
}

bool boton_apretado(int boton) {

  // leemos una vez
  int lectura1 = digitalRead(boton);
  delay(TIEMPO_ESPERA_DEBOUNCE);
  int lectura2 = digitalRead(boton);

  if ( (lectura1 == LOW && lectura2 == LOW))
    Serial.println("Boton " + (String) boton + "/" + numero_boton_a_color(boton) + " : " 
                    + (String) lectura1 + " -- " + (String) lectura2);
  return (lectura1 == LOW && lectura2 == LOW);

}

int numero_de_boton_pulsado() {

  while (true) {

    if (boton_apretado(BOTON_AZUL)) {
      return BOTON_AZUL;
    }
    if (boton_apretado(BOTON_BLANCO)) {
      return BOTON_BLANCO;
    }
    if (boton_apretado(BOTON_ROJO)) {
      return BOTON_ROJO;
    }
    if (boton_apretado(BOTON_AMARILLO)) {
      return BOTON_AMARILLO;
    } 
  }
}


uint8_t dame_led_de_boton(uint8_t boton) 
{

  if (boton == BOTON_AZUL) 
  {
    return LED_AZUL;
  }
  if (boton == BOTON_BLANCO)
  {
    return LED_BLANCO;
  }
  if (boton == BOTON_ROJO)
  {
    return LED_ROJO;
  }
  // en otro caso -> aseguramos al hacer a llamada a esta funcion que 
  // solo pasamos numeros de boton 4,5,6,7 
  return LED_AMARILLO;
}



boolean turno_de_victor() {

  for (int8_t i = 0; i < longitud_de_patron; i++)
  {
    int8_t boton = numero_de_boton_pulsado();
    int8_t led = dame_led_de_boton(boton);

//    Serial.println("Boton apretado = " + (String) boton + " : " + numero_boton_a_color(boton));
//    Serial.println("led encendido = " + (String) led + " : " + numero_led_a_color(led));
    enciende_led(led, TIEMPO_ENCENDIDO_LED/2);

    if (led != patron_de_leds[i])
    {
      Serial.println("Expected:" + (String)patron_de_leds[i] + "x" + numero_led_a_color(patron_de_leds[i]));
      Serial.println("Received:" + (String)led + "x" + numero_led_a_color(led));
      return false;
    }
  }
  
  return true;
}

uint8_t led_aleatorio() {

  // calculo numero
  return (random() % 4 ) + 8 ;
}

void genera_patron() {

  for (uint8_t i = 0; i < longitud_de_patron; i=i+1)
  {
    patron_de_leds[i] = led_aleatorio();
  }

}


void debug_patron() {

  Serial.println("patron [" + numero_led_a_color(patron_de_leds[0]) + " , " + 
                              numero_led_a_color(patron_de_leds[1]) + " , " + 
                              numero_led_a_color(patron_de_leds[2]) + " , " + 
                              numero_led_a_color(patron_de_leds[3]) + " , " + 
                              numero_led_a_color(patron_de_leds[4]) + "]");
}

void muestra_patron(){

  //debug_patron();

  for (uint8_t i = 0; i < longitud_de_patron; i = i+1) 
  {
    enciende_led (patron_de_leds[i], TIEMPO_ENCENDIDO_LED);
  }
  
}



//Genera Patron aleatorio y lo muestra al Jugador

void turno_de_maquina() {

  genera_patron();
  muestra_patron();
}


void marca_cambio_maquina_a_jugador(){

  tone(BUZZER, NOTE_C4,1000);
  delay(ESPERA_CORTA);
  noTone(BUZZER);

}

void soniditito(){

  tone(BUZZER, NOTE_C4);
  delay(1000);
  noTone(BUZZER);

  tone(BUZZER, NOTE_D4);
  delay(100);
  noTone(BUZZER);

  tone(BUZZER, NOTE_E4);
  delay(100);
  noTone(BUZZER);

}

void sonido_final(boolean ganado){

  if (ganado == true)
  {
    
    tone(3,NOTE_C4,1000);
    delay(TIEMPO_NOTA_MUSICAL_CORTO);
    noTone(3);

    tone(3,NOTE_C4,1000);
    delay(TIEMPO_NOTA_MUSICAL_CORTO);
    noTone(3);
    
    tone(3,NOTE_D4,1000);
    delay(TIEMPO_NOTA_MUSICAL_CORTO);
    noTone(3);
    
    tone(3,NOTE_E4,1000);
    delay(TIEMPO_NOTA_MUSICAL_CORTO);
    noTone(3);

    tone(3,NOTE_G4,1000);
    delay(TIEMPO_NOTA_MUSICAL_CORTO);
    noTone(3);

  } else {

    tone(3,NOTE_G4,1000);
    delay(TIEMPO_NOTA_MUSICAL_LARGO);
    noTone(3);
    
    tone(3,NOTE_F4,1000);
    delay(TIEMPO_NOTA_MUSICAL_LARGO);
    noTone(3);
    
    tone(3,NOTE_E4,1000);
    delay(TIEMPO_NOTA_MUSICAL_LARGO);
    noTone(3);

    tone(3,NOTE_C4,1000);
    delay(TIEMPO_NOTA_MUSICAL_LARGO);
    noTone(3);
  }
  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
	Serial.println("Serial set up -> OK");
  
  genera_semilla_random();

  pinMode(BUZZER, OUTPUT);            // BUZZER
  
  pinMode(LED_AZUL, OUTPUT);          // LED
  pinMode(LED_BLANCO, OUTPUT);        // LED
  pinMode(LED_ROJO, OUTPUT);          // LED
  pinMode(LED_AMARILLO, OUTPUT);       // LED
  pinMode(BOTON_AZUL, INPUT_PULLUP);       // BOTON
  pinMode(BOTON_BLANCO, INPUT_PULLUP);    // BOTON
  pinMode(BOTON_ROJO, INPUT_PULLUP);      // BOTON
  pinMode(BOTON_AMARILLO, INPUT_PULLUP);  // BOTON

  // dejamos tiempo para que el monitor en 
  // serie se haga visible en modo desarrollo.
  soniditito();
  delay(2000);
}


void loop() {
  turno_de_maquina();
  marca_cambio_maquina_a_jugador();
  boolean ganado = turno_de_victor();
  sonido_final(ganado);
  delay(ESPERA_LARGA);
}