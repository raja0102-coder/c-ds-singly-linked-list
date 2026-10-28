#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define Node structure for Singly Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("    [ERROR] Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("    [INFO] Linked list is empty.\n");
        return;
    }
    Node* temp = head;
    printf("    HEAD -> ");
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an element
bool searchNode(Node* head, int target) {
    Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == target) {
            printf("    [FOUND] Element %d found at position %d\n", target, position);
            return true;
        }
        temp = temp->next;
        position++;
    }
    printf("    [NOT FOUND] Element %d not present in list.\n", target);
    return false;
}

// Function to delete a node by key
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // If head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("    [SUCCESS] Deleted node with value %d\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present
    if (temp == NULL) {
        printf("    [WARNING] Key %d not found for deletion.\n", key);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;
    free(temp);
    printf("    [SUCCESS] Deleted node with value %d\n", key);
}

int main() {
    printf("==================================================\n");
    printf("      DATA STRUCTURES: SINGLY LINKED LIST         \n");
    printf("==================================================\n\n");

    Node* head = NULL;

    // 1. Insertion
    printf("[1] INSERTING ELEMENTS AT THE END:\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 25);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 55);
    displayList(head);
    printf("\n");

    // 2. Searching
    printf("[2] SEARCHING ELEMENTS:\n");
    searchNode(head, 40);
    searchNode(head, 99);
    printf("\n");

    // 3. Deletion
    printf("[3] DELETING ELEMENTS:\n");
    deleteNode(&head, 25);
    displayList(head);

    printf("\n==================================================\n");

    return 0;
}
