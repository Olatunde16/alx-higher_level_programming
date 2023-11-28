#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: A pointer the head of the linked list.
 * @number: The number to insert.
 * Author - Olutunmibi Iseoluwa
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number) 
{
	listint_t *new, *current, *prev;
	
	new = malloc(sizeof(listint_t));
	
	if (new == NULL) 
		return NULL;
	
	new->n = number;
	new->next = NULL;
	
	current = *head;
	prev = NULL;
	
	while (current != NULL && current->n < number) 
	{
		prev = current;
		current = current->next;
	}
	
	if (prev == NULL) 
	{
		new->next = *head;
		*head = new;
	} 
	
	else 
	{
		prev->next = new;
		new->next = current;
	}
	
	return (new);
}
