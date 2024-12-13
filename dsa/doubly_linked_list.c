#include <stdio.h>
#include <stdlib.h>

typedef struct Value{
    struct Value* llink;
    struct Value* rlink;
    int val;
} Value;

typedef struct{
    Value* header;
    size_t count;
} DoublyLinkedList;

// INIT, DEL and DISPLAY FUNCS

DoublyLinkedList* init(){
    DoublyLinkedList* head = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    head->header = (Value*)malloc(sizeof(Value));
    head->header->llink = NULL;
    head->header->rlink = NULL;
    head->header->val = 0;
    head->count = 0;
    return head;
}

void del(DoublyLinkedList* dllist){
    Value* temp = dllist->header->llink;

    while(temp->rlink != dllist->header){
        temp = temp->rlink;
        free(temp->llink);
    }
    free(temp);
    free(dllist->header);
    free(dllist);
}

void display(DoublyLinkedList* dllist){
    Value* temp = dllist->header->llink;
    printf("[");
    do{
        printf("%i, ", temp->val);
        temp = temp->rlink;     
    }while(temp != dllist->header);
    printf("]\n");
}

// INSERT OPERATIONS

// insert at end
void append(DoublyLinkedList* dllist, int el){
    // increase count
    dllist->count++;

    // make node to insert
    Value* value = (Value*)malloc(sizeof(Value));
    value->val = el;

    // change links
    if(dllist->header->llink == NULL && dllist->header->rlink == NULL){ // list is empty
        dllist->header->llink = value;
        dllist->header->rlink = value;
        value->rlink = dllist->header;
        value->llink = dllist->header;
        return;
    }
    value->llink = dllist->header->rlink;
    value->rlink = dllist->header;
    dllist->header->rlink->rlink = value;
    dllist->header->rlink = value;
    
}

// insert at front
void prepend(DoublyLinkedList* dllist, int el){
    // increase count
    dllist->count++;

    // make node to insert
    Value* value = (Value*)malloc(sizeof(Value));
    value->val = el;

    // change link to insert at front
    if(dllist->header->llink == NULL && dllist->header->rlink == NULL){ // list is empty
        dllist->header->llink = value;
        dllist->header->rlink = value;
        value->rlink = dllist->header;
        value->llink = dllist->header;
        return;
    }
    value->rlink = dllist->header->llink;
    dllist->header->llink->llink = value;
    dllist->header->llink = value;
    value->llink = dllist->header;
}

// insert at given index
void insert_at_idx(DoublyLinkedList* dllist, int el, int idx){
    size_t i = 0;
    Value* temp = dllist->header->llink;

    // make node to insert
    Value* value = (Value*)malloc(sizeof(Value));
    value->val = el;

    // traverse till idx
    while (i != idx){
        temp = temp->rlink;
        i++;
    }

    // change links for insertion
    
}


// DELETE OPERATIONS

// delete from end
int pop(DoublyLinkedList* dllist);

// delete from front
int popf(DoublyLinkedList* dllist);

// delete given index
int delete_at_idx(DoublyLinkedList* dllist);


int main(){
    DoublyLinkedList* dllist = init();
    append(dllist, 10);
    display(dllist);
    append(dllist, 20);
    display(dllist);
    append(dllist, 247874);
    display(dllist);
    prepend(dllist, 2024);
    display(dllist);
    prepend(dllist, 3232);
    display(dllist);
    prepend(dllist, 543);
    display(dllist);
    prepend(dllist, 421);
    display(dllist);
    del(dllist);
}
 

