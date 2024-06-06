#include "binary_trees.h"

/**
 * check_sub_tree_Left - Check if all nodes in the subtree are smaller than
 * the specified root value.
 * @node: Pointer to the current node in the subtree
 * @max: Value to compare with the root node's value
 * Return: 1 if all nodes are smaller or equal, 0 otherwise
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_Left(node->left, max);
		right = check_sub_tree_Left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * check_sub_tree_Right - Check if all nodes in the subtree are bigger than the
 * specified root value.
 * @node: Pointer to the current node in the subtree
 * @min: Value to compare with the root node's value
 * Return: 1 if all nodes are bigger or equal, 0 otherwise
 */

int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0, right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_Right(node->left, min);
		right = check_sub_tree_Right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst - Check if a binary tree is a binary search tree (BST).
 * The process involves verifying that the left subtree contains nodes smaller
 * than the root and the right subtree contains nodes bigger than the root.
 * @tree: Pointer to the root node of the binary tree
 * Return: 1 if it is a BST, 0 otherwise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, left = 2, right = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
