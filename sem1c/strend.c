#include <stdio.h>

int strend(char *s, char *t){
    int n=0, i;

    while (*s != '\0') // s is address of last char
        ++s;
    while (*t != '\0') // t is the address of last char. n is the length of *t
        ++t, ++n;

    for (i=0; i<n; i++){ // iterate strlen(t) num times of n
        if (*s != *t) 
            return 0;
        --s, --t;
    }
    return i;
}

int main(){
    int numchar_same = strend("vachan", "chan");
    printf("%i\n", numchar_same);
}
