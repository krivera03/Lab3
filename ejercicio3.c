#include <stdio.h>
#define MAX_SENSORES 10

typedef enum { NORMAL, ALERTA, FALLO} EstadoSensor;

// Lectura del sensor
typedef struct
{
    int id;
    float valor;
    EstadoSensor estado;  //Clasifica utilizando el enum
} Lectura;

// Clasificar valores según los rangos
EstadoSensor clasificar (float valor) { 

    if (valor >= 40.0 && valor <= 60.0)
        return NORMAL;
    else if ((valor >=20.0 && valor < 40.0) || (valor <= 60.0 && valor > 80.0))
        return ALERTA;
    else 
        return FALLO;
}
    
//Imprimir estado de los sensores
void imprimir_estado(EstadoSensor e){
    if (e == NORMAL) 
        printf("Normal");
    else if (e == ALERTA) 
        printf("Alerta");
    else 
        printf("Fallo");
}

int main(void){

    return 0;
}

//int     contar_estado(Lectura s [] , int n, EstadoSensor e);
//int     lectura_extrema(Lectura s[] , int n);

