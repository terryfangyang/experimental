#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define max(a, b) ((a >= b)?a:b)
int bt_depth(struct BTree *root)
{
	if (root == NULL)
	{
		return 0;
	}

	return (max(bt_depth(root->lchild), bt_depth(root->rchild)) + 1);
}

void bt_insertNode(struct BTree **root, int value)
{
	if ((*root) == NULL) {
	struct BTree *tmp = (struct BTree*)malloc(sizeof(struct BTree));

	tmp->lchild = NULL;
	tmp->rchild = NULL;
	tmp->data = value;

	*root = tmp;
	return;

	}

	if (value > (*root)->data)
		bt_insertNode(&(*root)->rchild, value);
	else if (value < (*root)->data)
		bt_insertNode(&(*root)->lchild, value);

}

void bt_inorder(struct BTree *root)
{
	if(root)
	{
		bt_inorder(root->lchild);
		printf("btree inorder %d\n", root->data);
		bt_inorder(root->rchild);
	}
}

void bt_destroy(struct BTree *root)
{

	if(root)
	{
		bt_destroy(root->lchild);
		bt_destroy(root->rchild);
		free(root);
	}
}
