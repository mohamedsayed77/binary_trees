#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0;
	size_t r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_depth - Calculate the depth of a node in a binary tree
 * @tree: Pointer to the node to calculate the depth for
 * Return: The depth of the node (distance from the root node)
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Add a node to a linked list at a specific level
 * @head: Pointer to the head of the linked list
 * @tree: Pointer to the binary tree node to store
 * @level: Level of the binary tree node
 */

void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
	link_t *new, *aux;

	new = malloc(sizeof(link_t));
	if (new == NULL)
	{
		return;
	}
	new->n = level;
	new->node = tree;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else
	{
		aux = *head;
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		new->next = NULL;
		aux->next = new;
	}
}

/**
 * recursion - Recursively traverse the binary tree
 * and store each node in a linked list
 * @head: Pointer to the head of the linked list
 * @tree: Pointer to the current binary tree node
 */

void recursion(link_t **head, const binary_tree_t *tree)
{
	size_t level = 0;

	if (tree != NULL)
	{
		level = binary_tree_depth(tree);
		linked_node(head, tree, level);
		recursion(head, tree->left);
		recursion(head, tree->right);
	}
}

/**
 * binary_tree_levelorder - Print the nodes of a binary tree in level-order
 * @tree: Pointer to the root node of the binary tree
 * @func: Pointer to the function to call for each node
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *head, *aux;
	size_t height = 0, count = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		head = NULL;
		recursion(&head, tree);
		while (count <= height)
		{
			aux = head;
			while (aux != NULL)
			{
				if (count == aux->n)
				{
					func(aux->node->n);
				}
				aux = aux->next;
			}
			count++;
		}
		while (head != NULL)
		{
			aux = head;
			head = head->next;
			free(aux);
		}
	}
}
