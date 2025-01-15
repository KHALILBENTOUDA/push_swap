/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:35:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/15 13:39:33 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack		*first_node;
	t_stack		*last_node;

	last_node = get_last_node(*stack);
	first_node = (*stack);
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
}

void	ra(t_stack **a, int checker)
{
	rotate(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int checker)
{
	rotate(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack **b, t_stack **a, int checker)
{
	rotate(b);
	rotate(a);
	if (!checker)
		write(1, "rr\n", 3);
}
