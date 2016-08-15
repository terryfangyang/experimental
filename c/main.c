#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include "graph.h"
#include "tree.h"

struct testvector {
	char name[32];
	int (*testfn)(void);
};

static void ll_printint(void* data)
{
	printf("print int %d\n", *(int*)data);
}

int testlinkedlist(void)
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

int teststack(void)
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

int testqueue(void)
{
	int i;
	int n;
	struct queue *q = NULL;
	queue_new(&q, sizeof(int), NULL);

	for(i = 0; i < 3; i++)
		queue_enqueue(q, &i);

	queue_peek(q, &n);
	printf("peek queue n=%d\n", n);

	for(i = 0; i < 3; i++)
	{
		queue_dequeue(q, &n);
		printf("dequeue n=%d\n", n);
		printf("queue size size=%d\n", queue_size(q));
	}

	queue_destroy(&q);
	return 0;
}

int testgraph(void)
{
	struct graph *g = NULL;
	int i = 5;

	graph_create(&g, i);

	graph_addEdge(g, 0, 1);
	graph_addEdge(g, 0, 4);
	graph_addEdge(g, 1, 2);
	graph_addEdge(g, 1, 3);
	graph_addEdge(g, 1, 4);
	graph_addEdge(g, 2, 3);
	graph_addEdge(g, 3, 4);

	list_for_each(g->array[1].head, ll_printint);
	graph_bfs(g, 0);
	printf("test graph is done \n");
	graph_destroy(g);
	return 0;
}

void testtree1(struct BTree **root, int array[], int left, int right)
{

	int l,r,mid;
	if (right < left) return;

	l = left;
	r = right;
	mid = (l + r)/2;

	(*root) = (struct BTree*)malloc(sizeof(struct BTree));
	(*root)->data = array[mid];
	(*root)->lchild = NULL;
	(*root)->rchild = NULL;
	testtree1(&(*root)->lchild, array, l, mid-1);
	testtree1(&(*root)->rchild, array, mid + 1, right);

	return root;
}

int testtree(void)
{
	//int i;
	struct BTree *root = NULL;
	int btarray[] = {1, 2, 3, 4, 5, 6, 7};

#if 0
	for(i = 0; i < sizeof(btarray)/sizeof(int); i++)
		bt_insertNode(&root, btarray[i]);
#endif
	testtree1(&root, btarray, 0,6);
	bt_inorder(root);
	printf("bt deepth is %d\n", bt_depth(root));
	bt_destroy(root);
	return 0;
}

struct testvector test[] = {
	{"test list", testlinkedlist},
	{"test stack", teststack},
	{"test queue", testqueue},
	{"test graph", testgraph},
	{"test btree", testtree},
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
