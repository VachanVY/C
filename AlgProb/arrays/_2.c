/*
https://www.geeksforgeeks.org/program-to-reverse-an-array/

Input: original_array[] = {1, 2, 3} 
Output: array_reversed[] = {3, 2, 1}

Input: original_array[] = {4, 5, 1, 2}
Output: array_reversed[] = {2, 1, 5, 4}
*/

#include <stdio.h>

void reverse(int* in, int* out, int len){
    for(int i=0; i<len; i++){
        out[len-i-1] = in[i];
    }
}

int main(){
    int original_array[] = {4, 5, 1, 2};
    int rev_arr[4];

    reverse(original_array, rev_arr, 4);

    for(int i=0; i<4; i++){
        printf("%i\n", rev_arr[i]);
    }
}
