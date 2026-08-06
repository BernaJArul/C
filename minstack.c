#include <stdlib.h>

typedef struct { int val, min; } Node;

typedef struct {
    Node data[30000];
    int top;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    int min = (obj->top == -1 || val < obj->data[obj->top].min) ? val : obj->data[obj->top].min;
    obj->data[++obj->top] = (Node){val, min};
}

void minStackPop(MinStack* obj) { obj->top--; }

int minStackTop(MinStack* obj) { return obj->data[obj->top].val; }

int minStackGetMin(MinStack* obj) { return obj->data[obj->top].min; }

void minStackFree(MinStack* obj) { free(obj); }
