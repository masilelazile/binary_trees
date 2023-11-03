#include "binary_trees.h"

/**
 * bst_search - Find a node with a specific value in a Binary Search Tree (BST).
 * @tree: Pointer to the root of the tree to search.
 * @value: The value to find in the BST.
 * Return: Pointer to the node with the given value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	
	if (value == tree->n)
		return ((bst_t *)tree);
	
	if (value < tree->n)
		return bst_search(tree->left, value);
	else
		return bst_search(tree->right, value);
}
