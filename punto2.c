#include <stdio.h>
#include <stdlib.h>

char* isPrime(int n){
    int i = n - 1;
    while(i > 1){
        if(n % i-- == 0){
            return "isn't prime.\n\n";
        }
    }

    return "is prime.\n\n";
}

int main(){
    //Entero a evaluar
    int n = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Check for primes\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){

        if(input == 1){
            printf("Enter a positive integer: \n");
            scanf("%d", &n);
            system("cls");

            //Los numeros primos deben ser mayores a uno
            if( n <= 0){
                printf("Value must be greater than 0.\n");
            }
            else{
                printf("%d %s", n, isPrime(n));
            }
        }
        else{
            //entrada invalida
            printf("Invalid input, try again.\n");
        }

        printf("Options: \n1.Check for primes\n2.Exit\n");
        scanf("%d", &input);
    }

}