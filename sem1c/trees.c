// ERROR
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode{
    char *word;
    int count;
    struct tnode *left;  // pointer to a tnode // left child
    struct tnode *right; // pointer to a tnode // right child
};
int getword(char *, int);

int main(){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);

/*
Add a node with w at or below p
Function which returns a pointer to a tnode
*/
struct tnode *addtree(struct tnode *p, char *w){ 
    int cond;

    if (p == NULL){             // new word has arrived
        p = talloc();           // make a new node
        (*p).word = strdup(w);  // add the word
        (*p).count = 1;         // inc the count
        (*p).left = (*p).right = NULL; 
    }
    else if ((cond = strcmp(w, (*p).word))) // repeated word 
        (*p).count++;
    else if (cond < 0) // lesser thing to the left
        (*p).left = addtree((*p).left, w);
    else              // greater thing to the right
        (*p).right = addtree((*p).right, w);   
    return p;     
}

void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint((*p).left);
        printf("%4d %s\n", (*p).count, (*p).word);
        treeprint((*p).right);
    }
}

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

int getword(char w[], int limit) {
	int c, len=0;
	/* first, skip over any non alphabetics */
	while ((c=getchar())!=EOF && !isalpha(c)) {
		/* do nothing more */
	}
	if (c==EOF) {
		return EOF;
	}
	/* ok, first character of next word has been found */
	w[len++] = c;
	while (len<limit && (c=getchar())!=EOF && isalpha(c)) {
		/* another character to be stored */
		w[len++] = c;
	}
	/* now close off the string */
	w[len] = '\0';
	return 0;
}

/* 
The nodes are maintained so that at any node the left subtree is lexicographically less than the 
word at the node, and the right subtree contains only words greater

To find out whether a new word is already in the tree, start at the root and compare the new word
to the word stored at that node. If they match, the question is answered. If the new word is less 
than the tree word, continue searching the left child, otherwise the right child.
If there is no child in the req direction, the new word is not in the tree, in fact it's the proper place
to add the new word
*/
