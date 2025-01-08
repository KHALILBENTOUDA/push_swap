/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:35:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/05 15:03:22 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    if (!stack && !*stack)
        return ;
    t_stack *last_node;

    last_node = get_last_node(*stack);
    last_node->next = (*stack);
    last_node->prev->next = NULL;
    (*stack)->prev = last_node;
    *stack = last_node;
}

void rra(t_stack **a)
{
    if (!a || !*a || (*a)->next == NULL)
        return ;
    rotate(a);
    ft_printf("rra\n");
}

void rrb(t_stack **b)
{
    if (!b || !*b || (*b)->next == NULL)
        return ;
    rotate(b);
    ft_printf("rrb\n");
}

void rrr(t_stack **b, t_stack **a)
{
    if (!b || !*b || !a || !*a || (*a)->next == NULL ||  (*b)->next == NULL)
        return ;
    rotate(b);
    rotate(a);
    ft_printf("rrr\n");
}