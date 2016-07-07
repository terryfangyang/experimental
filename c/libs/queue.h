#ifndef __QUEUE_H
#define __QUEUE_H

#include "linkedlist.h"

struct queue {
	struct list *list;
};

void queue_new(struct queue **q, int elementSize, void (*freeFn)(void*));
void queue_destroy(struct queue **q);

void queue_enqueue(struct queue *q, void* elementSize);
void queue_dequeue(struct queue *q, void* elementSize);
int queue_size(struct queue *q);
void queue_peek(struct queue *q, void *element);

#endif
