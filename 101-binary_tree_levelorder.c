#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree in level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_t *node;
	binary_tree_t *queue[1024];  /* Assuming a maximum of 1024 nodes. You can adjust this value. */
	int front = 0, rear = 0;

	queue[rear] = (binary_tree_t *)tree;
	rear++;

	while (front < rear)
	{
		node = queue[front];
		front++;

		func(node->n);

		if (node->left)
		{
			queue[rear] = node->left;
			rear++;
		}

		if (node->right)
		{
			queue[rear] = node->right;
			rear++;
		}
	}
}

