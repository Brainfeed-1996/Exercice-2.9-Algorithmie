#include <stdio.h>
#include <stdlib.h>

// Définition de la structure du nœud
struct Node {
    int data;
    struct Node* next;
};

// Fonction pour créer un nouveau nœud
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fonction pour calculer les produits des éléments positifs et négatifs
void calculateProducts(struct Node* head, int* positiveProduct, int* negativeProduct) {
    *positiveProduct = 1;
    *negativeProduct = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data > 0) {
            *positiveProduct *= temp->data;
        } else if (temp->data < 0) {
            *negativeProduct *= temp->data;
        }
        temp = temp->next;
    }
}

// Fonction principale
int main() {
    // Création d'une liste simplement chaînée d'entiers
    struct Node* head = createNode(1);
    head->next = createNode(-2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(-4);

    int positiveProduct, negativeProduct;
    calculateProducts(head, &positiveProduct, &negativeProduct);

    printf("Produit des éléments positifs: %d\n", positiveProduct);
    printf("Produit des éléments négatifs: %d\n", negativeProduct);

    return 0;
}
