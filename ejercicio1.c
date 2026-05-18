#include <stdio.h>

// Calcular potencia
int potencia(int base, int exp) { 
    int resultado = 1;

    while (exp > 0) {
        resultado = resultado * base;
        exp = exp - 1;     // Se elimina el int que generaba una nueva variable
    }
    return resultado;
}

// Función para verificar si el resultado es par
int es_par(int n) {

    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

//Ingresar variables e imprimir resultados
int main(void){ 
    int base, exp;
 
    // Ingresar y validar base distinta de cero
    do {
        printf("Ingrese la base de la potencia: ");
        scanf("%d", &base);
        
        if (base == 0) { 
        printf("Número inválido, la base debe ser diferente de cero. ");
        }
    } while (base == 0);

    // Ingresar y validar exponente mayor a cero
    do {
        printf("Ingrese el exponente de la potencia: ");
        scanf("%d", &exp);

        if (exp < 0) {
            printf("Número inválido, el exponente debe ser mayor a cero. ");
        }

    } while (exp < 0);
   
    // Imprime el resultado de la potencia
    printf("%d^%d = %d\n", base, exp, potencia(base, exp));

    // Verifica si el resultado es par 
    if (es_par(potencia(base, exp))) { 
        printf("El resultado es par.\n");
    } else {
        printf("El resultado es impar.\n");
    }

    return 0;
}

