/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:37:35 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/11 16:25:30 by kben-tou         ###   ########.fr       */
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

void fill_stack(t_stack **a, char **content, int ac)
{
    int i;
    t_stack *last_node;
    t_stack *new_node;

    i = 0;
    if (ft_strncmp(content[0], "./push_swap", ft_strlen(content[0])) == 0)
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
    if (ac == 2)
        ft_free(content);
}

void printf_stack(t_stack *stack)
{
    if (!stack)
        return ;
    while (stack != NULL)
    {
        ft_printf("(%d )\n",stack->value);
        stack = stack->next;
    }
}

t_stack *bigest_item(t_stack *a)
{
    t_stack *big;
    if (!a)
        return (NULL);
    big = a;
    while (a)
    {
        if (a->value > big->value)
            big = a;
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

void sort_three(t_stack **a)
{
    if (*a == bigest_item(*a))
        ra(a);
    else if ((*a)->next == bigest_item(*a))
        ra(&(*a)->next);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void sort_five(t_stack **a, t_stack **b, int size_s)
{
    t_stack *small;

    
    while (size_s > 3)
    {
        small = get_smallest_node(*a);
        while (*a != small)
            ra(a);
        pb(a, b);
        size_s--;
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}
void push_swap_sort(t_stack **a, t_stack **b)
{
    int size_s;

    size_s = 0;
    if (is_stack_sorted(a))
    {
        size_s = stack_size(*a);
        if (size_s == 2)
            sa(a);
        else if (size_s == 3)
            sort_three(a);
        else if (size_s <= 5)
            sort_five(a, b, size_s);
        else
            sort_stack_a(a, b);
    }
    is_stack_sorted(b);
}
void af()
{
    system("leaks push_swap");
}


int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    // atexit(af);
    a = NULL;
    b = NULL;
    if (ac < 2)
        return (0);
    av = check_input(av, ac);
    fill_stack(&a, av, ac);
    push_swap_sort(&a, &b);
    // printf("\n");
    // printf_stack(a);
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
}
