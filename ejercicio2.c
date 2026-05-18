#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

int contar_unos_fila(int m[][SIZE], int fila);
int contar_unos_columna(int m[][SIZE], int col);
int es_identidad(int m [][SIZE]);
int tiene_fila_completa(int m[][SIZE]);
int tiene_columna_completa(int m[][SIZE]);

int main(void) {
    int m[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0 ,0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int i, j;

    printf("Matriz ingresada:\n");

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    printf("Unos en la fila: %d\n", contar_unos_fila(m, 0));
    printf("Unos en la columna: %d\n", contar_unos_columna(m, 1));

    if (es_identidad(m)) {
        printf("Es matriz identidad: si\n");
    } else {
        printf("Es matriz identidad: no\n");
    }

    return 0;

}


// Contar cuantos unos hay en una fila
int contar_unos_fila(int m[][SIZE], int fila) {
    
    int i;
    int contador = 0;  //Inicia el contador en 0

    for (i = 0; i < SIZE; i++) {  //Recorre todas la columnas de la fila
        if (m[fila][i] == 1) { 
            contador ++;
        }
    }

    return contador;
}

// Contar cuantos unos hay en una columna, se repite el proceso
int contar_unos_columna(int m[][SIZE], int col) {
    
    int i;
    int contador = 0;  //Inicia el contador en 0

    for (i = 0; i < SIZE; i++) {
        if (m[i][col] == 1) { 
            contador ++;
        }
    }

    return contador;
}

// Verifica si la matriz es identidad
int es_identidad(int m[][SIZE]) {

    int i, j;

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            // Diagonal
            if (i == j) {

                if (m[i][j] != 1) {
                    return 0;
                }

            } else {

                // Numeros fuera de la diagonal
                if (m[i][j] != 0) {
                    return 0;
                }
            }
        }
    }

    return 1;
}