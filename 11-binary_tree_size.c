#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: If tree is NULL, the function returns 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	size_t n_left = binary_tree_size(tree->left);
	size_t n_right = binary_tree_size(tree->right);
	
	return 1 + n_left + n_right;
}
