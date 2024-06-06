#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the number of nodes in
 *  a binary tree with at least one child
 * @tree: Pointer to the root node of the tree to count the nodes in
 * Return: Number of nodes with at least one child
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  node = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		node += ((tree->left || tree->right) ? 1 : 0);
		node += binary_tree_nodes(tree->left);
		node += binary_tree_nodes(tree->right);
		return (node);
	}
}
