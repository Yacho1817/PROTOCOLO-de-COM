#include "MKL25Z4.h"
#include "UART.h"


void UART_iniciar(){
   
    SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;

    
    PORTA->PCR[1] = PORT_PCR_MUX(2); 
    PORTA->PCR[2] = PORT_PCR_MUX(2); 

    
    SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    UART0->C2 &= ~UART0_C2_TE_MASK & ~UART0_C2_RE_MASK; 
    UART0->BDH = 0x00; 
    UART0->BDL = 0x1A;
    UART0->C4 = 0x0F; 
    UART0->C1 = 0x00; 
    UART0->C3 = 0x00; 
    UART0->S2 = 0x00; 
    UART0->D = 0x00; 
    UART0->C2 = UART0_C2_TE_MASK | UART0_C2_RE_MASK; 
}

void UART_envio(uint8_t data) {
    
    while (!(UART0->S1 & UART0_S1_TDRE_MASK));

    
    UART0->D = data;
}

uint8_t UART_recibir() {
    
    while (!(UART0->S1 & UART0_S1_RDRF_MASK));

    
    return UART0->D;
}
