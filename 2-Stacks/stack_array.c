#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Stack kapasitesini 5 olarak belirliyoruz

// Stack yapisi
struct Stack {
    int items[MAX];
    int top;
};

// Stack'i baslatma
void initStack(struct Stack* s) {
    s->top = -1; // -1, stack'in tamamen bos oldugunu gosterir
}

// Stack dolu mu kontrolu
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Stack bos mu kontrolu
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// YENI ELEMAN EKLEME (Time Complexity: O(1))
void push(struct Stack* s, int newItem) {
    if (isFull(s)) {
        printf("Stack Overflow! (Yigin Dolu) - %d eklenemedi.\n", newItem);
        return;
    }
    s->top++; // Top işaretçisini bir yukarı kaydır
    s->items[s->top] = newItem; // O konuma yeni elemanı yerleştir
    printf("%d stack'e eklendi (Push).\n", newItem);
}

// EN USTTEKI ELEMANI CIKARMA (Time Complexity: O(1))
void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! (Yigin Bos)\n");
        return;
    }
    printf("%d stack'ten cikarildi (Pop).\n", s->items[s->top]);
    s->top--; // Top işaretçisini bir aşağı kaydırarak elemanı sanal olarak sil
}

// SADECE EN USTTEKI ELEMANI GORME (Time Complexity: O(1))
void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack bos.\n");
        return;
    }
    printf("En ustteki eleman (Peek): %d\n", s->items[s->top]);
}

int main() {
    struct Stack s;
    initStack(&s);

    printf("--- Stack Islemleri Basliyor ---\n");
    
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    
    printf("\n");
    peek(&s); // En üsttekine bakıyoruz ama çıkarmıyoruz
    
    printf("\n");
    pop(&s);  // En üsttekini (30) çıkarıyoruz
    peek(&s); // Artık en üstte 20 olmalı

    // Overflow test (Kapasiteyi asmaya calisalim)
    printf("\n--- Overflow Test ---\n");
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);
    push(&s, 70); // Kapasite 5 olduğu için bu eklenememeli!

    return 0;
}
