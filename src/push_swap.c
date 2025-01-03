/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:37:35 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/03 15:42:06 by kben-tou         ###   ########.fr       */
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
            last_node = get_last_node(last_node);
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
        ft_printf("%d \n",stack->value);
        stack = stack->next;
    }
}
void af()
{
    system("leaks a.out");
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
    sa(&a);
    pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    // ra(&a);
    // rb(&b);
    // rra(&a);
    // rrb(&b);
    // sa(&a);
    // pa(&a, &b);
    // pa(&a, &b);
    // pa(&a, &b);
    printf_stack(a);
    printf("\n");
    printf_stack(b);
    return (0);
}
