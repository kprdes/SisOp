#include <stdio.h>

// Función para encontrar el mayor de tres números
int mayorDeTres(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    } else if (b >= a && b >= c) {
        return b;
    } else {
        return c;
    }
}

int main() {
    int num1, num2, num3, mayor;

    // Pedir al usuario tres números
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    printf("Ingrese el tercer número: ");
    scanf("%d", &num3);

    // Encontrar el mayor de los tres números
    mayor = mayorDeTres(num1, num2, num3);

    // Mostrar el resultado
    printf("El mayor de los tres números es: %d\n", mayor);

    return 0;
}
