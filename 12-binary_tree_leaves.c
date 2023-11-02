#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if node is a leaf, otherwise 0.
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	
	return (node->right == NULL && node->left == NULL);
}

/**
 * binary_tree_leaves - Counts the number of leaf nodes in a binary tree.
 * @tree: Pointer to the root node of the tree to count the leaves.
 *
 * Return: If tree is NULL, the function returns 0.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	
	return binary_tree_is_leaf(tree) +
		binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right);
}
