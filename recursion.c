#include <stdio.h>

int sum(int n){
    if(n==0)
        return 0;
    int res = n + sum(n-1);
    return res;    
}

int factorial(int n){
    if (n==0 || n==1)
        return 1;
    int res = n * factorial(n-1);
    return res;
}

int main(){
    printf("Sum: %i\n", sum(10));
    printf("Factorial: %i\n", factorial(10));
}