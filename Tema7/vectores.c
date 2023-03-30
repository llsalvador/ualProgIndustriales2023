int main(){
    double temp[5];

    for(int i=0; i < 5; ++i){
        printf("\nPon la temperatura %i ", i);
        scanf("%lf", temp + i);
    }

    for(int i=0; i < 5; ++i){
        printf("\nLa temperatura %i es %lf", i, temp[i]);
    }
    printf("\n");


    return 0;
}