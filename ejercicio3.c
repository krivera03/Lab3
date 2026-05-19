#include <stdio.h>
#include <math.h>


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

//Contar estados 
int contar_estado(Lectura s [] , int n, EstadoSensor e){
    int contador = 0;

    for (int i = 0; i < n; i++){
        if (s[i].estado == e) {
            contador ++;
        }
    }
    return contador;
}

//Lectura extrema
int     lectura_extrema(Lectura s[], int n) {  

    int idx = 0;
    float max_distancia = fabs(s[0].valor - 50.0);

    for (int i = 1; i < n; i++){
        float distancia = fabs(s[i].valor - 50.0);

        if (distancia > max_distancia) {
            max_distancia = distancia;
            idx = i;
        }
    }
    return idx;
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
        printf("\n Tabla de Lecturas \n");
        printf("ID\tValor\tEstado\n");

        for (int i = 0; i < n; i++){
            printf("%d\t%.2f\t", s[i].id, s[i].valor);
            imprimir_estado(s[i].estado);
            printf("\n");
        }

        //Conteo de estados
        printf("\n Conteo de Estados \n");
        printf("Normal: %d\n", contar_estado(s, n, NORMAL));
        printf("Alerta: %d\n", contar_estado(s, n, ALERTA));
        printf("Fallo: %d\n", contar_estado(s, n, FALLO));

        //Lectura extrema
        int idx = lectura_extrema(s, n);

        printf("\n Lectura del Valor Más Alejado de 50.0 \n");
        printf("ID: %d\n", s[idx].id);
        printf("Valor: %.2f\n", s[idx].valor);
    
    return 0;
}





