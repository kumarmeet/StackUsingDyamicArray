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


void halfArray(DynamicStack *stack)
{
    stack->ptr = realloc(stack->ptr, (stack->capacity / 2) * sizeof(int));
    stack->capacity /= 2;
}

void doubleArray(DynamicStack *stack)
{
    stack->ptr = realloc(stack->ptr, (stack->capacity) * 2 * sizeof(int));
    stack->capacity *= 2;
    stack->top += 1;
}

int isEmpty(DynamicStack *stack)
{
    return (stack->top == -1) ? 1: 0;
}

int isFull(DynamicStack *stack)
{
    return stack->top + 1 == stack->capacity ? 1: 0;
}

int countItems(DynamicStack *stack)
{
    return stack->top + 1;
}

void push(DynamicStack *stack, int item)
{
    if(stack->top + 1 == stack->capacity)
        doubleArray(stack);
    else
    {
        stack->top += 1;
        stack->ptr[stack->top] = item;
    }
}

int pop(DynamicStack *stack)
{
    int item = -1;

    if(stack->top == -1)
    {
        printf("Underflow");
        return item;
    }
    else
    {
        item = stack->ptr[stack->top];
        stack->top -= 1;
    }
    return item;
}

int peek(DynamicStack *stack)
{
    return stack->top == -1 ? -1 : stack->ptr[stack->top];
}

DynamicStack * createDynamicStack(int cap)
{
    DynamicStack *s = (DynamicStack*)malloc(sizeof(DynamicStack));
    s->capacity = cap;
    s->top = -1;
    s->ptr = (int*)malloc(sizeof(int) * cap);
    return s;
}

