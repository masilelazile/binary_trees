#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

static void print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	if (!tree)
		return;
	
	int width = printf("(%03d)", tree->n);
	
	if (tree->left)
	{
		s[depth + 1][offset - width / 2] = '|';
		s[depth + 2][offset - width / 2] = '|';
	}
	
	if (tree->right)
	{
		s[depth + 1][offset + width + width / 2] = '|';
		s[depth + 2][offset + width + width / 2] = '|';
	}
	
	snprintf(&s[depth][offset - width / 2], width + 1, "(%03d)", tree->n);
	
	print_t(tree->left, offset - width / 2 - 1, depth + 3, s);
	print_t(tree->right, offset + width + width / 2 + 1, depth + 3, s);
}

void binary_tree_print(const binary_tree_t *tree)
{
	if (!tree)
		return;
	
	int height = _height(tree);
	char **s = malloc(sizeof(char *) * (3 * height + 1));
	
	if (!s)
		return;
	
	for (int i = 0; i < 3 * height + 1; i++) 
	{
		s[i] = malloc(255);
		if (!s[i])
		{
			for (int j = 0; j < i; j++)
				free(s[j]);
			free(s);
			return;
		}
		memset(s[i], ' ', 254);
		s[i][254] = '\0';
	}
	
	print_t(tree, 254 / 2, 0, s);
	
	for (int i = 0; i < 3 * height + 1; i++)
	{
		int j = 254;
		
		while (s[i][j] == ' ')
			
			j--;
		s[i][j + 1] = '\0';
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
