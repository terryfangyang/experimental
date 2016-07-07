#include <stdio.h>
#include "linkedlist.h"
#include "stack.h"

struct testvector {
	char name[32];
	int (*testfn)(void);
};

static void ll_printint(void* data)
{
	printf("print int %d\n", *(int*)data);
}

int testlinkedlist (void)
{
	int i;
	struct list *list = NULL;
	list_new(&list, sizeof(int), NULL);

	for(i = 0; i < 3; i++)
		list_prepend(list, &i);

	list_for_each(list, ll_printint);
	list_destroy(&list);
	return 0;
}

int teststack (void)
{
	int i;
	int n;
	struct stack *s = NULL;
	stack_new(&s, sizeof(int), NULL);

	for(i = 0; i < 3; i++)
		stack_push(s, &i);

	stack_peek(s, &n);
	printf("peek stack n=%d\n", n);

	for(i = 0; i < 3; i++)
	{
		stack_pop(s, &n);
		printf("stack pop n=%d\n", n);
		printf("stack size size=%d\n", stack_size(s));
	}

	stack_destroy(&s);
	return 0;
}

struct testvector test[] = {
	{"test list", testlinkedlist},
	{"test stack", teststack},

};

int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i < sizeof(test)/sizeof(struct testvector); i++)
	{
		printf("%s result = %d\n",test[i].name,test[i].testfn());
	}

	return 0;
}
