#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to delete duplicates from a sorted linked list
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;

    while (current != NULL && current->next != NULL) {
        if (current->val == current->next->val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp); // Free memory of duplicate node
        } else {
            current = current->next;
        }
    }
    return head;
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Example usage
int main() {
    // Creating the linked list: 1 -> 1 -> 2
    struct ListNode* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);

    printf("Original list: ");
    printList(head);

    // Removing duplicates
    head = deleteDuplicates(head);

    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}
