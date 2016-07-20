#ifndef __GRAPH_H
#define __GRAPH_H
#include "linkedlist.h"
#include "queue.h"

struct AdjList {
	struct list *head;
};

struct graph {
	int v;
	struct AdjList *array;
	int *isVisit;
};

void graph_create(struct graph **g, int num);
void graph_addEdge(struct graph *g, int src, int dst);
void graph_destroy(struct graph *g);
void graph_dfs(struct graph *g, int i);
void graph_bfs(struct graph *g, int i);
#endif
