#include <stdio.h>
#include <stdlib.h>

//funcion que evalua si un año es bisiesto
//permite que se haga multiples veces por ejecucion
//Es bisiesto si es divisible por 4 y no por 100 o si es divisible por 400
char* isLeap(int y){
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0){
        return "is leap year.\n\n";
    }

    return "isn't a leap year.\n\n";
}

int main(){
    //Año a evaluar
    int y = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Check if a year is a leap year\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){

        if(input == 1){
            printf("Enter the year: \n");
            scanf("%d", &y);

            //Se revisan años AC unicamente
            if( y <= 0){
                printf("Value must be greater than 0.\n");
            }
            else{
                printf("%d %s", y, isLeap(y));
            }
        }
        else{
            //entrada invalida
            printf("Invalid input, try again.\n\n");
        }

        printf("Options: \n1.Check if a year is a leap year\n2.Exit\n");
        scanf("%d", &input);
    }
    return 0;
}
