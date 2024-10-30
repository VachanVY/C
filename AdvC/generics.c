#include <stdio.h>

int add_int(int a, int b){return a + b;}
float add_float(float a, float b){return a + b;}
double add_double(double a, double b){return a + b;}

#define add(a, b) _Generic((a),      \
    int: add_int((a), (b)),          \
    float: add_float((a), (b)),      \
    double: add_double((a), (b)),    \
    default: printf("Invalid type\n")\
)

int main(){
    printf("%d\n", add(10, 20));
    printf("%f\n", add(10.5f, 20.5f));
    printf("%lf\n", add(10.5, 20.5));
    printf("%lf\n", add((short)10, (short)20));
    return 0;
}