#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int capacity;
    int top;
    int *ptr;
} DynamicStack;

DynamicStack * createDynamicStack(int);
void push(DynamicStack*, int);
int pop(DynamicStack *);
int peek(DynamicStack *);
int countItems(DynamicStack *);
int isFull(DynamicStack*);
int isEmpty(DynamicStack*);
void doubleArray(DynamicStack*);
void halfArray(DynamicStack*);

int main()
{
    DynamicStack *stack = NULL;
    stack = createDynamicStack(4);
    push(stack, 20);
    push(stack, 20);
    push(stack, 20);
    push(stack, 20);
    return 0;
}
