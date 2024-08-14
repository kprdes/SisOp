#include <stdio.h>
#include <stdlib.h>

//funcion que evalua si un año es bisiesto
//permite que se haga multiples veces por ejecucion
//Es bisiesto si es divisible por 4 y no por 100 o si es divisible por 400
int factorial(int n){
    if(n >= 1){
        return n * factorial(n - 1);
    }
    else{
        return 1;
    }
}

int main(){
    //Valor a evaluar
    int y = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Compute factorial of a number\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){

        if(input == 1){
            printf("Enter the number: \n");
            scanf("%d", &y);

            //Se puede calcular el factorial de enteros positivos unicamente
            if( y < 0){
                printf("Value must be equal or greater than 0.\n");
            }
            else{
                printf("The result of %d! is: %d\n\n", y, factorial(y));
            }
        }
        else{
            //entrada invalida
            printf("Invalid input, try again.\n\n");
        }

        printf("Options: \n1.Compute factorial of a number\n2.Exit\n");
        scanf("%d", &input);
    }

}