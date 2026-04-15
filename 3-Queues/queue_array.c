#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the queue

struct Queue {
    int items[MAX];
    int front;
    int rear;
};

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    // Empty condition: front is -1 OR front has surpassed rear
    return q->front == -1 || q->front > q->rear;
}

// ADD ELEMENT TO REAR (Time Complexity: O(1))
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is Full! (Overflow) - Cannot enqueue %d\n", value);
        return;
    }
    // If inserting the first element, set front to 0
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// REMOVE ELEMENT FROM FRONT (Time Complexity: O(1))
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty! (Underflow) - Cannot dequeue\n");
        return;
    }
    printf("Dequeued: %d\n", q->items[q->front]);
    q->front++;
    
    // Reset the queue pointers if all elements are removed
    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

// VIEW THE FRONT ELEMENT (Time Complexity: O(1))
void peekFront(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Front element: %d\n", q->items[q->front]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    printf("--- Queue Operations Started ---\n");

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("\n");
    peekFront(&q);

    printf("\n");
    dequeue(&q); // 10 will be removed (First In, First Out)
    peekFront(&q); // Now 20 should be at the front

    // Overflow test
    printf("\n--- Overflow Test ---\n");
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This should fail because the array capacity (MAX=5) is reached

    return 0;
}
