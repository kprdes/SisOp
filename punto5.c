#include <stdio.h>
#include <stdlib.h>

//funcion que evalua si un año es bisiesto
//permite que se haga multiples veces por ejecucion
//Es bisiesto si es divisible por 4 y no por 100 o si es divisible por 400
int power(int n, int p){
    if(p >= 1){
        return n * power(n, p - 1);
    }
    else{
        return 1;
    }
}

int main(){
    //Valor a elevar
    int y = 0;
    //Potencia
    int p = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Compute power\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){

        if(input == 1){
            printf("Enter the number: \n");
            scanf("%d", &y);
            system("cls");
            printf("Enter the power: \n");
            scanf("%d", &p);
            system("cls");
            //Solo se pueden potencias positivas por la recursion
            if( p < 0){
                printf("Power must be equal or greater than 0.\n");
            }
            else{
                printf("%d to the power of %d is: %d\n\n", y, p, power(y, p));
            }
        }
        else{
            //entrada invalida
            system("cls");
            printf("Invalid input, try again.\n\n");
        }

        printf("Options: \n1.Compute power of a number\n2.Exit\n");
        scanf("%d", &input);
    }

}