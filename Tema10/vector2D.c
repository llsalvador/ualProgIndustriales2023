#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NF (7*2)
#define NC  (12)

int main(int argc, char*argv[]){
    float temp[NF][NC];
    time_t t;

    srand((unsigned)time(&t));
    for(int i=0; i<NF; ++i)
        for(int j=0; j<NC; ++j)
            temp[i][j] = -7 + (25+7)*1.0*rand()/RAND_MAX;

    for(int i=0; i<NF; ++i){
        printf("m[%2i][1..%i]=[", i, NC);
        for(int j=0; j<NC; ++j){
            printf("%6.1f", temp[i][j]);
            if(j != NC-1) printf(", ");
            else printf("]\n");
        }
    }

    for(int i=0; i<NF; ++i){
        for(int j=0; j<NC; ++j){
            printf("m[%d,%d]= %.1f", i, j, temp[i][j]);
        }
    }
    printf("\n");

    return 0;
}