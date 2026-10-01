#include <stdbool.h>
#include <stdlib.h>

#define STACK_CAPACITY 100

// Helper Struct for Stack
typedef struct {
    int data[STACK_CAPACITY];
    int top;
} Stack;

// Initialize an empty stack
void stackInit(Stack* s) {
    s->top = -1;
}

// Push to stack
void stackPush(Stack* s, int x) {
    s->data[++(s->top)] = x;
}

// Pop from stack
int stackPop(Stack* s) {
    return s->data[(s->top)--];
}

// Peek stack top
int stackPeek(Stack* s) {
    return s->data[s->top];
}

// Check if stack is empty
bool stackEmpty(Stack* s) {
    return s->top == -1;
}
typedef struct {
    Stack s1;
    Stack s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    stackInit(&(obj->s1));
    stackInit(&(obj->s2));
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(&(obj->s1), x);
}

// Helper function to shift elements from s1 to s2 when s2 is empty
void shiftStacks(MyQueue* obj) {
    if (stackEmpty(&(obj->s2))) {
        while (!stackEmpty(&(obj->s1))) {
            stackPush(&(obj->s2), stackPop(&(obj->s1)));
        }
    }
}

int myQueuePop(MyQueue* obj) {
    shiftStacks(obj);
    return stackPop(&(obj->s2));
}

int myQueuePeek(MyQueue* obj) {
    shiftStacks(obj);
    return stackPeek(&(obj->s2));
}

bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(&(obj->s1)) && stackEmpty(&(obj->s2));
}

void myQueueFree(MyQueue* obj) {
     free(obj);
}
