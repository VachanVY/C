#include <stdio.h>

int main(){
    float arr[7] /*= {5.0, 8.0, 7.0, 2.0, 4.0, 1.0, 6.0, 9.0, 3.0, 0.0}*/, temp;
    int N = sizeof(arr)/sizeof(float);

    printf("Input array\n");
    for(int i=0; i<N; i++)
        scanf("%f ", arr[i]);
    printf("\n\n");    

    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Printing sorted array\n");
    for(int i=0; i<N; i++)
        printf("%f ", arr[i]);
    printf("\n");    
}
