/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:19:55 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/15 10:22:33 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a)
{
	if ((*a)->value == bigest_item(*a))
		ra(a, 0);
	else if ((*a)->next->value == bigest_item(*a))
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}

static t_stack	*get_top_node(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	sort_four_five(t_stack **a, t_stack **b, int size_s)
{
	t_stack	*small;
	int		index;

	index = 0;
	while (size_s > 3)
	{
		small = get_smallest_node(*a);
		index = get_index_node(*a, small->value);
		while ((*a)->value != small->value)
		{
			if (index > stack_size(*a) / 2)
				rra(a, 0);
			else
				ra(a, 0);
		}
		pb(a, b, 0);
		size_s--;
	}
	sort_three(a);
	while (*b)
		pa(a, b, 0);
}

void	fill_stack(t_stack **a, char **content)
{
	int			i;
	t_stack		*top_node;
	t_stack		*new_node;

	i = 0;
	top_node = NULL;
	while (content[i])
	{
		new_node = add_new_node(ft_atoi(content[i]));
		if (*a)
		{
			top_node = get_top_node(*a);
			new_node->prev = top_node;
			top_node->next = new_node;
		}
		else
		{
			*a = new_node;
			new_node->prev = NULL;
		}
		i++;
	}
	ft_free(content);
}
