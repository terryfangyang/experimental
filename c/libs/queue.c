#include <stdlib.h>
#include "queue.h"

void queue_new(struct queue **queue, int elementSize, void (*freeFn)(void*))
{
	if (queue == NULL) return;

	if (*queue == NULL) {
		(*queue) = (struct queue *)malloc(sizeof(struct queue));
		(*queue)->list = NULL;
	}

	list_new(&((*queue)->list), elementSize, freeFn);
}

void queue_destroy(struct queue **queue)
{
	list_destroy(&(*queue)->list);
	free(*queue);
}

int queue_size(struct queue *queue)
{
	return list_size(queue->list);
}

void queue_enqueue(struct queue *queue, void *element)
{
	list_append(queue->list, element);
}

void queue_dequeue(struct queue *queue, void *element)
{
	if (queue_size(queue) <= 0) return;

	list_head(queue->list, element, 1);
}

void queue_peek(struct queue *queue, void *element)
{
	if (queue_size(queue) <= 0) return;

	list_head(queue->list, element, 0);
}
