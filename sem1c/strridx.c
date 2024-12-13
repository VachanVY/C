#include <stdio.h>
#include <string.h>

int strridx(char str[], char t);

int main(){
    char str[] = "Vachan V Yaligod";
    char t = 'V';

    int idx = strridx(str, t);
    printf("%i\n", idx);
}

int strridx(char str[], char t){
    for(int i=strlen(str)-1; i>=0; i--){
        if(str[i]==t){
            return i;
        }
    }
    return -1;
}