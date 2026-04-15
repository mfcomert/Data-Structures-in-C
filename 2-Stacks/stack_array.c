#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

// Stack structure
struct Stack {
    int items[MAX];
    int top;
};

// Initialize the stack
void initStack(struct Stack* s) {
    s->top = -1; // -1 indicates the stack is empty
}

// Check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// PUSH: Add element to the top (Time Complexity: O(1))
void push(struct Stack* s, int newItem) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d.\n", newItem);
        return;
    }
    s->top++;
    s->items[s->top] = newItem;
    printf("Pushed: %d\n", newItem);
}

// POP: Remove element from the top (Time Complexity: O(1))
void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack is empty.\n");
        return;
    }
    printf("Popped: %d\n", s->items[s->top]);
    s->top--;
}

// PEEK: View the top element without removing it (Time Complexity: O(1))
void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element (Peek): %d\n", s->items[s->top]);
}

int main() {
    struct Stack s;
    initStack(&s);

    printf("--- Stack Operations Started ---\n");
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("\n");
    peek(&s);
    
    printf("\n");
    pop(&s);  // Removes 30
    peek(&s); // Now 20 should be on top

    // Overflow test
    printf("\n--- Overflow Test ---\n");
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70); // This should fail due to MAX capacity (5)

    return 0;
}
