#include <stdio.h>

int main(){
    int base, exp;

    do {
        printf("Ingrese la base de la potencia: ");
        scanf("%d\n", &base);

    } while (base == 0);
        printf("Número inválido. Ingrese una base diferente de cero: ")
        scanf("%d\n", &base)

    do {
        printf("Ingrese el exponente de la potencia: ")
        scanf("%d\n", &exp)

    } while (exp > 0);
        printf("Número inválido. Ingrese un exponente positivo: ")
        scanf("%d\n", &exp)

    return 0;
}

int potencia(base, exp) {
    int resultado = 1;
    while (exp > 0) {
        resultado = resultado * base;
        exp = exp - 1;     // Se elimina el int que generaba una nueva variable
    }
    return resultado;
}

int main(void) {
    printf("%d\n^%d\n = %d\n", base, exp, resultado);
    return 0;
}