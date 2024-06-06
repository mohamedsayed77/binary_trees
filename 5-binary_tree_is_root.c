#include "binary_trees.h"

/**
 * binary_tree_is_root - Check if a node is the root of the tree
 * A root node is one that has no parent.
 * @node: Pointer to the node to check
 * Return: 1 if the node is the root, 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}
