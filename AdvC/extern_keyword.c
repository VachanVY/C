#include <stdio.h>
#include "extern_h.h"

// https://www.youtube.com/watch?v=85uE7-XKSRg&list=PL71Y0EmrppR0KyZvQWj63040UEzKQU7n8&index=26
int main(){
    printf("%d\n", add(10, 20));
    return 0;
}
// gcc .\AdvC\extern_keyword.c .\AdvC\extern_h.c