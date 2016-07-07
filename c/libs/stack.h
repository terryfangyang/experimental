#ifndef __STACK_H
#define __STACK_H

#include "linkedlist.h"

struct stack {
	struct list *list ;
};

void stack_new(struct stack **stack, int elementSize, void (*freeFn)(void*));
void stack_destroy(struct stack **stack);

void stack_peek(struct stack *stack, void *element);
void stack_push(struct stack *stack, void *element);
void stack_pop(struct stack *stack, void *element);
int stack_size(struct stack *stack);
#endif
