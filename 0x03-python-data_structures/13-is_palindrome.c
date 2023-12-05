#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
#include <stdio.h>
#include <stdlib.h>

/* Definition of a singly linked list node */
typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

/* Function to reverse a linked list */
listint_t *reverse_list(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to the linked list
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */
/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1;  // An empty list or a single-node list is considered a palindrome
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = *head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        prev_slow = slow;
        slow = slow->next;
    }

    listint_t *second_half = reverse_list(slow);
    listint_t *first_half = *head;
    prev_slow->next = NULL;  // Split the original list into two halves

    while (first_half != NULL && second_half != NULL) {
        if (first_half->n != second_half->n) {
            return 0;  // Not a palindrome
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return (1);  
}

/* Example usage */
int main() {
    // Example linked list: 1 -> 2 -> 3 -> 2 -> 1
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 1;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 2;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->n = 3;
    head->next->next->next = malloc(sizeof(listint_t));
    head->next->next->next->n = 2;
    head->next->next->next->next = malloc(sizeof(listint_t));
    head->next->next->next->next->n = 1;
    head->next->next->next->next->next = NULL;

    // Check if the linked list is a palindrome
    int result = is_palindrome(&head);
    if (result) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free memory
    while (head != NULL) {
        listint_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
