#include <stdio.h>

int strcat(char *s, char *t){
  while(*s != '\0')
    ++s;                   // After the loop ends, s represents the address of last char of s
  while((*s = *t) != '\0') // value at t i.e *t will go to *s
    ++s, ++t;              // inc address of s and t 
}

int strcmp(char *s, char *t){
    while(*s != '\0' && *t != '\0'){
        if(*s != *t)
            return 0;
        ++s, ++t;    
    }
    return 1;
}

int strlen(char *s){
    int len = 0;
    while(*s != '\0')
        ++s, len += 1;
    return len;
}

int main(){
    char s[20] = "It's ";
    char t[8] = "Vachan";
    char u[8] = "Vachan";

    printf("%i\n", strcmp(t, s));
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