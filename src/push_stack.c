/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:08:16 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/02 19:26:38 by kben-tou         ###   ########.fr       */
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

static void push(t_stack **head, t_stack *node)
{
    if (!node)
        return ;
    t_stack *tmp;

    tmp = *head;
    *head = node;
    node -> next = tmp;
}

void pa(t_stack **a, t_stack **b)
{
    if (!a || !b || !*b)
        return ;
    push(a, *b);
    ft_printf("pa");
}

void pb(t_stack **a, t_stack **b)
{
    if (!a || !b || !*a)
        return ;
    t_stack *last_node;
    
    last_node = get_last_node(*a);
    push(b, last_node);
    if (*a && last_node)
        last_node->prev->next = NULL;
    free(last_node);
    ft_printf("pb");
}