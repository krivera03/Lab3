#include <stdio.h>

int potencia(int base, int exp) {
    int resultado = 1;
    while (exp > 0) {
        resultado = resultado * base;
        int exp = exp - 1;
    }
    return resultado;
}

int main(void) {
    printf("2^8 = %d\n", potencia(2, 8));
    printf("3^4 = %d\n", potencia(3, 4));
    return 0;
}