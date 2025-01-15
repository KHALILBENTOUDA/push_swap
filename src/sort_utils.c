/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 10:03:52 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/13 15:57:36 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack **a)
{
	t_stack	*list;

	list = *a;
	if (!*a || !a)
		return (0);
	while (list->next)
	{
		if (list->value > list->next->value)
			return (1);
		list = list->next;
	}
	return (0);
}

int	is_in_lis(int *lis, int lis_size, int nb)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (lis[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	get_min_index(int array[], int size)
{
	int	i;
	int	min_i;

	i = 0;
	min_i = 0;
	while (i < size)
	{
		if (array[i] <= array[min_i])
			min_i = i;
		i++;
	}
	return (min_i);
}

int	get_index_node(t_stack *stack, int node_value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == node_value)
			break ;
		i++;
		stack = stack->next;
	}
	return (i);
}

void	to_array(int stack_len, t_stack *iter, int *temp_array)
{
	int	i;

	i = 0;
	while (i < stack_len && iter)
	{
		temp_array[i] = iter->value;
		i++;
		iter = iter->next;
	}
}
