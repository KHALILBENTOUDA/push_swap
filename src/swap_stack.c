/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:38:52 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/02 13:05:34 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack **stack)
{
    t_stack *current;
    int swap;

    current = NULL;
    if (!stack)
        return ;
    current = *stack;
    if (current && current->next)
    {
        swap = current->value;
        current->value = current->next->value;
        current->next->value = swap;
    }
}

void sa(t_stack **a)
{
    if (!a || !*a)
        return ;
    swap(a);
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    if (!b || !*b)
        return ;
    swap(b);
    ft_printf("sb\n");
}

void ss(t_stack **a, t_stack **b)
{
    if (!a || !b || !*a || !*b)
        return ;
    swap(a);
    swap(b);
    ft_printf("ss\n");
}