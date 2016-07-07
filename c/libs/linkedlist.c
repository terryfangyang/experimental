#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void list_new(struct list **list, int elementSize, void (*freeFuc)(void*))
{
	if (list == NULL) return;

	if (*list == NULL) {
		*list = (struct list *)malloc(sizeof(struct list));
		(*list)->elementSize = elementSize;
		(*list)->listLength = 0;
		(*list)->head = NULL;
		(*list)->tail = NULL;
		(*list)->freeFuc = freeFuc;
	}
}

void list_destroy(struct list **list)
{
	if (list == NULL || (*list) == NULL) return;

	while((*list)->head != NULL)
	{
		struct node *cur = (*list)->head;
		(*list)->head = cur->next;

		if ((*list)->freeFuc)
			(*list)->freeFuc(cur->data);

		free(cur->data);
		free(cur);
	}
}

void list_prepend(struct list *list, void *element)
{
	if (list == NULL) return;

	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = (void *)malloc(list->elementSize);

	memcpy(newNode->data, element, list->elementSize);
	newNode->next = list->head;
	list->head = newNode;

	//empty list
	if(list->tail == NULL)
		list->tail = list->head ;

	list->listLength++;
}

void list_append(struct list *list, void *element)
{
	if (list == NULL) return;

	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = (void*)malloc(list->elementSize);

	memcpy(newNode->data, element, list->elementSize);
	newNode->next = NULL;

	//empty list
	if (list->head == NULL) {
		list->head = list->tail = newNode;
	} else {
		list->tail->next = newNode;
		list->tail = newNode;
	}

	list->listLength++;
}

int list_size(struct list *list)
{
	if (list == NULL) return 0;

	return list->listLength;
}

void list_for_each(struct list *list, void (*listIterator)(void*))
{
	if (list == NULL) return ;

	struct node *cur = list->head;

	while(cur != NULL)
	{
		if (listIterator)
			listIterator(cur->data);

		cur = cur->next;
	}
}

void list_del(struct list *list, void *element, int (*cmp)(void*, void*))
{

}

void list_head(struct list *list, void *element, int isRemove)
{
	if (list == NULL) return;

	struct node *cur = list->head;
	memcpy(element, cur->data, list->elementSize);

	if (isRemove) {
		list->head = cur->next;
		list->listLength--;
		free(cur->data);
		free(cur);
	}
}

void list_tail(struct list *list, void *element)
{
	if (list == NULL) return;

	struct node *cur = list->tail;
	memcpy(element, cur->data, list->elementSize);
}
