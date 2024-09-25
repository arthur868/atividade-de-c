#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
struct Node {
    int data;
    struct Node* next;
};

// Função para adicionar um nó ao final da lista
void append(struct Node** head_ref, int new_data) {
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

// Função para inverter a lista
void invert(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Armazena o próximo nó
        current->next = prev;  // Inverte o ponteiro
        prev = current;        // Move prev para o atual
        current = next;        // Move current para o próximo nó
    }
    *head_ref = prev;  // Atualiza a cabeça da lista
}

// Função para imprimir a lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Função principal
int main() {
    struct Node* head = NULL;

    append(&head, 20);
    append(&head, 40);
    append(&head, 10);

    printf("Lista original:\n");
    printList(head);

    invert(&head);

    printf("Lista invertida:\n");
    printList(head);

    // Liberação de memória (opcional)
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
