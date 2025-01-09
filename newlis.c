/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newlis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:17 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/09 19:51:38 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *find_the_lis(int *lis, int *temp_array, int stack_len)
{
    int i;
    int j;

    i = 0;
    while (i < stack_len)
    {
        j = 0;
        while (j < i)
        {
            if (temp_array[i] > temp_array[j] && lis[j] + 1 > lis[i])
                lis[i] = lis[j] + 1;
            j++;
        }
        i++;
    }
    return (lis);
}

static void find_max_lis(int *lis, int *max, int stack_len, int *index)
{
    int i;

    i = 0;
    while(i < stack_len)
    {
        if (lis[i] > *max)
        {
            *max = lis[i];
            *index = i;
        }
        i++;
    }
}

static int *fill_and_compare_lis(int *final_lis, int *lis, int *temp_array, int max_index, int max_lis)
{
    while (max_index >= 0)
    {
        if (max_lis == lis[max_index])
        {
            final_lis[max_lis - 1] = temp_array[max_index];
            max_lis--;
        }
        max_index--;
    }
    return (final_lis);
}

void init_array(int stack_len, t_stack *iter, int *temp_array)
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
int *get_lis(t_stack **stack, int stack_len, int *lis_size)
{
    t_stack *iter;
    int **lis;
    int *temp_array;
    int *final_lis;
    int max_lis;
    int max_index;

    max_lis = 0;
    max_index = 0;
    iter = *stack;
    lis = malloc(sizeof(int*) * stack_len);
    temp_array = malloc(sizeof(int) * stack_len);
    if (!lis || !temp_array)
        return (NULL);
    init_array(stack_len, iter, temp_array);
    
    exit(0);
    lis = find_the_lis(lis, temp_array, stack_len);
    find_max_lis(lis, &max_lis, stack_len, &max_index);
    final_lis = malloc(sizeof(int) * max_lis);
    if (!final_lis)
        return (NULL);
    final_lis = fill_and_compare_lis(final_lis, lis, temp_array, max_index, max_lis);
    *lis_size = max_lis;
    return (free(temp_array), free(lis), final_lis);
}