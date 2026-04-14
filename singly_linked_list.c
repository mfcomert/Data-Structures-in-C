#include <stdio.h>
#include <stdlib.h>

// Düğüm (Node) yapısı
struct Node {
    int data;
    struct Node* next;
};

// Listenin sonuna eleman ekleme (Time Complexity: O(n))
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// YENİ: Düğüm Silme Fonksiyonu (Time Complexity: O(n))
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    // Durum 1: Silinmek istenen düğüm 'head' (ilk düğüm) ise
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Başlangıcı bir sonraki düğüme kaydır
        free(temp);             // Eski başı bellekten sil
        return;
    }

    // Durum 2: Silinmek istenen düğümü listede ara
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Eğer değer listede yoksa fonksiyondan çık
    if (temp == NULL) return;

    // Düğümü listeden kopar (prev'in next'ini, temp'in next'ine bağla)
    prev->next = temp->next;
    
    // Bellekten sil (Memory Management)
    free(temp);
}

// YENİ: Program biterken tüm belleği işletim sistemine iade etme
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Sonraki düğümü kaybetmemek için kaydet
        free(current);        // Mevcut düğümü sil
        current = next;       // Bir sonrakine geç
    }
    *head_ref = NULL; // Liste tamamen boşaltıldı
}

// Listeyi ekrana yazdırma (Time Complexity: O(n))
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    printf("Elemanlar ekleniyor...\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Ilk Liste: ");
    printList(head);

    printf("\n20 degeri siliniyor...\n");
    deleteNode(&head, 20); // Aradan eleman silme
    
    printf("Guncel Liste: ");
    printList(head);

    // Program biterken belleği temizle (Çok önemli!)
    freeList(&head);
    
    return 0;
}
