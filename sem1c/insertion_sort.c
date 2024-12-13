#include <stdio.h>

int main(){
    float arr[] = {5.0, 8.0, 7.0, 2.0, 4.0, 1.0, 6.0, 9.0, 3.0, 0.0};
    int N = sizeof(arr)/sizeof(float);

    for(int i=1; i<N; i++){
        for(int j=i-1; j<=0; j--){
            float temp = arr[i];
            while(arr[j]>temp){???????
                arr[i] = arr[j];

            }
        }
               
    }
}