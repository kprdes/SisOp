#include <stdio.h>

// This function is to get an explicit type of number and change implicit type
int main() {
    int selection;
    printf("What do you want to convert? Type:\n1. Int to float.\n2. Float to Int.\n");
    scanf("%d", &selection); 

    if (selection == 1) {
        int input;
        printf("Please type the number that you want to change:\n");
        scanf("%d", &input);  
        printf("This is your number before the change: %d\n", input);
        float NewFloat = input;
        printf("This is your new number: %f\n", NewFloat);
    } else if (selection == 2) {
        float input;
        printf("Please type the number that you want to change:\n");
        scanf("%f", &input);  
        printf("This is your number before the change: %f\n", input);
        int NewInt = (int)input;
        printf("This is your new number: %d\n", NewInt);
    } else {
        printf("The input was incorrect\n");
    }

    return 0;
}
