#include <stdio.h>
#include <math.h>


int main(){
    int precision;
    float n, raiz, incremento = 1;

     do{
        printf("Escribe la precisión (positivo <= 7):\n");
        scanf("%i", &precision);
    }while(precision <= 0 || precision > 7);
    do{
        printf("Escribe la raiz (positiva):\n");
        scanf("%f", &n);
    }while(n <= 0);
    
    raiz = 0;//Inicialización.
    while(precision){
        if(raiz*raiz*raiz*raiz < n)
            raiz += incremento;
        else if(raiz*raiz*raiz*raiz > n){
                raiz -= incremento;
                incremento /= 10;
                if(incremento < 0.1)
                    precision--;
            }
    }
    printf("La raiz cuarta calculada de %f (%f) es %f y la exacta %.10lf\n", n, raiz*raiz*raiz*raiz, raiz, sqrt(sqrt(n)));

    return 0;
    }
