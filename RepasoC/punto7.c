#include <stdio.h>

int main() {
    int n, i, siguienteTermino, t1, t2;
    t1 = 0;
    t2 = 1;

    // Pregunta al usuario cuántos términos de la serie de Fibonacci quiere
    printf("Ingrese el número de términos: ");
    scanf("%d", &n);

    printf("Serie de Fibonacci: ");

    for (i = 1; i <= n; i++) {
        printf("%d ", t1);
        siguienteTermino = t1 + t2;
        t1 = t2;
        t2 = siguienteTermino;
    }

    return 0;
}
