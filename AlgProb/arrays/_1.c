/*
https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

Maximum and minimum of an array using minimum number of comparisons
Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
              Maximum element is: 9

Input: arr[] = {22, 14, 8, 17, 35, 3}
Output:  Minimum element is: 3
              Maximum element is: 35
*/

#include <stdio.h>
#include <limits.h>

void minmax(int* arr, int len, int* min, int* max){
    *max = INT_MIN; *min = INT_MAX;
    for(int i=0; i<len; i++){
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min){
            *min = arr[i];
        }
    }
}

int main(){
    int min, max;
    minmax((int[]){3, 5, 4, 1, 9}, 5, &min, &max);
    printf("min:%i max:%i\n", min, max);
}