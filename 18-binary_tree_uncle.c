#include "binary_trees.h"

/**
 * binary_tree_uncle - Find the uncle node of a given node in a binary tree
 * @node: Pointer to the node to check
 * Return: Pointer to the uncle node,
 * or NULL if the uncle does not exist or if the node is NULL
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
	{
		return (NULL);
	}
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
