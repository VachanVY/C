// Create a BST of N integers: 6, 9, 5, 2, 8, 15, 24, 14, 8, 5, 2
// Traverse: Inorder, Preorder and Post Order
// Search for a value

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* llink;
    struct Node* rlink;
    int el;
} Node;

Node* getNode(int el){
    Node* root = (Node*)malloc(sizeof(Node));
    root->el = el;
    root->llink = NULL;
    root->rlink = NULL;
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->llink);
        freeTree(root->rlink);
        free(root);
    }
}

void insertNode(Node* root, int insert_el){
    if(insert_el <= root->el){
        if(root->llink == NULL)
            root->llink = getNode(insert_el);
        else
            insertNode(root->llink, insert_el);
    } else{
        if(root->rlink == NULL)
            root->rlink = getNode(insert_el);
        else
            insertNode(root->rlink, insert_el);
    }
}

void InOrder(Node* root){
    if(root!=NULL){
        InOrder(root->llink);
        printf("%i ", root->el);
        InOrder(root->rlink);
    }
}

void PreOrder(Node* root){
    if(root!=NULL){
        printf("%i ", root->el);
        PreOrder(root->llink);
        PreOrder(root->rlink);
    }
}

void PostOrder(Node* root){
    if(root!=NULL){
        PostOrder(root->llink);
        PostOrder(root->rlink);
        printf("%i ", root->el);
    }
}

int main(){
    const int len = 12;
    int arr[] = { 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2};

    Node* root = getNode(arr[0]);
    for(int i=1; i<len; i++){
        insertNode(root, arr[i]);
    }
    printf("INORDER");
    InOrder(root);
    printf("\n");

    printf("PREORDER");
    PreOrder(root);
    printf("\n");

    printf("POSTORDER");
    PostOrder(root);
    printf("\n");

    freeTree(root);
}
