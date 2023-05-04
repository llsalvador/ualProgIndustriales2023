#include <stdio.h>

union ADC{
    unsigned valor;
    struct RADC{
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
    } registro;
};

struct Coordenadas{
    char tipo;
    union 
    {
        /* data */
        struct Polar
        {
            /* data */
            double modulo, angulo;
        } polar;

        struct Cartesiana
        {
            /* data */
            double x,y;
        } cartesiana;
        
        
    } datos;
    
} datos1,datos2;

void binario32(unsigned valor);

int main(){
    union ADC adc1,adc2;

    //adc1.valor = *(unsigned*)(0x34);
    adc1.registro.AWDCH = 7;
    adc1.registro.RESERV1 = 13;
    printf("El valor almacenado es 0x%08X\n", adc1.valor);
    binario32(adc1.valor);
    printf("\n");
    binario32((13<<27));
    printf("\n");
    adc2.registro.RESERV = 3;
    adc2.registro.DISCNUM = 8;
    binario32(adc2.valor);
    printf("\n");
    adc1.registro.DISCEN = 1;
    if(adc1.registro.DISCEN)
        printf("Se ha activado DISCEN\n");
    else
        printf("NO se ha activado DISCEN\n");

    datos1.tipo = 'p';
    datos1.datos.polar.modulo = 25;
    datos1.datos.polar.angulo = 90;
    printf("El tamaño de la estructura es de %u\n", (unsigned)sizeof(datos1));

    return 0;

}

void binario32(unsigned valor){
    for(int i = 32; i; --i){
        if(i && i % 8 == 0)
            printf(" ");
        printf("%u", (valor & 0x80000000?1:0));
        valor <<= 1;
    }
}
