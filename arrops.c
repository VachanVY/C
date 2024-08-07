#include <stdio.h>
#include <float.h>

int max1d(int N, float arr[]){
    int argmax = 0; float max = FLT_MIN;
    for(int i=0; i<N; i++){
        if(max < arr[i])
            max = arr[i], argmax = i;
    }
    return max, argmax;
}
                                                                      //            =axis(0)=> shape(5)
float* max2d(int shape[2], float arr[shape[0]][shape[1]],  int axis){ // shape(3, 5) =axis(1)=> shape(3)
    float* max_arr; int* argmax_arr; int argmax; float max;
    for(int i=0; i<shape[0]; i++){
        max = FLT_MIN, argmax = -1;
        for(int j=0; j<shape[1]; j++){
            if(max < arr[i][j]){
                max = arr[i][j], argmax = j;
                max_arr[i] = max, argmax_arr[i] = argmax;
            }
        // max_arr[i] =  max1d(sizeof(arr[i])/sizeof(arr[i][0]), arr[i]);
        }
    }
    return max_arr;
}
// {{1.0, 3.0, 1.0, 6.0, 0.0},   // {6,
//  {2.0, 0.0, 1.0, 0.0, 0.0},   //  2,
//  {1.0, 2.0, 0.0, -1.0, 10.0}}; // 10}

// float* argmax2d(int shape[2], float arr[shape[0]][shape[1]]){
//     float* argmax_arr;
//     for(int i=0; i<)
// }

int main(){
//     float arr1d[] = {1.0, 3.0, 1.0, 6.0, 0.0};
//     printf("%f\n", max1d(sizeof(arr1d)/sizeof(arr1d[0]), arr1d));
//     printf("%i\n", argmax1d(sizeof(arr1d)/sizeof(arr1d[0]), arr1d));
// //                        
    float arr2d[3][5] = {{1.0, 3.0, 1.0, 6.0, 0.0},   // {6,
                       {2.0, 0.0, 1.0, 0.0, 0.0},   //  2,
                       {1.0, 2.0, 0.0, -1.0, 10.0}}; // 10} axis=1 // {2.0, 3.0, 1.0, 6.0, 10.0} axis=0
    int shape[2] = {3, 5};
    float* maxarr2d = max2d(shape, arr2d, 1);
    for(int i=0; i<3; i++){
        printf("%f ", maxarr2d[i]);
    }
}
