#include "MKL25Z4.h"
#include "SPI.h"

void SPI_INIC() {

    PORTC->PCR[4] = PORT_PCR_MUX(0x02); 
    PORTC->PCR[5] = PORT_PCR_MUX(0x02); 
    PORTC->PCR[6] = PORT_PCR_MUX(0x02); 
    PORTC->PCR[7] = PORT_PCR_MUX(0x02); 

    SPI0->C1 = 0x00; 
    SPI0->C2 = SPI_C2_SP_MODE_MASK | SPI_C2_MODFEN_MASK;

    SPI0->BR = 0x01; 
    SPI0->C1 |= SPI_C1_SPE_MASK;
}

void SPI_ENVI(uint8_t data) {
    
    while (!(SPI0->S & SPI_S_SPTEF_MASK));
    SPI0->D = data;
}

uint8_t SPI_RECI() {
    while (!(SPI0->S & SPI_S_SPRF_MASK));
    return SPI0->D;
}
