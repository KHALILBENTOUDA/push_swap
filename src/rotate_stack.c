/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:35:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/03 14:59:17 by kben-tou         ###   ########.fr       */
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

void ra(t_stack **a)
{
    if (!a || !*a || (*a)->next == NULL)
        return ;
    rotate(a);
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    if (!b || !*b || (*b)->next == NULL)
        return ;
    rotate(b);
    ft_printf("rb\n");
}

void rr(t_stack **b, t_stack **a)
{
    if (!b || !*b || !a || !*a || (*a)->next == NULL ||  (*b)->next == NULL)
        return ;
    rotate(b);
    rotate(a);
    ft_printf("rr\n");
}