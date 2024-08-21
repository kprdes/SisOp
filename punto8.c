#include <stdio.h>

// Función para verificar si un carácter es una letra mayúscula
int esMayuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

int main() {
    char ch;

    // Pedir al usuario un carácter
    printf("Ingrese un carácter: ");
    scanf("%c", &ch);

    // Verificar si el carácter es mayúscula
    if (esMayuscula(ch)) {
        printf("%c es una letra mayúscula.\n", ch);
    } else {
        printf("%c no es una letra mayúscula.\n", ch);
    }

    return 0;
}
