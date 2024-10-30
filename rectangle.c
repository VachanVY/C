#include <stdio.h>

int main(){
    int length = 60, breadth = 40;

    for(int j=0; j<breadth; j++){
        for(int i=0; i<length; i++){
            if((j>0 && j<breadth-1) && (i>0 && i<length-1))
                printf(" ");
            else
                printf("|");
        }
        printf("\n");
    }
}