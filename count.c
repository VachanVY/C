#include <stdio.h>

int main(){
    int c, i;
    int nwhite = 0; int nother = 0;
    int ndigit[10];

    for(i=0; i<10; i++){
        ndigit[i] = 0;
    } 
    while((c=getchar()) != EOF){
        switch (c)
        {
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9':   
            ndigit[c-'0']++; // c-'0' gets the numerical value
            break;
        case '\n': case ' ': case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("nwhite: %i\n nother: %i\n", nwhite, nother); printf("ndigits:");
    for(i=0; i<10; i++){
        printf("%i ", ndigit[i]);
    }
}