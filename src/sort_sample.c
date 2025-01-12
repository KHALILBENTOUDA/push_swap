/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sample.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:19:55 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/12 18:04:12 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **a)
{
    if ((*a)->value == bigest_item(*a))
        ra(a);
    else if ((*a)->next->value == bigest_item(*a))
        rra(a);
    if ((*a)->value > (*a)->next->value)
        sa(a);
}

void sort_five(t_stack **a, t_stack **b, int size_s)
{
    t_stack *small;
    int index;

    index = 0;
    while (size_s > 3)
    {
        small = get_smallest_node(*a);
        index = get_index_node(*a, small->value);
        while (*a != small)
        {
            if (index >= stack_size(*a) / 2)
                rra(a);
            else
                ra(a);
        }
        pb(a, b);
        size_s--;
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}

void fill_stack(t_stack **a, char **content, int ac)
{
    int i;
    t_stack *last_node;
    t_stack *new_node;

    i = 0;
    if (ft_strncmp(content[0], "./push_swap", ft_strlen(content[0])) == 0 \
    || ft_strncmp(content[0], "./checker", ft_strlen(content[0])) == 0 )
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