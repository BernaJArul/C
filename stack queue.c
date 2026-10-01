
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void qInit(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void qPush(Queue* q, int x) {
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = x;
    q->size++;
}

int qPop(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int qFront(Queue* q) {
    return q->data[q->front];
}

bool qEmpty(Queue* q) {
    return q->size == 0;
}

typedef struct {
    Queue q;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    qInit(&(obj->q));
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    int n = obj->q.size;
    qPush(&(obj->q), x);
    // Rotate the queue so the newly added element is at the front
    for (int i = 0; i < n; i++) {
        int val = qPop(&(obj->q));
        qPush(&(obj->q), val);
    }
}

int myStackPop(MyStack* obj) {
    return qPop(&(obj->q));
}

int myStackTop(MyStack* obj) {
    return qFront(&(obj->q));
}

bool myStackEmpty(MyStack* obj) {
    return qEmpty(&(obj->q));
}

void myStackFree(MyStack* obj) {
    free(obj);
}
