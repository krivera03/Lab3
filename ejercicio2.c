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
        {1, 1, 0 ,0},
        {1, 0, 1, 0},
        {1, 0, 0, 1}
    };

    int i, j;

    printf("Matriz ingresada:\n");  //Imprime matriz ingresada

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            printf("%d ", m[i][j]);
        }

        printf("\n");
    }

    //Imprime la cuenta de unos en la fila 1, columna 1
    printf("Unos en la fila: %d\n", contar_unos_fila(m, 0));
    printf("Unos en la columna: %d\n", contar_unos_columna(m, 1));

    // Imprime si la matriz es identidad
    if (es_identidad(m)) {
        printf("Es matriz identidad: si\n");
    } else {
        printf("Es matriz identidad: no\n");
    }

    // Imprime si tiene una fila completa de unos
    if (tiene_fila_completa(m)) {
        printf("Tiene fila completa de unos: si\n");
    } else {
        printf("Tiene fila completa de unos: no\n");
    }

    // Imprime si tiene una columna completa de unos
    if (tiene_columna_completa(m)) {
        printf("Tiene columna completa de unos: si\n");
    } else {
        printf("Tiene columna completa de unos: no\n");
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


// Verifica si hay una fila completa de unos
int tiene_fila_completa(int m[][SIZE]) {

    int i, j;
    int completa;

    for (i = 0; i < SIZE; i++) {

        completa = 1;

        for (j = 0; j < SIZE; j++) {

            if (m[i][j] != 1) {
                completa = 0;
            }
        }

        if (completa == 1) {
            return 1;
        }
    }

    return 0;
}

//Verifica si tiene una columna completa de unos
int tiene_columna_completa(int m[][SIZE]) {

    int i, j;
    int completa;

    for (j = 0; j < SIZE; j++) {

        completa = 1;

        for (i = 0; i < SIZE; i++) {

            if (m[i][j] != 1) {
                completa = 0;
            }
        }

        if (completa == 1) {
            return 1;
        }
    }

    return 0;
}