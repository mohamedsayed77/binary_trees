#include "binary_trees.h"

/**
 * aux_sort - Recursively creates an AVL tree from a sorted array.
 * @parent: Pointer to the parent node.
 * @array: Pointer to the sorted array.
 * @begin: Starting index of the subarray.
 * @last: Ending index of the subarray.
 * Return: Pointer to the root of the AVL tree.
 */

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int mid = 0;

	if (begin <= last)
	{
		mid = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[mid]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, mid - 1);
		root->right = aux_sort(root, array, mid + 1, last);
		return (root);
	}
	return (NULL);
}

/**
 * sorted_array_to_avl - Creates an AVL tree from a sorted array.
 * @array: Pointer to the sorted array.
 * @size: Size of the sorted array.
 * Return: Pointer to the root of the AVL tree.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}
