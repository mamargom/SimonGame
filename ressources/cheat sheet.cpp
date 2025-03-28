#include <Arduino.h>

/* *************************************************
    DEFINE VARIABLES Y TIPOS DE DATOS (INFORMACION)
**************************************************** */

/* 
Numeros sin decimales
*/
// uint8_t -> numero 0..255
uint8_t  numero_corto;
uint8_t  numero_corto_iniciado = 5;

// int8_t -> numero -128..127
int8_t  numero1;

// uint16_t -> numero 0..65,535
uint16_t  numero2;

// int16_t -> numero -32,768 a 32,767
int16_t  numero3;

// uint32_t -> numero 0 .. 4,294,967,295
uint32_t  numero4;

// int32_t -> numero -2,147,483,648 .. 2,147,483,647
int32_t  numero4;

/* 
Numeros con decimales
*/
// float 32bits -> ±1.17549×10⁻³⁸ ..  ±3.40282×10³⁸ (aprox.)
float numero5 = -12.53;

/* 
Define constantes (El valor se define y NO se puede cambiar)
*/
#define NUMERO_DE_BOTONES 4

/* 
Texto
*/
char letra = 'a';
char texto[] = "Hola Víctor";

/*
Booleanos TRUE/FALSE
*/

bool cierto = true;
bool falso = false;



/* *****************************************************
    FIN DE DEFINE VARIABLES Y TIPOS DE DATOS (INFORMACION)
********************************************************** */

/* *************************************************
    DEFINE VECTORES (CAJONES)
**************************************************** */

// Define un vector (4 cajitas : 0,1,2,3)
uint8_t pines_de_leds[4] = {8,6,7,5};
uint8_t pines_de_botones[NUMERO_DE_BOTONES] = {12,13,14,15};

// tengo que definir una funcion para usarlo
void vectores () {
    
    // lee datos de un vector -> lee posicion 0
    uint8_t pin1 = pines_de_leds[0];

    // asigna datos a un vector -> posicion 1
    pines_de_leds[1] = 12;

}

/* *************************************************
    FIN DE DEFINE VECTORES (CAJONES)
**************************************************** */




/* *************************************************
    DEFINE FUNCIONES (CAJITA DE CERILLAS)
**************************************************** */
// Esta funcion no devuelve nada "void"
void escribe_boton_apretado() {
    char mensaje_de_boton_apretado[] = "Boton apretado...";
    Serial.println(mensaje_de_boton_apretado);
}

// Esta funcion devuelve un número
uint8_t numero_de_boton_apretado() {
    
    uint8_t numero_boton;
    // Mas código aquí
    // por ejemplo:
    // numero_boton = espera_boton_apretado();
    // devuelve numero_boton
    return  numero_boton;
}

// funcion con parametros
void escribe_numero_de_boton_apretado(uint8_t boton, char mensaje[]) {
    
    escribe_boton_apretado();
    Serial.println(mensaje);
    Serial.println(boton);
}

/* *************************************************
    FIN DE DEFINE FUNCIONES (CAJITA DE CERILLAS)
**************************************************** */



/* *************************************************
    OPERADORES
**************************************************** */
void operadores_y_asignacion() {

    // ==, +, - , <, <=, >=


    3+4;
    1==1;
    3<5; 
    5<=5; 
    5>5; 
    5>=5; 

    // =

    bool resultado;
    uint8_t multiplicacion;
    resultado = 3<5;
    multiplicacion = 3 * 4;
    multiplicacion = multiplicacion + 10;


}


/* *************************************************
    BUCLES Y CONTROL DE FLUJO
**************************************************** */

void bucles_y_control() {

    uint8_t contador = 5;


    // Que hacer si una condicion es cierta.
    // por ejemplo contador == 5. Usa "==" y no "="
    if (contador == 5)
    {
        /* code */
    } 
    else if (contador == 0) 
    {
        /* code */
    } 
    else 
    {
        /* code */
    }
    
    


    // mientra condicion es cierta (== true)
    // while (condicion == true) 

    // repite sin parar porque 1 es siempre 1 
    while (1)
    {
        /* code */
    }

    // repite 5 veces
    while (contador > 0)
    {
        // haz algo -> código aquí
        
        contador = contador - 1;
    }

    // repite 4 veces
    for (uint8_t i = 0; i < NUMERO_DE_BOTONES; i++)
    {
        // haz algo -> código aquí
    }
    

}
 

/* *************************************************
    FIN DE BUCLES Y CONTROL DE FLUJO
**************************************************** */



/* *************************************************
    FUNCIONES ÚTILES ARDUINO
**************************************************** */
void funciones_utiles() {
    
    uint32_t milisegundos;

    // escribe en en pin 12 un pin (HIGH/LOW)
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    
    // espera tantos milisegundos
    delay(milisegundos);

    // lee el valor del pin 8
    uint8_t valor_leido_pin = digitalRead(8);

}

/* *************************************************
    FIN DE FUNCIONES ÚTILES ARDUINO
**************************************************** */



/* *************************************************
    PRIPIO DE ARDUINO
**************************************************** */




void setup() {
    // Lo ejecuta una sola vez, cuando el programa arranca.
    // Lo utilizas para configurar pines, etc.
 
    // codigo aqui....

    // Activa consola para poder escribir (salida al ordenador)
    Serial.begin(9600);
	Serial.println("Serial set up -> OK");
}


void loop() {
    // Despues de ejecutar setup() repite lo que hay 
    // en esta funcion loop () todo el tiempo.

    // codigo aqui.
  }

/* *************************************************
    PRIPIO DE ARDUINO
**************************************************** */
