#include <stdio.h>
#include "linkedlist.h"

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

struct testvector test[] = {
	{"test list", testlinkedlist},
	{"test stack", testlinkedlist},

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
