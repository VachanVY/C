#include <stdio.h>

double pi = 3.1415926535897932385;

double factorial(int x){
    for(int n = x-1; n>=1; n--)
        x *= n;
    return (double) x;
}

double power(double x, int n){
    if(n==0)
        return (double) 1;
    double pow = x;
    for(int i=1; i<n; i++)
        pow *= x;
    return pow;
}

double SIN(double x){
    x *= pi/180; double sum = 0;
    for(int i=0; i<8; i++){
        int dinominator = 2*i + 1;
        sum += power(-1, i)*power(x, dinominator)/factorial(dinominator);
    }
    return sum;
}

int main(){
    printf("%f\n", SIN(30));
}

