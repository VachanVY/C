#include <iostream>

#include <stdio.h>
#include <stdlib.h>

template <typename dtype>
struct Value{
    struct Value* llink;
    struct Value* rlink;
    dtype val;
};

struct DoublyLinkedList{
    Value<short>* header;
    size_t count;
};

// INIT and DISPLAY FUNCS

DoublyLinkedList* init(){
    DoublyLinkedList* head = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    head->header = (Value<short>*)malloc(sizeof(Value<short>));
    head->header->llink = NULL;
    head->header->rlink = NULL;
    head->header->val = 0;
    head->count = 0;
    return head;
}

int main(){

}
 

/*



// INSERT OPERATIONS

// insert at end
void append(DoublyLinkedList* dllist, int el){
    // increase count
    dllist->count++;

    // make node to insert
    Value* value = (Value*)malloc(sizeof(Value));
    value->val = el;

    if(dllist->header->llink == NULL && dllist->header->rlink == NULL){
        dllist->header->llink = value;
        dllist->header->rlink = value;
        value->rlink = dllist->header;
        value->llink = dllist->header;
    }
    else{
        // change links
        value->llink = dllist->header->rlink;
        value->rlink = dllist->header;
        dllist->header->rlink->rlink = value;
        dllist->header->rlink = value;
    }
}

// insert at front
void prepend(DoublyLinkedList* dllist, int el);

// insert at given index
void insert_at_idx(DoublyLinkedList* dllist, int el);


// DELETE OPERATIONS

// delete from end
int pop(DoublyLinkedList* dllist);

// delete from front
int popf(DoublyLinkedList* dllist);

// delete given index
int delete_at_idx(DoublyLinkedList* dllist);



*/