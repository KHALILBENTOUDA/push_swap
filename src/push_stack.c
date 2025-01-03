/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:08:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/03 12:32:13 by kben-tou         ###   ########.fr       */
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
    t_stack *last_node;
    t_stack *last_head;

    if (!stack || !*stack || !head)
        return ;
    last_node = get_last_node(*stack);
    if ((*stack)->next == NULL)
        *stack = NULL;
    else
        last_node->prev->next = NULL;
    last_node->prev = NULL;
    if (*head != NULL)
    {
        last_head = get_last_node(*head);
        last_node->prev = last_head;
        last_head->next = last_node;
    }
    else
        (*head) = last_node;
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