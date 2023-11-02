#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: Pointer to the root node of the tree to count the nodes.
 *
 * Return: If tree is NULL, the function returns 0.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	return (tree->left != NULL || tree->right != NULL) +
		binary_tree_nodes(tree->left) +
		binary_tree_nodes(tree->right);
}
