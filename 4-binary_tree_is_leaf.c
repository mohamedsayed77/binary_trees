#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Check if a node is a leaf
 * A leaf node is one that has no children (neither left nor right).
 * @node: Pointer to the node to check
 * Return: 1 if the node is a leaf, 0 otherwise
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
