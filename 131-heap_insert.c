#include "binary_trees.h"

/**
 * swap - swaps nodes when child is greater than parent
 *
 * @arg_node: parent node
 * @arg_child: child node
 * Return: no return
 */

void swap(heap_t **arg_node, heap_t **arg_child)
{
	heap_t *node, *child;

	node = *arg_node;
	child = *arg_child;

	if (child->n > node->n)
	{
		if (child->left)
			child->left->parent = node;
		if (child->right)
			child->right->parent = node;

		if (node->left == child)
		{
			child->right = node->right;
			if (node->right)
				node->right->parent = child;
			node->right = child;
		}
		else
		{
			child->left = node->left;
			if (node->left)
				node->left->parent = child;
			node->left = child;
		}
		child->parent = node->parent;
		node->parent = child;
		if (child->parent)
		{
			if (child->parent->left == node)
				child->parent->left = child;
			else
				child->parent->right = child;
		}
		else
		{
			*arg_node = child;
		}
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: A double pointer to the root of the Max Heap.
 * @value: The value to insert.
 *
 * Return: A pointer to the newly inserted node.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	new_node = binary_tree_insert_left(*root, value);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap(&new_node->parent, &new_node);
	}
	return (new_node);
}
