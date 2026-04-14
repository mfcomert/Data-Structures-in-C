#include <stdio.h>
#include <stdlib.h>

// 1. Adım: Düğüm (Node) yapısını tanımlama
struct Node {
    int data;
    struct Node* next;
};

// 2. Adım: Listenin sonuna eleman ekleme fonksiyonu (Time Complexity: O(n))
void insertAtEnd(struct Node** head_ref, int new_data) {
    // Bellekte yeni bir düğüm için yer ayır (Memory Allocation)
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref; // Listenin sonunu bulmak için geçici pointer

    // Yeni düğümün verisini ata ve next pointer'ını NULL yap (çünkü en sona eklenecek)
    new_node->data = new_data;
    new_node->next = NULL;

    // Eğer liste tamamen boşsa, yeni düğüm doğrudan head (baş) olur
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Liste boş değilse, son düğüme kadar ilerle
    while (last->next != NULL) {
        last = last->next;
    }

    // Son düğümün next pointer'ını yeni düğüme bağla
    last->next = new_node;
}

// 3. Adım: Listeyi ekrana yazdırma fonksiyonu (Time Complexity: O(n))
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n"); // Listenin bittiğini göstermek için
}

// Ana fonksiyon: Kodumuzu test edelim
int main() {
    // Başlangıçta liste boş (head = NULL)
    struct Node* head = NULL;

    printf("Elemanlar ekleniyor...\n");
    
    // Fonksiyona head'in adresini (&head) gönderiyoruz ki orijinal listeyi değiştirebilelim
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);

    printf("Bagli Liste: ");
    printList(head);

    return 0;
}
