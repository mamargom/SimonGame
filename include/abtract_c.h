#include <Arduino.h>


#define REPETIR(numero_veces) for (int vez = 0; vez < numero_veces; vez++)
#define MIENTRAS(condicion) while (condicion)
#define SI(condicion) if (condicion)
#define SINO else

void repetir(int veces, void (*func)()) {
    for (int i = 0; i < veces; i++) {
        func();
    }
}

void mientras(bool (*condicion)(), void (*func)()) {
    while (condicion()) {
        func();
    }
}

void mientras(bool condicion, void (*func)()) {
    while (condicion) {
        func();
    }
}

void para_cada_pin(size_t array[] , void (*func)(int)) {
    size_t NumberOfElements = sizeof(array)/sizeof(array[0]);
    for (size_t i = 0; i < NumberOfElements; i++) {
        func(array[i]);
    }
}


void enciende_led(uint8_t pin) {
    digitalWrite(pin, HIGH);
}

int lee_boton (uint8_t pin) {
    return digitalRead(pin);
}

bool boton_apretado (uint8_t pin) {
    return digitalRead(pin) == LOW;
}

bool boton_suelto (uint8_t pin) {
    return not boton_apretado(pin);
}
