#include <stdio.h>

int main(){
    int m[10][10];

    m[1][1] = 11;
    printf("El valor es: %i\n",*(*(m+1)+1));

    return 0;
}