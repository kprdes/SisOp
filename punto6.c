#include <stdio.h>

int main() {
    int n, i;
    
    // Pedir el numero de elementos para comprobar
    printf("Ingresa el numero de elementos a ingresar: ");
    scanf("%d", &n);

    int array[n];

    // Registrar los inputs
    printf("Ingresa %d enteros (Con un salto de linea):\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Separar y mostrar los pares
    printf("Numeros pares:\n");
    for(i = 0; i < n; i++) {
        if(array[i] % 2 == 0) {
            printf("%d ", array[i]);
        }
    }

    // Separar y mostrar los impares
    printf("\nNumeros impares:\n");
    for(i = 0; i < n; i++) {
        if(array[i] % 2 != 0) {
            printf("%d ", array[i]);
        }
    }

    return 0;
}
