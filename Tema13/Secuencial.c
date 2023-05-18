#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MaxDatos    100
typedef double Estructura;
typedef struct 
{
    char nombre[30], apellido1[30], apellido2[30], cp[6];
} Estructura1;


int escribeFichero(char *nombre, Estructura datos[], unsigned cantidad);
int leeFichero(char *nombre, Estructura datos[], unsigned cantidad);
int escribeBinario(char *nombre, Estructura datos[], unsigned cantidad);
Estructura leeBinario(char *nombre, Estructura *dato, unsigned posicion);

int main(){
    Estructura datos[MaxDatos], d;
    time_t t;

    srand((unsigned)time(&t));//Inicialización.

    for(int i=0; i < MaxDatos; ++i)
        datos[i] = (100 + 100)*1.0*rand()/RAND_MAX -100.0;
    /*printf("Se han escrito %i reales.\n", escribeFichero("datos.txt", datos, MaxDatos));
    printf("Se han leido %i reales.\n", leeFichero("datos.txt", datos, MaxDatos));*/
    printf("Se han escrito %i reales.\n", escribeBinario("datos.txt", datos, MaxDatos));
    printf("El valor escrito es %.10lf y el original es %.10lf\n", leeBinario("datos.txt", &d, 33), datos[33]);
    
    Estructura1 e1;
    strcpy(e1.nombre, "Pepe");
    strcpy(e1.apellido1, "Gotera");
    strcpy(e1.apellido2, "Otilio");
    strcpy(e1.cp, "04001");
    FILE *f;
    f = fopen("datos1.txt", "w+");
    fprintf(f, "%s;%s;%s,%s\n", e1.nombre, e1.apellido1, e1.apellido2, e1.cp);
    fclose(f);

    return 0;
}

int escribeFichero(char *nombre, Estructura datos[], unsigned cantidad){
    FILE *f;
    int i = 0, escritos = 1;

    f = fopen(nombre, "w+");
    while(i < cantidad && escritos != -1){
        escritos = fprintf(f, "%8.3lf;%10.3lf\n", datos[i], datos[i]*datos[i]);
        i++;
    }
    fclose(f);
    if(i == cantidad)
        return i;

return 0;
}

int escribeBinario(char *nombre, Estructura datos[], unsigned cantidad){
    FILE *f;
    int i = 0, escritos = 1;

    f = fopen(nombre, "w+");
    while(i < cantidad && escritos != -1){
        escritos = fwrite(datos + i, sizeof(datos[0]), 1, f);
        i++;
    }
    fclose(f);
    if(i == cantidad)
        return i;

return 0;
}

int leeFichero(char *nombre, Estructura datos[], unsigned cantidad){
    FILE *f;
    int i = 0, escritos = 1;

    f = fopen(nombre, "r");
    while(i < cantidad && escritos != -1 && !feof(f)){
        double d;
        escritos = fscanf(f, "%lf;%lf\n", &datos[i], &d);
        i++;
    }
    if(feof(f))
        printf("Se ha llegado al final del fichero %s.\n", nombre);
    else printf("No se ha llegado al final del fichero %s.\n", nombre);
    fclose(f);

    return i;
}

Estructura leeBinario(char *nombre, Estructura *dato, unsigned posicion){
    FILE *f;
    int i = 0, escritos = 1;

    f = fopen(nombre, "r");
    fseek(f, posicion * sizeof(Estructura), SEEK_SET);
    fread(dato, sizeof(Estructura), 1, f);
    fclose(f);

    return *dato;
}
