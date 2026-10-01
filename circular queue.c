#include <stdbool.h>
#include <stdlib.h>

typedef struct {
     int *a, h, t, k, count;
} MyCircularQueue;

bool myCircularQueueIsEmpty(MyCircularQueue* q) {
    return q->count == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* q) {
    return q->count == q->k;
}

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = malloc(sizeof(MyCircularQueue));
    q->a = malloc(sizeof(int) * k);
    q->h = 0; q->t = -1; q->k = k; q->count = 0;
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* q, int value) {
    if (myCircularQueueIsFull(q)) return false;
    q->t = (q->t + 1) % q->k;
    q->a[q->t] = value;
    q->count++;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* q) {
    if (myCircularQueueIsEmpty(q)) return false;
    q->h = (q->h + 1) % q->k;
    q->count--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* q) {
    return myCircularQueueIsEmpty(q) ? -1 : q->a[q->h];
}

int myCircularQueueRear(MyCircularQueue* q) {
    return myCircularQueueIsEmpty(q) ? -1 : q->a[q->t];
}

void myCircularQueueFree(MyCircularQueue* q) {
    free(q->a); free(q);
}
