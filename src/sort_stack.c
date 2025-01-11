/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/11 21:40:21 by kben-tou         ###   ########.fr       */
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

static void to_array(int stack_len, t_stack *iter, int *temp_array)
{
    int i;

    i = 0;
    while (i < stack_len && iter)
    {
        temp_array[i] = iter->value;
        i++;
        iter = iter->next;
    }
}
static int next_number(t_stack *list, int nb_b, int size_a)
{
    int next;
    int *newarr;

    next = get_smallest_node(list)->value;
    newarr = malloc(sizeof(int) * size_a);
    if (!newarr)
        exit(2);
    to_array(size_a, list, newarr);
    int i;
    int j;

    i = 0;
    while (i < size_a)
    {
        j = turn_around(size_a, i);
        if (newarr[i] < nb_b && newarr[j] > nb_b)
            return (newarr[j]);
        i++;
    }
    return (next);
}
static int get_min_index(int array[], int size)
{
    int i;
    int min_i;

    i = 0;
    min_i = 0;
    while (i < size)
    {
        if (array[i] <= array[min_i])
            min_i = i;
        i++;
    }
    return (min_i);
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

        if (hold < less || (hold == less && get_index_node(*a, next_nb) > get_index_node(*a, start)))
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
    int *lis = get_lis(a, stack_size(*a), &lis_size);
    int less_moves;
    int i;
    int check;

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
    while ((*b))
    {
        less_moves = get_less_mover_b(a, b, (*b)->value);
        push_to_a(a, b, less_moves);
    }
    
    // push_to_a_with_sort(a, b);
    // Rotate to the smallest element
    while ((*a)->value != get_smallest_node(*a)->value)
    {
        if (get_index_node(*a,  get_smallest_node(*a)->value) >= stack_size(*a) / 2)
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
  
 
// rr
// rr   
// pa   
// ra   
// pa   
// rra   
// pa   
// rr   
// ra   
// ra   
// ra   
// pa 


// ra
// ra
// rrb
// pa
// ra
// rrb
// pa
// rrb
// pa
// ra
// ra
// ra
// rb
// pa
