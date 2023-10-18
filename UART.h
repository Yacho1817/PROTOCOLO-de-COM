
#ifndef UART_H
#define UART_H
#include "MKL25Z4.h"
#include <stdio.h>
#define UART0_C2_TE_MASK   0x08
#define UART0_C2_RE_MASK   0x04
#define UART0_S1_TDRE_MASK 0x80
#define UART0_S1_RDRF_MASK 0x20
#define SIM_SCGC4_UART0_MASK 0x4000000u
#define SIM_SCGC5_PORTA_MASK 0x200u

void UART_iniciar();
void UART_envio(uint8_t data);
uint8_t UART_recibir();

#endif
