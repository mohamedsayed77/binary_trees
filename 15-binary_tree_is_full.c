#include "binary_trees.h"

/**
 * binary_tree_is_full - Check if a binary tree is full
 * A binary tree is considered full
 * if each node has either zero or two children.
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			left = binary_tree_is_full(tree->left);
			right = binary_tree_is_full(tree->right);
			if (left == 0 || right == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}
