#include <stdio.h>
#include <stdbool.h>

void strcat(char *s, char *t){
  while(*s != '\0')
    ++s;                   // After the loop ends, s represents the address of last char of s
  while((*s = *t) != '\0') // value at t i.e *t will go to *s
    ++s, ++t;              // inc address of s and t
}

int strcmp(char *s, char *t){
    while(*s != '\0' && *t != '\0'){
        if(*s != *t)
            return false;
        ++s, ++t;    
    }
    return true;
}

size_t strlen(char *s){
    size_t len = 0;
    while(*s != '\0')
        ++s, len++;
    return len;
}

void strrev(char* s, char* r){
    size_t ns = strlen(s) - 1;
    int iter = ns;
    while(iter>=0){
        r[ns-iter] = s[iter];
        iter--;
    }
    r[ns+1] = '\0';
}


int main(){
    char s[20] = "It's ";
    char t[] = "Vachan";
    char u[] = "Vachan";
    char v[7];

    printf("%s\n", u);
    strrev(u, v);
    printf(v);
    // printf("%s\n", u);
    // printf("%i\n", strlen(t));
    // printf("%i\n", strcmp(t, s));
}

/*
int strcat(char *s, char *t){ // s must be big enough;

    int i, j;
    for (i=0; s[i] != '\0'; i++) // i is last char of s
        ;

    for (j=0; t[j] != '\0'; j++)
        s[i+j] = t[j];
    s[i+j] = '\0';

}
*/