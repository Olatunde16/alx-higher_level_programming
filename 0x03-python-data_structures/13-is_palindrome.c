#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
void *reverse_list(listint_t *head) 
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;
	
	while (current != NULL) 
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}	
	return (prev);
}

/**
 * is_palindrome - checks if a linked list is a palindrome
 * @head: double pointer to the linked list
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */

int is_palindrome(listint_t **head) 
{
	if (*head == NULL || (*head)->next == NULL)
        return (1);
	
	listint_t *slow = *head;
	listint_t *fast = *head;
	listint_t *prev_slow = *head;
	
	while (fast != NULL && fast->next != NULL) 
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}
	
	listint_t *second_half = reverse_list(slow);
	listint_t *first_half = *head;
	prev_slow->next = NULL; 
	
	while (first_half != NULL && second_half != NULL) 
	{
		if (first_half->n != second_half->n)
			return (0);
		
		first_half = first_half->next;
		second_half = second_half->next;
	}
	
	return (1);  
}
