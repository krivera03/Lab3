# Laboratorio 3
Karen Rivera Angulo 

C09197

---

## Ejercicio 1
### Correción de error
El código que calcula potencias enteras tiene un problema dentro del `while` en `int exp = exp -1;` que genera una nueva variable local y no la modifica entonces el `exp` nunca cambia y el ciclo se vuelve infinito. 

```C
#include <stdio.h>

int potencia(int base, int exp) {
    int resultado = 1;
    while (exp > 0) {
        resultado = resultado * base;
        int exp = exp - 1;     // Error en el código al generar una nueva variable
    }
    return resultado;
}

int main(void) {
    printf("2^8 = %d\n", potencia(2, 8));
    printf("3^4 = %d\n", potencia(3, 4));
    return 0;
}
```


## Ejercicio 2

## Ejercicio 3