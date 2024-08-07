#include <stdio.h>

int string_length(char s[]){
    int i=0;
    while (*(s+i)!='\0'){
        i++;
    }
    return i;
}

int main(){
    char str[] = "malayalam"; // 9 + null character
    int strlen = string_length(str);
    int cond = strlen/2;
    printf("%i %i", str[strlen], strlen);

    for(int i=0; i<cond; i++){
        if(str[i]!=str[strlen-i-1]){
            printf("%s is not a palindrome\n", str);
            return 0;
        }
    }; printf("%s is a palindrome\n", str);
}