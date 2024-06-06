#include "binary_trees.h"

/**
 * binary_tree_insert_right - Insert a node as the right child of a parent node
 * If the parent already has a right child, the new node is placed above the
 * existing right child, pushing it down one level.
 * @parent: Pointer to the parent node
 * @value: Integer value to be stored in the new node
 * Return: Pointer to the newly created node, or NULL if the operation fails
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}
	parent->right = new_node;
	return (new_node);
}
