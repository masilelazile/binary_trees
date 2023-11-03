#include "binary_trees.h"

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 * @min: The minimum value a node in the tree can have.
 * @max: The maximum value a node in the tree can have.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */

int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	int left_height = height(tree->left);
	int right_height = height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
	        is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return is_avl_helper(tree, INT_MIN, INT_MAX);
}

/**
 * height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree.
 */

int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left = height(tree->left);
	int right = height(tree->right);

	return ((left > right) ? left + 1 : right + 1);
}

