# Laboratorio 3
Karen Rivera Angulo 

C09197

---
El presente laboratorio cuenta con tres ejercicios en los que se calculan potencias, se trabaja con matrices binarias y se realiza la toma de datos de sensores de temperatura.

La mayoría de las funciones se implementan mediante ciclos `for`, en los cuales se recorren los datos desde 0 hasta `n-1`. Con base en este recorrido, se realizan comparaciones de valores, toma de datos y cálculos utilizando condicionales `if`.

Los códigos mostrados corresponden a las funciones implementadas; sin embargo, no representan el código completo de cada ejercicio.

## Ejercicio 1
### Correción de error
El código que calcula potencias enteras presenta un problema dentro del ciclo `while`. En la línea `int exp = exp - 1;` se crea una nueva variable local llamada `exp` en lugar de modificar la variable original. Como consecuencia, el valor del exponente nunca cambia, la condición del `while` siempre permanece verdadera y el ciclo se vuelve infinito.

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

### Ingreso de variables por el usuario
Se genera el siguiente código para que el usuario pueda ingresar la base, validando que el número ingresado sea diferente de cero, y el exponente, verificando que el número sea mayor que cero.  

Estas validaciones se realizan mediante el uso del ciclo `do while`.

```C
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

    return 0;
}
```

En la siguiente imagen se puede observar el resultado del código anterior al digitar diferentes números confirmando que el código funciona correctamente.

![imagen](./imagen1.png)

### Verificación de si el resultado es par o impar
Por medio de la función `es_par(int n)` se verifica si el resultado obtenido es par o impar. Para ello, se divide el número entre dos y se comprueba si el residuo de la división es igual a cero.  

Si el residuo es cero, el número es par; en caso contrario, el número es impar, como se muestra en el siguiente código agregado.

```C
// Función para verificar si el resultado es par
int es_par(int n) {

    if (n % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
```
Después de imprimir el resultado, se utiliza una estructura condicional `if` para mostrar si el número obtenido es par o impar, según corresponda.

```C
    // Verifica si el resultado es par 
    if (es_par(potencia(base, exp))) { 
        printf("El resultado es par.\n");
    } else {
        printf("El resultado es impar.\n");
    }
```
Se prueban ambos casos para verificar el correcto funcionamiento del código.

![imagen2](./imagen2.png)



## Ejercicio 2
Se implementan cinco funciones para trabajar con una matriz binaria, cuyos elementos son únicamente 0 y 1.

### Contar unos en la fila y columna
Esta función se implementa mediante un ciclo `for` observado en el código, en el cual se recorre la matriz y se van sumando los valores cuando son iguales a 1.  

Este procedimiento es el mismo tanto para las filas como para las columnas de la matriz. En este caso, el recorrido se realiza específicamente sobre la fila 0 y la columna 0.

```C
// Contar cuantos unos hay en una fila
int contar_unos_fila(int m[][SIZE], int fila) {
    
    int i;
    int contador = 0;  //Inicia el contador en 0

    for (i = 0; i < SIZE; i++) {  //Recorre todos los números de la fila
        if (m[fila][i] == 1) { 
            contador ++;
        }
    }

    return contador;
}

```

### Identificar matriz identidad 
Para identificar si una matriz es identidad, se realiza un procedimiento similar al de contar unos en filas y columnas. Para esto se realiza primero el pseudocódigo.

```text
funcion es_identidad(matriz,n)

  for i desde 0 hasta n-1
    for j desde 0 hasta n-1
     
     if i == i=j entonces
        if matriz[i][j] != 1 entonces 
            devolver falso
        end if
    else
        if matriz[i][j] != 0 entonces
            devolver falso
        end if
    end for
  end for

  devolver verdadero

end funcion
```

Este se implementa mediante dos ciclos `for` que recorren las filas y las columnas, verificando si los valores en la diagonal principal son iguales a 1 y si los elementos restantes son iguales a 0.


```C
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
```

En la siguiente figura se pueden validar los resultados de las tres funciones mencionadas anteriormente, donde se cuentan los unos en la fila 0 y la columna 0, además de identificar si la matriz es identidad.  

Se realizó una pequeña modificación a la matriz ingresada para comprobar el correcto funcionamiento de las funciones.


![imagen3](./imagen3.png)

### Verifica si tiene una fila y columna completa de unos
Se genera el pseudocódigo de la función.

```text
funcion tiene_fila_completa(matriz, n)
    
    for i desde 0 hasta n-1

        completa -> verdadero

        for j desde 0 hasta n-1 

            if matriz[i][j] != 1 entonces
                completa -> falso
            end if
        end for

        if completa == verdadero entonces
            devuelve verdadero
        end if

    end for

    devuelve falso

end funcion
```


De forma similar, se aplican dos ciclos `for` para recorrer la matriz y verificar si existen unos en toda la fila.  

Esta misma función se repite para el caso de las columnas.

```C
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
```
En la siguiente figura se prueban las funciones modificando la matriz para obtener tres casos: no hay filas ni columnas completas de unos, existe una fila completa de unos y existe una columna completa de unos.  

Esto permite verificar que el código funciona correctamente sin importar la posición en la que se encuentre la fila o columna de unos.

![imagen4](./imagen4.png) 

### Generación de matriz aleatoria 
A continuación, se genera una matriz aleatoria utilizando `rand()%2`, la cual asigna a la variable `m2` valores aleatorios de 0 y 1 para cada elemento de la matriz.

Posteriormente, la matriz es impresa mediante dos ciclos `for`.

```C
int m2[SIZE][SIZE];

int i, j;

for (i = 0; i < SIZE; i++) { 
    for (j = 0; j < SIZE; j++) {
        m2[i][j] = rand() % 2;   //Genera matriz aleatoria
    }
}

    //Imprime matriz aleatoria
    printf("Matriz aleatoria:\n");

    for (i = 0; i < SIZE; i++) {

        for (j = 0; j < SIZE; j++) {

            printf("%d ", m2[i][j]);
        }

        printf("\n");
    }
```
Todas las funciones anteriores son utilizadas en el código para obtener los resultados de la matriz aleatoria. De este modo, los resultados para ambas matrices se muestran a continuación.

![imagen5](./imagen5.png)

En este caso, el código se compila y ejecuta dos veces para obtener matrices distintas, con lo cual se confirma nuevamente que las funciones implementadas funcionan correctamente al contar los unos.

### Prueba con diferentes tamaños de matrices 
Finalmente, se modifica el tamaño de las matrices para determinar si las funciones se implementan correctamente sin importar sus dimensiones. En este caso, se utilizan matrices de 2x2, 3x3 y 5x5. Además, el programa ya funcionaba correctamente con una matriz 4x4.

Dado que se utiliza la constante `SIZE` en cada función, el recorrido por las filas y columnas no se ve afectado por el tamaño de la matriz, lo que permite su reutilización para diferentes dimensiones.

![imagen6](./imagen6.png) 

## Ejercicio 3

### Clasificar estados de los sensores 
Con el siguiente código se clasifican los estados de acuerdo con los rangos establecidos, mediante el uso de condiciones `if` y `else`.


```C
/ Clasificar valores según los rangos
EstadoSensor clasificar (float valor) { 

    if (valor >= 40.0 && valor <= 60.0)
        return NORMAL;
    else if ((valor >=20.0 && valor < 40.0) || (valor <= 60.0 && valor > 80.0))
        return ALERTA;
    else 
        return FALLO;
}
```

### Lecturas del usuario
Seguidamente, se solicitan los datos del usuario por medio de ciclos `for`, los cuales imprimen las solicitudes de ingreso de datos y posteriormente muestran la tabla de resultados de acuerdo con la función mencionada anteriormente.


```C
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
```

En la siguiente figura se ingresan los ID y los valores de 10 sensores, donde se determina la clasificación correspondiente a cada estado.

El estado **Normal** corresponde a valores entre 40.0 y 60.0, **Alerta** a valores entre 20.0 y 40.0 o entre 60.0 y 80.0, y **Fallo** a valores menores que 20.0 o mayores que 80.0.

Los resultados se presentan en una tabla que muestra el ID, el valor registrado y el estado correspondiente de cada sensor.

![imagen7](./imagen7.png)

### Contar estados 
La función para contar estados inicia un contador en 0, el cual recorre los resultados y va sumando los estados según la clasificación realizada anteriormente.

```C
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
```
Nuevamente, se ingresan los datos de los sensores y el programa realiza el conteo de cuántos se encuentran en estado **Normal**, **Alerta** y **Fallo**, de acuerdo con los rangos implementados anteriormente.

![imagen8](./imagen8.png)


### Lectura del valor más alejado a 50.0 
Finalmente, se genera el código que sea capaz de leer el valor que se encuentre más alejado de 50.0 por medio de la función matemática `fabs` siendo el valor absoluto del número, que recorre los datos por medio de un ciclo `for` hasta encontrar el más alejado.

```C
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
```

En la siguiente figura se observan todas las funciones implementadas, con especial detalle en la función de lectura extrema, la cual encuentra el valor más alejado de 50.0 y muestra su ID y su valor correspondiente.

![imagen9](./imagen9.png)