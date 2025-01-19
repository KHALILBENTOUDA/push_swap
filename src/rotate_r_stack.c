/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:35:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/18 17:13:57 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack		*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = (*stack);
	last_node->prev->next = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack **a, int checker)
{
	rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **b, t_stack **a, int checker)
{
	rotate(b);
	rotate(a);
	if (!checker)
		write(1, "rrr\n", 4);
}
