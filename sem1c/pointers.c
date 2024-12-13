#include <stdio.h>

int main(){
    ///////////////////////////////////
    ///////////////////////////////////
    int x = 1, y = 2;

    int *p = &x;
    printf("p = %p\n*p = %i\n", p, *p); // address of x, value where p points
    (*p)++; 
    printf("increment p by 1\n");
    printf("*p = %i\nx = %i\n\n", *p, x);
    ///////////////////////////////////
    ///////////////////////////////////
    int a[] = {0, 1, 2, 3, 4, 5};
    int *pa = &a[0]; // eq: pa = a

    printf("%p\n%p\n", pa, pa+1);
    printf("%i\n%i\n\n", *(pa), *(pa+1)); // value at pa. value at pa+1.
    ///////////////////////////////////
    ///////////////////////////////////
    char amsg[] = "hey hi"; // array of characters
    char *pmsg = "hey hi"; // pointer initialized to point a string
    printf("%s\n", amsg); printf("%s\n\n", pmsg);
}
