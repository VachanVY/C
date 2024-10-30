#include <stdio.h>

// https://www.youtube.com/watch?v=xWQs59c78g4&list=PL71Y0EmrppR0KyZvQWj63040UEzKQU7n8&index=25

void foo(int *a, int *b, int *c){
    *a += *c;
    *b += *c;
}

void foo_restrict(int *restrict a, int *restrict b, int *c){
    *a += *c;
    *b += *c;
}

int main(){
    int x = 10, y = 20, z = 30;
    printf("x: %d, y: %d\n", x, y);

    foo(&x, &y, &z);
    printf("x: %d, y: %d\n", x, y);

    x = 10, y = 20, z = 30;
    foo_restrict(&x, &y, &z);
    printf("x: %d, y: %d\n", x, y);
    return 0;    
}