#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    Value* next;
} Value;

// Array of `Value`s
typedef Value* LinkedList;

LinkedList init(int val, Value* value){
    LinkedList list = (LinkedList)malloc(sizeof(Value));
    list->val = val;
    list->next = value;
    return list;
}

void insert(LinkedList list, int val, int idx){
    Value* to_insert = (Value*)malloc(sizeof(Value));
    list->next = to_insert;
}

void delete(){

}

int main(){
    LinkedList list = init(2, NULL);


}


