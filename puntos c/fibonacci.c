#include <stdio.h>

//Metodo para calcular termino n de la secuencia de fibonacci
/*se usa unsigned long long int para  poder calcular terminos mas alla del 46, 
ya que los valores de estos exceden el valor maximo del tipo int*/
unsigned long long int fibonacci(int n){
    unsigned long long  n0 = 0;
    unsigned long long  n1 = 1;
    unsigned long long int flag = 0;
    
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    
    for(int i = 1; i < n; i++){
        flag = n1 + n0;
        n0 = n1;
        n1 = flag;
    }
    return flag;
}

int main(){
    //numero de termino de la secuencia a calcular
    int n;
    //Variable para manejo de opciones
    int input;

    printf("Options: \n1.Calculate a term of the Fibonacci sequence\n2.Exit\n");
    scanf("%d", &input);

    //ciclo de menu
    while(input != 2){
        if(input == 1){
            printf("Enter the number term of the Fibonacci series to be calculated:\n");
            scanf("%d", &n);
            printf("Term %d of the Fibonacci series is equal to %llu\n\n", n, fibonacci(n));
                }
                else{
                    //entrada invalida
                    printf("Invalid input, try again.\n\n");
                }

                printf("Options: \n1.Calculate a term of the Fibonacci sequence\n2.Exit\n");
                scanf("%d", &input);
    }

}