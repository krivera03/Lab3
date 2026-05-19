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

        Lectura s[MAX_SENSORES];
        int n = MAX_SENSORES;

        //Lecturas del usuario
        for (int i = 0; i < n; i++){
            printf("Ingrese el ID del sensor %d: ", i + 1);
            scanf("%d", &s[i].id);

            printf("Ingrese el valor del sensor %d: ", i + 1);
            scanf("%f", &s[i].valor);

            //Clasificar 
            s[i].estado = clasificar(s[i].valor);
        }

        //Tabla de resultado
        printf("\n--- Tabla de Lecturas ---\n");
        printf("ID\tValor\tEstado\n");

        for (int i = 0; i < n; i++){
            printf("%d\t%.2f\t", s[i].id, s[i].valor);
            imprimir_estado(s[i].estado);
            printf("\n");
        }
    
    return 0;
}




//int     contar_estado(Lectura s [] , int n, EstadoSensor e);
//int     lectura_extrema(Lectura s[] , int n);

