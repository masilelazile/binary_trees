#include "binary_trees.h"

/**
 * find_node - function to find a node in a tree
 * @root: root of the tree to evaluate
 * @node: node to find
 * Return: 1 if it exists, 0 if not
 */

int find_node(const binary_tree_t *root, const binary_tree_t *node)
{
	if (root == NULL)
		return (0);
	if (node == root)
		return (1);
	if (node->n < root->n)
			return (find_node(root->left, node));
	if (node->n > root->n)
		return (find_node(root->right, node));
	return (0);
}

/**
 * cross_tree - traverse the tree, checking if each node exists correctly
 * @root: root node of the tree
 * @node: current node to evaluate
 * Return: 1 if it is a BST, 0 if not
 */

int cross_tree(const binary_tree_t *root, const binary_tree_t *node)
{
	if (root && node)
	{
		int aux = 0;
		
		aux = find_node(root, node);
		
		if (node->left)
			aux &= cross_tree(root, node->left);
		if (node->right)
			aux &= cross_tree(root, node->right);
		return (aux);
	}
	return (1);
}

/**
 * binary_tree_is_bst - check if it is a correctly structured BST
 * @tree: tree to check
 * Return: 1 if it is a BST, 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (cross_tree(tree, tree));
}
