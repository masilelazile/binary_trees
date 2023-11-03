/**
 * heapify_down - Reorganizes the heap by bubbling down the root
 * @root: Pointer to the root of the heap
 */

void heapify_down(heap_t *root)
{
	heap_t *largest, *temp;

	while (root->left)
	{
		largest = root->left;
		if (root->right && root->right->n > largest->n)
			largest = root->right;

		if (largest->n <= root->n)
			break;

		temp = root->n;
		root->n = largest->n;
		largest->n = temp;

		root = largest;
	}
}

/**
 * heap_extract - Extracts the max value of a max binary heap
 * @root: Double pointer to the root of the heap
 *
 * Return: The extracted maximum value, or 0 if the heap is empty.
 */

int heap_extract(heap_t **root)
{
	int max_value;

	if (!root || !*root)
		return (0);

	max_value = (*root)->n;

	(*root)->n = get_last_node(*root)->n;
	remove_last_node(*root);

	heapify_down(*root);

	return max_value;
}
