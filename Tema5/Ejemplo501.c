#include <stdio.h>

int main(){


for(int i = 0; i < 10; ++i){
    for(int j = 0; j < 10; ++j){
        if(!i)
            if(!j)
                printf("*");
            else
                printf("%4i", j);    
        else if(!j)
                printf("%i", i);
            else if(j < i)
                    printf("    ");
                else
                    printf("%4i", i*j);
    }
    printf("\n");
}

char a = getchar();
return 0;
}