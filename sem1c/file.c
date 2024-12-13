#include <stdio.h>

int main(){
    FILE *fptr = fopen("hi.txt", "r");
    // fprintf(fptr, " Hey");
    char mystring[100];
    while(fgets(mystring, 100, fptr)){
        printf("%s", mystring);
        fclose(fptr);
    }
    fclose(fptr);
}
