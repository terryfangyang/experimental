#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void graph_create(struct graph **g, int num)
{
	int i = 0;

	(*g) = (struct graph*)malloc(sizeof(struct graph));
	(*g)->v = num;
	(*g)->array = (struct AdjList*)malloc(sizeof(struct AdjList) * num);
	(*g)->isVisit = (int*)malloc(sizeof(int) * num);

	for (i = 0; i < num; i++)
	{
		((*g)->array[i]).head = NULL;
		(*g)->isVisit[i] = 0;
	}

}

void graph_destroy(struct graph *g)
{

	int i = 0;

	for(i = 0; i < g->v; i++)
	{
		if (g->array[i].head != NULL)
			list_destroy(&(g->array[i].head));
	}

	free(g->array);

}
void graph_addEdge(struct graph *g, int src, int dst)
{

	if (g == NULL) return ;

	if (g->array[src].head == NULL)
	{
		list_new(&(g->array[src].head), sizeof(int), NULL);
	}
	if (g->array[dst].head == NULL)
	{
		list_new(&(g->array[dst].head), sizeof(int), NULL);
	}
	list_append(g->array[src].head, &dst);
	list_append(g->array[dst].head, &src);

}

int graph_getFirstAdjVertex(struct graph *g, int index)
{
	int i;

	list_head(g->array[index].head, &i, 0);
	return i;
}

int graph_notEndVertex(struct graph *g, int index)
{
	if (index == -1)
		return -1;
	else
		return 0;
}

int graph_getNextAdjVertex(struct graph *g, int vertex, int cur, int *next)
{
	struct node *node = g->array[vertex].head->head;

	while (node != NULL)
	{
		int data = *(int*)node->data;

		if (data == cur)
		{
			if(node->next != NULL)
			{
				*next =  *(int*)node->next->data;
			}
			else
			{
				*next = -1;
			}

			return 0;
		}

		node = node->next;
	}

	return -1;
}

void graph_dfs(struct graph *g, int i)
{
	int node = 0;

	if (g == NULL) return;

	printf("visit node is %d \n", i);
	g->isVisit[i] = 1;

	for( node = graph_getFirstAdjVertex(g, i) ; graph_notEndVertex(g,node) != -1 ; graph_getNextAdjVertex(g, i, node, &node) )
	{
		if(!g->isVisit[node])
		{
			graph_dfs(g, node);
		}
	}
}

void graph_bfs(struct graph *g, int i)
{
	struct queue *q = NULL;
	int n = 0;
	int node = 0;

	queue_new(&q, sizeof(int), NULL);
	queue_enqueue(q, &i);

	while(!queue_isempty(q))
	{
		queue_dequeue(q, &n);
		if (!g->isVisit[n])
		{
			printf("visit node is %d \n", n);
			g->isVisit[n] = 1;
		}

		for( node = graph_getFirstAdjVertex(g, n) ; graph_notEndVertex(g,node) != -1 ; graph_getNextAdjVertex(g, n, node, &node) )
		{
			if (!g->isVisit[node])
			{
				queue_enqueue(q, &node);
			}
		}

	}
	queue_destroy(&q);
}
