#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array of integers.
 * @array: The array to convert into an AVL tree.
 * @size: The size of the array.
 * Return: A pointer to the root node of the AVL tree, or NULL if failed.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
