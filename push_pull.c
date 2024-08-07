// ERROR!!!
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

void push(double); // push double value onto value stack
double pop(void);   // pop and return top value from stack

#define MAXVAL 100 // max depth of stack

int sp = 0; // next free stack pos
double val[MAXVAL];

// reverse polish calculator
int main(){
    int type;
    double op;
    char s[MAXOP];

    while((type = getchar()) != EOF){ // [1, 2, -, 4, 5, +, *] = (1-2)*(4+5) = -9
        switch(type){
            case NUMBER:
                push(atof(s)); break; // [2 , 1], [5, 4]
            case '+':
                push(pop() + pop()); break; // push(5+4) => [9, -1]
            case '*':
                push(pop()*pop()); break; // push(9 * -1) => [-9]
            case '-':
                op = pop(); // 2;  [2, 1] => [1]
                push(pop() - op); break;// push(1 - 2) => [-1]
            case '/':
                op = pop(); // 
                if (op != 0)
                    push(pop() - op);
                else
                    printf("ZeroDivisionError\n");
                break;
            case '\n':
                printf("Error: unknown command %s\n", s);
        }
    }
    printf("%f\n", val[0]);
}

void push(double f){
    if(sp<MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack is full, can't push %f\n", f); 
}

double pop(void){
    if(sp>0)
        return val[--sp];
    else    
        printf("Error: Stack is empty\n");
    return 0.0;    
}
