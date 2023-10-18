#ifndef SPI_H
#define SPI_H
#include "MKL25Z4.h"
#include <stdio.h>
#define SPI_C2_SP_MODE_MASK 0x00
void SPI_INCI();
void SPI_ENVI(uint8_t data);
uint8_t SPI_RECI();

#endif 
