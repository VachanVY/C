#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    size_t maxlen;
    int rear;
    int front;
    int* que; // array of int
} Queue;

Queue* init(int num_ques, const size_t qmaxlen){
    Queue* pque = (Queue*)malloc(num_ques * sizeof(Queue)); // array of Queues

    for(int i=0; i<num_ques; i++){
        pque[i].que = (int *)malloc(sizeof(int)*qmaxlen);
        pque[i].maxlen = qmaxlen;
        pque[i].rear = -1;
        pque[i].front = 0;
    }
    return pque;
}

void del(Queue* pque, size_t num_ques){ // input: array of Queues
    for(int i=0; i<num_ques; i++){
        free(pque[i].que);
    }
    free(pque);
}

void insert_ascending(
    Queue* pque, // input: array of Queues
    unsigned int qnum, 
    int el
){
    assert(pque[qnum].rear != pque[qnum].maxlen - 1);
    int j = pque[qnum].rear;
    if(j>0){
        while(el<pque[qnum].que[j]){
            pque[qnum].que[j+1] = pque[qnum].que[j]; // shift element front
            j--;
        }
    }
    j++;
    pque[qnum].que[j] = el;
    pque[qnum].rear += 1;
}

int delete_element(
    Queue* pque, // input: array of Queues
    unsigned int qnum
){
    assert(pque[qnum].rear >= pque[qnum].front);
    int el = pque[qnum].que[pque[qnum].front++];
    return el;
}

void print_pque(
    Queue* pque, // input: array of Queues
    size_t num_ques
){
    for(int i=0; i<num_ques; i++){
        printf("Qnum %i: [", i);
        if(pque[i].rear>=pque[i].front){
            for(int j=pque[i].front; j<=pque[i].rear; j++){
                printf("%i, ", pque[i].que[j]);
            }
        }
        printf("]\n");
    }
}

int main(){
    size_t num_ques = 3; size_t maxlen = 5;
    Queue* pque =  init(num_ques, maxlen);
    print_pque(pque, num_ques);
    printf("\n\n\nfor loop inserting\n");

    for(size_t i=0; i<num_ques; i++){
        insert_ascending(pque, i, 23+i);
        insert_ascending(pque, i, 3232+i);
        insert_ascending(pque, i, 54554+i);
        insert_ascending(pque, i, 32324+i);
        insert_ascending(pque, i, 5252+i);
    }
    print_pque(pque, num_ques);

    printf("\n\n\ndeleting from qnum 1\n");
    delete_element(pque, 1);
    print_pque(pque, num_ques);

    printf("\n\n\ndeleting from qnum 2\n");
    delete_element(pque, 2);
    print_pque(pque, num_ques);

    printf("\n\n\ndeleting from qnum 0\n");
    delete_element(pque, 0);
    print_pque(pque, num_ques);

    printf("\n\n\ndeleting from qnum 0\n");
    delete_element(pque, 1);
    print_pque(pque, num_ques);

    del(pque, num_ques);
}