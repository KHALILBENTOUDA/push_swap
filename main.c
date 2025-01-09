/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:56:50 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/09 12:50:02 by kben-tou         ###   ########.fr       */
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
    for (int i = 0; i < lis_size; i++)
    {
        if (lis[i] == nb)
            return (1);
    }
    return (0);
}

// static int get_index_node(t_stack *stack, int node_value)
// {
//     int i;

//     i = 0;
//     while(stack)
//     {
//         if (stack->value == node_value)
//             return (i);
//         i++;
//         stack = stack->next;
//     }
//     return (i);
// }
// static int next_number(t_stack *list, int nb_b, int size_a)
// {
//     int next;
//     int i;

//     next = get_smallest_node(list)->value;
//     i = size_a;
//     while (list && list->next)
//     {
//         if (nb_b > list->value && nb_b < list->next->value)
//         {
//             next = list->next->value;
//             break;
//         }
//         list = list ->next;
//     }
//     return (next);
// }

// static int smallest_action_nb(t_stack **a, t_stack **b, int next, int nb_b)
// {
//     int size_a;
//     int size_b;
//     int nb_b_index;
//     int next_index;
//     int actions[3];
//     int action_numbers;

//     size_b = stack_size(*b);
//     size_a = stack_size(*a);
//     size_a = next;
//     nb_b_index = get_index_node(*b, nb_b);
//     next_index = get_index_node(*a, next);
//     // printf("-%d)\n",nb_b_index);
// 	// printf("-%d)\n",next_index);
//     if (nb_b_index < size_b / 2)
//         actions[0] = nb_b_index;
//     else
//         actions[0] = size_b - nb_b_index;

//     if (next_index < size_a / 2)
//         actions[0] += next_index;
//     else
//         actions[0] += size_a - next_index;
        
//     if (nb_b_index > next_index)
//         actions[1] = nb_b_index;
//     else
//         actions[1] = next_index;

//     if (size_b - nb_b_index > size_a - next_index)
//         actions[2] = size_b - nb_b_index;
//     else
//         actions[2] = size_a - next_index;
//     action_numbers = actions[0];
//     if (actions[1] < action_numbers)
//         action_numbers = actions[1];
//     if (actions[2] < action_numbers)
//         action_numbers = actions[2];
//     return (action_numbers);
// }

// static int get_fit_actions(t_stack **a, t_stack **b, int next, int nb_b)
// {
//     int size_a;
//     int size_b;
//     int nb_b_index;
//     int next_index;
//     int actions[3];
//     int action_numbers;

//     size_b = stack_size(*b);
//     size_a = stack_size(*a);
//     size_a = next;
//     nb_b_index = get_index_node(*b, nb_b);
//     next_index = get_index_node(*a, next);
//     int fit;

//     fit = 0;
//     // printf("-%d)\n",nb_b_index);
// 	// printf("-%d)\n",next_index);
//     if (nb_b_index < size_b / 2)
//         actions[0] = nb_b_index;
//     else
//         actions[0] = size_b - nb_b_index;

//     if (next_index < size_a / 2)
//         actions[0] += next_index;
//     else
//         actions[0] += size_a - next_index;
        
//     if (nb_b_index > next_index)
//         actions[1] = nb_b_index;
//     else
//         actions[1] = next_index;

//     if (size_b - nb_b_index > size_a - next_index)
//         actions[2] = size_b - nb_b_index;
//     else
//         actions[2] = size_a - next_index;
//     action_numbers = actions[0];
//     if (actions[1] < action_numbers)
//     {
//         action_numbers = actions[1];
//         fit = 1;
//     }
//     if (actions[2] < action_numbers)
//     {
//         action_numbers = actions[2];
//         fit = 2;
//     }
//     return (fit);
// }

// static t_stack *get_node_with_index(t_stack *stack, int index)
// {
//     int i;

//     i = 0;
//     while (stack)
//     {
//         if (i == index)
//             break;
//         i++;
//         stack = stack->next;
//     }
//     return (stack);
// }

// static int find_the_right_nb(t_stack **a, t_stack **b)
// {
//     int size_b;
//     int size_a;
//     int next;
//     int indic_b;
//     t_stack *iter_b;
//     int check;
//     int k;
//     int right;

//     size_b = stack_size(*b);
//     size_a = stack_size(*a);
//     indic_b = 0;
//     next = 0;
//     iter_b = *b;
//     while (iter_b)
//     {
//         next = next_number(*a, (iter_b)->value, size_a);
//         right = smallest_action_nb(a,b, next, (iter_b)->value);
//         if (right <= check)
//         {
//             check = right;
//             k = indic_b;
//         }
//         iter_b = iter_b->next;
//         indic_b++;
//     }
//     return (get_node_with_index(*b, k)->value);
// }


static void push_to_a_with_sort(t_stack **a, t_stack **b)
{
    
}

void sort_stack_a(t_stack **a, t_stack **b)
{
    int stack_len = stack_size(*a);
    int lis_size;
    int *lis = get_lis(a, stack_len, &lis_size);
    int i;

    i = 0;
    while (i < stack_len)
    {
        if (is_in_lis(lis, lis_size, (*a)->value))
            ra(a);
        else
            pb(a, b);
        i++;
    }
    push_to_a_with_sort(a, b);
    // Rotate to the smallest element
    // while ((*a)->value != get_smallest_node(*a)->value)
    // {
    //     if (get_index_node(*a, (*a)->value) >= stack_len / 2)
    //         ra(a);
    //     else
    //         rra(a);
    // }

    // Print the sorted stack
    // t_stack *temp = *a;
    // while (temp)
    // {
    //     printf("{%d} ", temp->value);
    //     temp = temp->next;
    // }
}
