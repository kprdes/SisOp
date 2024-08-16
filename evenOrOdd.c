#include <stdio.h>

//Funcion que revisa si un numero es par o no usando recursion
char* evenOrOdd(int n){
    if(n <= 1 ){
        if(n == 1 ){
            return "is odd.\n\n";
        }
        else{
            return "is even.\n\n";
        }
    }
    else{
        evenOrOdd(n - 2);
    }
}

int main(){
    //Numero a evaluar
    int n = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Check wether a number is even or odd\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){

        if(input == 1){
            printf("Enter the number: \n");
            scanf("%d", &n);
            printf("%d %s", n, evenOrOdd(n));
        }
        else{
            //entrada invalida
            printf("Invalid input, try again.\n\n");
        }
        printf("Options: \n1.Check wether a number is even or odd\n2.Exit\n");
        scanf("%d", &input);
    }

}