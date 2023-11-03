#include "binary_trees.h"

/**
 * copy_heap - Creates a copy of a max heap
 * @root: Pointer to the root of the original heap
 *
 * Return: Pointer to the root of the copied heap
 */

heap_t *copy_heap(heap_t *root)
{
	if (!root)
		return (NULL);

	return binary_tree_node(
		copy_heap(root->left),
		root->n,
		copy_heap(root->right)
	);
}

/**
 * heap_to_sorted_array - Creates a sorted array from a max heap
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 *
 * Return: Pointer to the sorted array of integers
 */

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;

	if (!heap)
		return (NULL);

	heap_t *heap_copy = copy_heap(heap);

	if (!heap_copy)
		return (NULL);

	nodes = count_h_nodes(heap_copy);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
	{
		free(heap_copy);
		return (NULL);
	}

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap_copy);

	free(heap_copy);

	return (arr);
}

