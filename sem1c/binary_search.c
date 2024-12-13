#include <stdio.h>

int binary_search(int arr[], int element){
    int N = sizeof(arr)/sizeof(int);

    int mid, low=0, high=N-1;
    while(1){
        mid = (high + low)/2;
        if(arr[mid] == element)
            return mid;
        else if(element < arr[mid])
            high = mid, printf("low:%i mid:%i high:%i\n", low, mid, high);
        else if (element > arr[mid])
            low = mid, printf("low:%i mid:%i high:%i\n", low, mid, high);
        else
            return 0;
    }
}

int main(){
    int arr[] = {9, 18, 28, 38, 40, 45, 90, 100, 120};
    int element = 38;

    int idx = binary_search(arr, element);

    printf("%i/n", idx);
}
