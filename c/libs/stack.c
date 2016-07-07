#include <stdlib.h>
#include "stack.h"

void stack_new(struct stack **stack, int elementSize, void (*freeFn)(void*))
{
	if (stack == NULL) return;

	if (*stack == NULL) {
		(*stack) = (struct stack *)malloc(sizeof(struct stack));
		(*stack)->list = NULL;
	}

	list_new(&((*stack)->list), elementSize, freeFn);
}

void stack_destroy(struct stack **stack)
{
	list_destroy(&(*stack)->list);
	free(*stack);
}

int stack_size(struct stack *stack)
{
	return list_size(stack->list);
}

void stack_push(struct stack *stack, void *element)
{
	list_prepend(stack->list, element);
}

void stack_pop(struct stack *stack, void *element)
{
	if (stack_size(stack) <= 0) return;

	list_head(stack->list, element, 1);
}

void stack_peek(struct stack *stack, void *element)
{
	if (stack_size(stack) <= 0) return;

	list_head(stack->list, element, 0);
}
