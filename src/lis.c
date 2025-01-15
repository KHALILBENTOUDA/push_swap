/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:17 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/13 12:35:55 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*find_the_lis(int *lis, int *temp_array, int stack_len)
{
	int		i;
	int		j;
	int		a;
	int		hold_value;

	i = 0;
	while (i < stack_len)
	{
		hold_value = temp_array[i];
		a = 1;
		j = turn_around(stack_len, i);
		while (j != i)
		{
			if (temp_array[j] > hold_value)
			{
				a++;
				hold_value = temp_array[j];
			}
			j = turn_around(stack_len, j);
		}
		lis[i] = a;
		i++;
	}
	return (lis);
}

static void	find_max_lis(int *lis, int *max, int stack_len, int *index)
{
	int		i;

	i = 0;
	while (i < stack_len)
	{
		if (lis[i] > *max)
		{
			*max = lis[i];
			*index = i;
		}
		i++;
	}
}

static int	*fill_and_compare_lis(int *final_lis, int *lis, \
int *temp_array, int stack_len)
{
	int		j;
	int		first_position;
	int		b;
	int		max_index;
	int		max_lis;

	b = 0;
	find_max_lis(lis, &max_lis, stack_len, &max_index);
	final_lis[b++] = temp_array[max_index];
	first_position = max_index;
	j = turn_around(stack_len, max_index);
	while (j != first_position)
	{
		if (temp_array[j] > temp_array[max_index])
		{
			final_lis[b] = temp_array[j];
			b++;
			max_index = j;
		}
		j = turn_around(stack_len, j);
	}
	return (final_lis);
}

void	init_array(int stack_len, t_stack *iter, int *temp_array, int *lis)
{
	int		i;

	i = 0;
	if (!iter)
		return ;
	while (i < stack_len && iter)
	{
		temp_array[i] = iter->value;
		lis[i] = 1;
		i++;
		iter = iter->next;
	}
}

int	*get_lis(t_stack *iter, int stack_len, int *lis_size)
{
	int		*lis;
	int		*temp_array;
	int		*final_lis;
	int		max_lis;
	int		max_index;

	max_lis = 0;
	max_index = 0;
	lis = malloc(sizeof(int) * stack_len);
	if (!lis)
		exit(1);
	temp_array = malloc(sizeof(int) * stack_len);
	if (!temp_array)
		exit(1);
	init_array(stack_len, iter, temp_array, lis);
	lis = find_the_lis(lis, temp_array, stack_len);
	find_max_lis(lis, &max_lis, stack_len, &max_index);
	final_lis = malloc(sizeof(int) * max_lis);
	if (!final_lis)
		exit(1);
	final_lis = fill_and_compare_lis(final_lis, lis, temp_array, stack_len);
	*lis_size = max_lis;
	return (free(temp_array), free(lis), final_lis);
}
