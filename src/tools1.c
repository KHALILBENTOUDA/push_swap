/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:22:39 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/13 16:03:19 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigest_item(t_stack *a)
{
	int	big;

	if (!a)
		exit(1);
	big = a->value;
	while (a)
	{
		if (a->value > big)
			big = a->value;
		a = a->next;
	}
	return (big);
}

t_stack	*get_smallest_node(t_stack *a)
{
	t_stack	*small;

	if (!a)
		return (NULL);
	small = a;
	while (a)
	{
		if (a->value < small->value)
			small = a;
		a = a->next;
	}
	return (small);
}

t_stack	*add_new_node(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = content;
	node->next = NULL;
	return (node);
}

int	stack_size(t_stack *a)
{
	int	counter;

	counter = 0;
	if (!a)
		return (0);
	while (a)
	{
		counter++;
		a = a->next;
	}
	return (counter);
}

int	next_number(t_stack *list, int nb_b, int size_a)
{
	int		next;
	int		*newarr;
	int		i;
	int		j;

	next = get_smallest_node(list)->value;
	newarr = malloc(sizeof(int) * size_a);
	if (!newarr)
		exit(1);
	to_array(size_a, list, newarr);
	i = 0;
	while (i < size_a)
	{
		j = turn_around(size_a, i);
		if (newarr[i] < nb_b && newarr[j] > nb_b)
		{
			next = newarr[j];
			break ;
		}
		i++;
	}
	free(newarr);
	return (next);
}
