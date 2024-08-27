#include <stdio.h>

int lowercase(char a){
    if(a > 64 && a < 91){
        return 1;
    }
    else if(a > 96 && a < 123){
        return 0;
    }
    else{
        return -1;
    }
}

int main(){
    //Caracter a evaluar
    char a = '\0';
    //variable para guardar resultado
    int c = 0;

    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Check if a letter is lowercase\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){
        if(input == 1){
            printf("Enter the letter: \n");
            scanf(" %c", &a);

            c = lowercase(a);

            //1: la letra es mayuscula, 0: la letra es minuscula, -1: el caracter no es una letra
            if( c == 0){
                printf("The letter is lowercase.\n\n");
            }
            else if(c == 1){
                printf("The letter isn't lowercase.\n\n");
            }
            else if(c == -1){
                printf("The character is not part of the English alphabet.\n\n");
            }
        }
        else{
            //entrada invalida
            printf("Invalid input, try again.\n\n");
        }

        printf("Options: \n1.Check if a letter is lowercase\n2.Exit\n");
        scanf("%d", &input);
    }

    return 0;
}
