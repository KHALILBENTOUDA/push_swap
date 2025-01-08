/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:35:49 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/05 15:09:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
{
    if (!stack && !*stack)
        return ;
    t_stack *first_node;
    t_stack *last_node;

    last_node = get_last_node(*stack);
    first_node = (*stack);
    *stack = first_node->next;
    (*stack)->prev = NULL;
    first_node->next = NULL;
    first_node->prev = last_node;
    last_node->next = first_node;
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