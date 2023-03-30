#include <stdio.h>

int main(){
    float a, *p;

    a = -4.55;
    p = &a;

    printf("Resultado del ejercicio 6.14\n");
    printf("a = %.2f\n", a);
    printf("p = %p\n", p);
    printf("*p = %.2f\n", *p);
    printf("&a = %p\n", &a);
    printf("&*p = %p\n", &*p);
    printf("&p = %p\n", &p);
    //printf("*a = %f\n", *a);
    printf("*(&a) = %.2f\n", *(&a));

    return 0;
}