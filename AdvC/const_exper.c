#include <stdio.h>

#define LEN 10
#ifndef LEN != 10
    #error "LEN must be 10"
#endif
// constepr size_t len = 10; // valid only in c23

int main(){
    int arr[LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i = 0; i < LEN; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}