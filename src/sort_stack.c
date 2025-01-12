/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/12 11:05:13 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int next_number(t_stack *list, int nb_b, int size_a)
{
    int next;
    int *newarr;

    next = get_smallest_node(list)->value;
    newarr = malloc(sizeof(int) * size_a);
    if (!newarr)
        exit(1);
    to_array(size_a, list, newarr);
    int i;
    int j;

    i = 0;
    while (i < size_a)
    {
        j = turn_around(size_a, i);
        if (newarr[i] < nb_b && newarr[j] > nb_b)
        {
            next = newarr[j];
            break;
        }
        i++;
    }
    free(newarr);
    return (next);
}


static int calculate_moves(t_stack **a, t_stack **b, int next_nb, int nb)
{
    int nb_index;
    int next_index;
    int actions[3];

    nb_index = get_index_node(*b, nb);
    next_index = get_index_node(*a, next_nb);
    if (nb_index >= stack_size(*b) / 2)
        actions[0] = stack_size(*b) - nb_index;
    else
        actions[0] = nb_index;
    if (next_index >= stack_size(*a) / 2)
        actions[0] += stack_size(*a) - next_index;
    else
        actions[0] += next_index;
    if (nb_index > next_index)
        actions[1] = nb_index;
    else
        actions[1] = next_index;
    if (stack_size(*b) - nb_index > stack_size(*a) - next_index)
        actions[2] = stack_size(*b) - nb_index ;
    else
        actions[2] = stack_size(*a) - next_index;
    return (actions[get_min_index(actions, 3)]);
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
    less = INT_MAX;
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
    }
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
    while ((next_nb != (*a)->value && nb_b != (*b)->value))
    {
        if ((next_index >= stack_size(*a) / 2) && (nb_index >= stack_size(*b) / 2))
            rrr(b, a);
        else if ((next_index < stack_size(*a) / 2) && (nb_index < stack_size(*b) / 2))
            rr(b, a);
        else
            break;
    }
    while (next_nb != (*a)->value) {
        if (next_index >= stack_size(*a) / 2)
            rra(a);
        else
            ra(a);
    }
    while (nb_b != (*b)->value) {
        if (nb_index >= stack_size(*b) / 2)
            rrb(b);
        else
            rb(b);
    }
    pa(a, b);
}

void sort_stack_a(t_stack **a, t_stack **b)
{
    int lis_size;
    int *lis;
    int less_moves;
    int i;
    int check;

    lis = get_lis(a, stack_size(*a), &lis_size);
    check = stack_size(*a) - lis_size;
    i =  stack_size(*a);
    while (i >= 0 )
    {
        if (is_in_lis(lis, lis_size, (*a)->value))
            ra(a);
        else
        {
            pb(a, b);
            if (--check <= 0)
                break;
        }
        i--;
    }
    free (lis);
    while ((*b))
    {
        less_moves = get_less_mover_b(a, b, (*b)->value);
        push_to_a(a, b, less_moves);
    }
    while ((*a)->value != get_smallest_node(*a)->value)
    {
        if (get_index_node(*a, get_smallest_node(*a)->value) >= stack_size(*a) / 2)
            rra(a);
        else
            ra(a);
    }
}
  
