#include <stdio.h>

int fibonacci(int n){
    int n0 = 0;
    int n1 = 1;
    int flag = 0;
    
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
    int n;
    printf("Enter the number term of the Fibonacci series to be calculated:\n");
    scanf("%d", &n);
    printf("Term %d of the Fibonacci series is equal to %d\n\n", n, fibonacci(n));
}