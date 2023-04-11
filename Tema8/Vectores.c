#include <stdio.h>


int main(  ){
    const unsigned Max = 10;
    float vector[Max];
    float inicializado[] = {0.0,1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9};
    float *v, *ini;

    printf("Primera salida.\n");
    for(int i=0; i<Max; ++i){
        printf("Valor %i para inicializado (%.2f) y sin (%.2f).\n", i,
            inicializado[i], vector[i]);
    }
    printf("Segunda salida.\n");
    v = vector;
    ini = inicializado;
    for(int i=0; i<Max; ++i){
        printf("Valor %i para inicializado (%.2f) y sin (%.2f).\n", i,
            *ini++, *v++);
    }
    printf("Tercera salida.\n");
    v = vector;
    ini = inicializado;
    for(int i=0; i<Max; ++i){
        printf("Valor %i para inicializado (%.2f) y sin (%.2f).\n", i,
            *ini+i, *v+i);
    }
    printf("Cuarta salida.\n");
    v = vector;
    ini = inicializado;
    for(int i=0; i<Max; ++i){
        printf("Valor %i para inicializado (%.2f) y sin (%.2f).\n", i,
            *(ini+i), *(v+i));
    }

    /**********************INTRODUCCIÓN DE DATOS**********************************/
    for(int i=0; i<Max; ++i){
        printf("Pon el valor vector[%i]: ", i);
        scanf("%f", vector + i);
    }

    for(int i=0; i<Max; ++i){
        printf("Valor %i para vector (%.2f).\n", i, vector[i]);
    }
   
    return 0;
}