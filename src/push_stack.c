/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:08:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/18 17:13:43 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **head, t_stack **stack)
{
	t_stack	*node;

	if (!stack || !*stack)
		return ;
	node = *stack;
	*stack = node->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	node->next = NULL;
	if (*head != NULL)
	{
		node->prev = NULL;
		node->next = (*head);
		(*head)->prev = node;
		*head = node;
	}
	else
		(*head) = node;
}

void	pa(t_stack **a, t_stack **b, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
