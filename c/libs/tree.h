#ifndef __BTREE_H
#define  __BTREE_H

struct BTree {
	struct BTree *lchild;
	struct BTree *rchild;
	int data;
};

int bt_depth(struct BTree *root);
void bt_insertNode(struct BTree **root, int value);
void bt_inorder(struct BTree *root);
void bt_destroy(struct BTree *root);
#endif
