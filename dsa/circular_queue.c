#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int front;
    int rear;
    int maxlen;
    int counts;
    int *que;
} Queue;

Queue* init(int maxlen){
    Queue* que;
    que->front = 0;
    que->rear = -1;
    que->counts = 0;
    que->maxlen = maxlen;
    que->que = (int *)malloc(maxlen*sizeof(int));
    return que;
}

void del(Queue* que){
    free(que->que);
}

void push(Queue* que, int el){
    assert(que->counts != que->maxlen);
    que->rear = (que->rear + 1) % que->maxlen;
    que->counts += 1;
    que->que[que->rear] = el;
}

int pop(Queue* que){
    assert(que->counts > 0);
    int el = que->que[que->front];
    que->front = (que->front + 1) % que->maxlen;
    que->counts -= 1;
}

void display(Queue* que){
    printf("Queue([");
    for(int i=0; i<que->counts; i++){
        printf("%i, ", que->que[i]);
    }
    printf("], front=%i, rear=%i, counts=%i)\n", que->front, que->rear, que->counts);
}

int main(){
    Queue* que = init(4);
    push(que, 10); push(que, 20); push(que, 30); push(que, 40);
    display(que); // [10, 20, 30, 40]
    int el = pop(que); 
    display(que); // [10, 20, 30]
    push(que, 50);
    display(que);
    del(que);
}