#include <stdio.h>
#include <math.h>

struct Vector {
    float x;
    float y;
};

float magnitude(struct Vector v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

float sum(float xs[], int len){
    float sum = 0;
    for (int i = 0; i < len; i++){
        sum += xs[i];
    }
    return sum;
}

int main() {
    struct Vector v = {1.0, 2.0};
    printf("%f\n", magnitude(v));
    printf("%f\n", magnitude((struct Vector){1.0, 2.0}));

    printf("sum: %f\n", sum((float[]){1.0, 2.0, 3.0}, 3));
    return 0;
}