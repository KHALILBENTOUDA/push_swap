/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_moves(t_stack **a, t_stack **b, int next_nb, int nb)
{
	int	nb_index;
	int	next_index;
	int	actions[3];

	nb_index = get_index_node(*b, nb);
	next_index = get_index_node(*a, next_nb);
	if (nb_index > stack_size(*b) / 2)
		actions[0] = stack_size(*b) - nb_index;
	else
		actions[0] = nb_index;
	if (next_index > stack_size(*a) / 2)
		actions[0] += stack_size(*a) - next_index;
	else
		actions[0] += next_index;
	if (nb_index > next_index)
		actions[1] = nb_index;
	else
		actions[1] = next_index;
	if (stack_size(*b) - nb_index > stack_size(*a) - next_index)
		actions[2] = stack_size(*b) - nb_index;
	else
		actions[2] = stack_size(*a) - next_index;
	return (actions[get_min_index(actions, 3)]);
}

static int	get_less_mover_b(t_stack **a, t_stack **b, int nb_b)
{
	int		next_nb;
	int		hold;
	int		less;
	int		start;
	t_stack	*iter_b;

	next_nb = 0;
	iter_b = *b;
	less = INT_MAX;
	start = nb_b;
	while (iter_b)
	{
		next_nb = next_number(*a, iter_b->value, stack_size(*a));
		hold = calculate_moves(a, b, next_nb, iter_b->value);
		if (hold <= less)
		{
			less = hold;
			start = iter_b->value;
		}
		iter_b = iter_b->next;
	}
	return (start);
}

static void	push_to_a(t_stack **a, t_stack **b, int nb_b)
{
	int	next_nb;
	int	next_index;
	int	nb_index;

	next_nb = next_number(*a, nb_b, stack_size(*a));
	next_index = get_index_node(*a, next_nb);
	nb_index = get_index_node(*b, nb_b);
	while ((next_nb != (*a)->value && nb_b != (*b)->value))
	{
		if ((next_index > stack_size(*a) / 2) && \
			(nb_index > stack_size(*b) / 2))
			rrr(b, a, 0);
		else if ((next_index < stack_size(*a) / 2) && \
			(nb_index < stack_size(*b) / 2))
			rr(b, a, 0);
		else
			break ;
	}
	ft_rotate_a(a, next_index, next_nb);
	ft_rotate_b(b, nb_index, nb_b);
	pa(a, b, 0);
}

static void	init_b(t_stack **a, t_stack **b)
{
	int	lis_size;
	int	*lis;
	int	i;
	int	check;

	lis = get_lis(*a, stack_size(*a), &lis_size);
	check = stack_size(*a) - lis_size;
	i = stack_size(*a);
	while (i >= 0)
	{
		if (is_in_lis(lis, lis_size, (*a)->value))
			ra(a, 0);
		else
		{
			pb(a, b, 0);
			if (--check <= 0)
				break ;
		}
		i--;
	}
	free(lis);
}

void	sort_stack_a(t_stack **a, t_stack **b)
{
	int	less_moves;

	less_moves = 0;
	init_b(a, b);
	while (*b)
	{
		less_moves = get_less_mover_b(a, b, (*b)->value);
		push_to_a(a, b, less_moves);
	}
	while ((*a)->value != get_smallest_node(*a)->value)
	{
		if (get_index_node(*a, get_smallest_node(*a)->value) \
			> stack_size(*a) / 2)
			rra(a, 0);
		else
			ra(a, 0);
	}
}
