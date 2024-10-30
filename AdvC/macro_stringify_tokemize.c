#include <stdio.h>

#define STR(x) new_var_##x

#define add(type)\
    type add_##type(type a, type b){\
        return a + b;                \
    }

add(int)
add(float)

int main(){
    int STR(1) = 10;
    int STR(2) = 20;
    printf("%d %d\n", new_var_1, new_var_2);

    
    printf("%d\n", add_int(10, 20));
    printf("%f\n", add_float(10.5, 20.5));
    return 0;
}