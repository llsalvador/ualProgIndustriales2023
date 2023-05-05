#include <stdio.h>

union ADC{
    unsigned valor;
    struct ADC_CR1 {
    unsigned AWDCH:5;
    unsigned EOCIE:1;
    unsigned AWDIE:1;
    unsigned JEOCIE:1;
    unsigned SCAN:1;
    unsigned AWDSGL:1;
    unsigned JAUTO:1;
    unsigned DISCEN:1;
    unsigned JDISCEN:1;
    unsigned DISCNUM:3;
    unsigned RESERV:6;
    unsigned JAWDEN:1;
    unsigned AWDEN:1;
    unsigned RES:2;
    unsigned OVRIE:1;
    unsigned RESERV1:5;
}registro;} adc1,adc2,adc3;


void escribeBinario(unsigned ancho, unsigned valor);


int main(){
    escribeBinario(32, adc1.valor);
    printf("\n");
    adc1.registro.AWDCH = 5;
    printf("%X\n", adc1.valor);
    escribeBinario(32, adc1.valor);
    printf("\n");

    return 0;
}

void escribeBinario(unsigned ancho, unsigned valor){
    if(ancho > 32) printf("Se escriben los primeros 32 bits (%u).\n", ancho);
    for(int i=(ancho>32?32:ancho); i ; --i){
        if(i && i % 8 == 0) printf(" ");
        printf("%u", (valor & 0x80000000?1:0));
        valor <<= 1;
    }
}