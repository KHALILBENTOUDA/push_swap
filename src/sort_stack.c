/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/10 00:48:55 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_stack_sorted(t_stack **a)
{
    if (!*a || !a)
        return (0);
    t_stack *list = *a;
    while (list->next)
    {
        if (list->value > list->next->value)
            return (1);
        list = list->next;
    }
    return (0);
}

int is_in_lis(int *lis, int lis_size, int nb)
{
    int i;

    i = 0;
    while (i < lis_size)
    {
        if (lis[i] == nb)
            return (1);
        i++;
    }
    
    return (0);
}

static int get_index_node(t_stack *stack, int node_value)
{
    int i;

    i = 0;
    while(stack)
    {
        if (stack->value == node_value)
            return (i);
        i++;
        stack = stack->next;
    }
    return (i);
}

static int next_number(t_stack *list, int nb_b, int size_a)
{
    int next;
    int i;

    if (!list)
        return (0);
    next = get_smallest_node(list)->value;
    i = size_a;
    while (list && list->next)
    {
        if (nb_b > list->value && nb_b < list->next->value)
        {
            next = list->next->value;
            break;
        }
        list = list ->next;
    }
    return (next);
}

static int calculate_moves(t_stack **a, t_stack **b, int next_nb, int nb)
{
    int moves;
    int a_size;
    int b_size;
    int pos_next;
    int pos_nb;

    moves = 0;
    a_size = stack_size(*a);
    b_size = stack_size(*b);
    pos_next = get_index_node(*a, next_nb);
    pos_nb = get_index_node(*b, nb);
    if (pos_next >= a_size / 2)
        moves = a_size - pos_next;
    else
        moves = pos_next;
    if (pos_nb >= b_size / 2)
        moves += b_size - pos_nb;
    else
        moves += pos_nb;
    // printf("%d (%d) \n",nb, moves);
    return (moves);
}

static int get_less_mover_b(t_stack **a, t_stack **b, int nb_b)
{
    int next_nb;
    int hold;
    int less;
    int start;
    t_stack *iter_b;

    next_nb = 0;
    iter_b = *b;
    next_nb = next_number(*a, nb_b, stack_size(*a));
    less = calculate_moves(a, b, next_nb, nb_b);
    start = nb_b;
    while (iter_b)
    {
        next_nb = next_number(*a, iter_b->value, stack_size(*a));
        hold = calculate_moves(a, b, next_nb, iter_b->value);
        if (hold <= less)
        {
            less = hold;
            start = iter_b->value;
        }
        iter_b = iter_b->next;
    };
    return (start);
}

static void push_to_a(t_stack **a, t_stack **b, int nb_b)
{
    int next_nb;
    int next_index;
    int nb_index;

    next_nb = next_number(*a, nb_b, stack_size(*a));
    next_index = get_index_node(*a, next_nb);
    nb_index = get_index_node(*b, nb_b);
    if ((next_index >= stack_size(*a) / 2) && (nb_index >= stack_size(*b) / 2))
    {
        while (next_nb != (*a)->value && nb_b != (*b)->value)
            rrr(b, a);
    }
    else if ((next_index < stack_size(*a) / 2) && (nb_index < stack_size(*b) / 2))
    {
        while (next_nb != (*a)->value && nb_b != (*b)->value)
            rr(b, a);
    }
    if (next_index >= (stack_size(*a) / 2))
    {
        while (next_nb != (*a)->value)
            rra(a);
    }
    else
    {
        while (next_nb != (*a)->value)
            ra(a);
    }
    if (nb_index >= (stack_size(*b) / 2))
    {
        while (nb_b != (*b)->value)
            rrb(b);
    }
    else
    {
        while (nb_b != (*b)->value)
            rb(b);
    }
    pa(a, b);
}

void sort_stack_a(t_stack **a, t_stack **b)
{
    int lis_size;
    int *lis = get_lis(a, stack_size(*a), &lis_size);
    int less_moves;
    int i;
    i =  stack_size(*a);
    while (i >= 0 )
    {
        if (is_in_lis(lis, lis_size, (*a)->value))
            ra(a);
        else
            pb(a, b);
        i--;
    }
    while ((*b))
    {
        less_moves = get_less_mover_b(a, b, (*b)->value);
        push_to_a(a, b, less_moves);
    }
    
    // push_to_a_with_sort(a, b);
    // Rotate to the smallest element
    while ((*a)->value != get_smallest_node(*a)->value)
    {
        if (get_index_node(*a, (*a)->value) >= stack_size(*a) / 2)
            rra(a);
        else
            ra(a);
    }
    // Print the sorted stack
    // t_stack *temp = *a;
    // i = 0;
    // while (lis[i])
    // {
    //     printf("{%d} ", lis[i]);
    //     i++;
    // }
}
