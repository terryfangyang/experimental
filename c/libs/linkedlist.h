struct node {
	struct node *next;
	void *data;
};

struct list {
	int elementSize;
	int listLength;
	struct node *head;
	struct node *tail;
	void (*freeFuc)(void*);
};

void list_new(struct list **list, int elementSize, void (*freeFuc)(void*));
void list_destroy(struct list **list);

void list_prepend(struct list *list, void *element);
void list_append(struct list *list, void *element);
int list_size(struct list *list);

void list_for_each(struct list *list, void (*listIterator)(void*));
void list_del(struct list *list,void *element, int (*cmp)(void*, void*));
