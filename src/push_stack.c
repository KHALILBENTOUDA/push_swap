/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:08:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/06 22:55:32 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last_node(t_stack *list)
{
    if (!list)
        return (NULL);
    while (list -> next)
        list = list->next;
    return (list);
}

static void push(t_stack **head, t_stack **stack)
{
    t_stack *node;

    if (!stack || !*stack || !head)
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

void pa(t_stack **a, t_stack **b)
{
    if (!a || !b || !*b)
        return ;
    push(a, b);
    ft_printf("pa\n");
}

void pb(t_stack **a, t_stack **b)
{
    if (!a || !b || !*a)
        return ;
    push(b, a);
    ft_printf("pb\n");
}