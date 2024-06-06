#include "binary_trees.h"


/**
 * tree_is_perfect - Check if a binary tree is perfect
 * A binary tree is considered perfect if it has the same number of levels
 * in the left and right subtrees,
 * and each node has either zero or two children.
 * @tree: Pointer to the root node of the tree to check
 * Return: The level of height if the tree is perfect, 0 otherwise
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (tree->left && tree->right)
	{
		l = 1 + tree_is_perfect(tree->left);
		r = 1 + tree_is_perfect(tree->right);
		if (r == l && r != 0 && l != 0)
			return (r);
		return (0);
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

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * A binary tree is considered perfect if it has the same number of levels
 * in the left and right subtrees,
 * and each node has either zero or two children.
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
		{
			return (1);
		}
		return (0);
	}
}
