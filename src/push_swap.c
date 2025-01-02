/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:37:35 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/02 18:15:29 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void fill_stack(t_stack **a, char **content)
{
    int i;
    t_stack *last_node;
    t_stack *new_node;

    i = 1;
    last_node = NULL;
    while(content[i])
    {
        new_node = add_new_node(ft_atoi(content[i]));
        if (*a)
        {
            last_node = *a;
            while(last_node->next)
                last_node = last_node->next;
            new_node->prev = last_node;
            last_node->next = new_node;
        }
        else
        {
            *a = new_node;
            new_node->prev = NULL;
        }
        i++;
    }
}

void printf_stack(t_stack *stack)
{
    if (!stack)
        return ;
    while (stack != NULL)
    {
        ft_printf("%d, ",stack->value);
        stack = stack->next;
    }
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (ac < 2)
        ft_printf("Error\n");
    fill_stack(&a,av);
    pb(&a, &b);
    printf_stack(a);
    ft_printf("\n");
    printf_stack(b);

    return (0);
}
