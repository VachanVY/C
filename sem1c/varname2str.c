#include <stdio.h>

#define dprint(expr) printf(#expr " = %f\n", expr)
#define paste(front, back) front ## back

int main(){
    float x = 1, y = 2;
    dprint(x/y);

    float xy = 1;
    printf("%f\n", paste(x, y));
}
