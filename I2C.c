#include "MKL25Z4.h"
#include "I2C.h"

void protocoloiniciar(uint32_t baudrate) {
    
    SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    
    PORTB->PCR[0] = PORT_PCR_MUX(2); 
    PORTB->PCR[1] = PORT_PCR_MUX(2); 

    SIM->SCGC4 |= SIM_SCGC4_I2C0_MASK;
    I2C0->F = I2C_F_MULT(0) | I2C_F_ICR(baudrate); 
    I2C0->C1 |= I2C_C1_IICEN_MASK; 
}
void protocoloempezar() {

    I2C0->C1 |= I2C_C1_MST_MASK | I2C_C1_TX_MASK; 
}
void protocolofinalizar() {

    I2C0->C1 &= I2C_C1_MST_MASK; 
}
void protocoloescrito(uint8_t data) {
    I2C0->D = data; 
    while (!(I2C0->S & I2C_S_IICIF_MASK));
    
    I2C0->S |= I2C_S_IICIF_MASK; 

}
uint8_t protocololectura() {

    I2C0->C1 &= I2C_C1_TX_MASK; 

    while (!(I2C0->S & I2C_S_IICIF_MASK)); 
    
    I2C0->S |= I2C_S_IICIF_MASK; 

    return I2C0->D; 
}
