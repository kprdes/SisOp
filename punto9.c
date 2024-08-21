#include <stdio.h>

// Función para verificar si un carácter es una letra minúscula
int esMinuscula(char c) {
    return (c >= 'a' && c <= 'z');
}

int main() {
    char ch;

    // Pedir al usuario un carácter
    printf("Ingrese un carácter: ");
    scanf("%c", &ch);

    // Verificar si el carácter es minúscula
    if (esMinuscula(ch)) {
        printf("%c es una letra minúscula.\n", ch);
    } else {
        printf("%c no es una letra minúscula.\n", ch);
    }

    return 0;
}
