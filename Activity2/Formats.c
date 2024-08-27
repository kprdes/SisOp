#include <stdio.h>

// This function will print the numbers 1 to 10 in octal format
void octal(int array[]) {
    printf("Octal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%o ", array[i]);  
    }
    printf("\n");
}

// This function will print the numbers 1 to 10 in decimal format
void decimal(int array[]) {
    printf("Decimal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", array[i]);  
    }
    printf("\n");
}

// This function will print the numbers 1 to 10 in hexadecimal format
void hexadecimal(int array[]) {
    printf("Hexadecimal:\n");
    for (int i = 0; i < 10; i++) {
        printf("%X ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    decimal(array);
    octal(array);
    hexadecimal(array);
    
    return 0;
}
