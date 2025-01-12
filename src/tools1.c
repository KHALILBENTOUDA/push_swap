/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:22:39 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/12 13:24:16 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int bigest_item(t_stack *a)
{
    int big;
    if (!a)
        exit(1);
    big = a->value;
    while (a)
    {
        if (a->value > big)
            big = a->value;
        a = a->next;
    }
    return (big);
}

t_stack *get_smallest_node(t_stack *a)
{
    t_stack *small;
    if (!a)
        return (NULL);
    small = a;
    while (a)
    {
        if (a->value < small->value)
            small = a;
        a = a->next;
    }
    return (small);
}

t_stack *add_new_node(int content)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node -> value = content;
    node -> next = NULL;
    return (node);
}

int stack_size(t_stack *a)
{
    int counter;

    counter = 0;
    if (!a)
        return (0);
    while (a)
    {
        counter++;
        a = a->next;
    }
    return (counter);
}