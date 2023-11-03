#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: First node.
 * @second: Second node.
 *
 * Return: Pointer to the lowest common ancestor, or NULL if not found.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *node1 = first;
	const binary_tree_t *node2 = second;
	
	if (first == NULL || second == NULL)
		return (NULL);
	
	while (node1 != node2)
	{
		node1 = (node1 == NULL) ? second : node1->parent;
		node2 = (node2 == NULL) ? first : node2->parent;
	}
	return ((binary_tree_t *)node1);
}
