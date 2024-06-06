#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling node of a given node in a binary tree
 * @node: Pointer to the node to check
 * Return: Pointer to the sibling node,
 *  or NULL if the node has no sibling or is NULL
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
