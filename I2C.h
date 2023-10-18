#ifndef I2C_H
#define I2C_H
#include "MKL25Z4.h"
#include <stdio.h>


void protocoloiniciar(uint32_t baudrate);
void protocoloempezar();
void protocolofinalizar();
void protocloescrito(uint8_t data);
uint8_t protocololectura();

#endif


