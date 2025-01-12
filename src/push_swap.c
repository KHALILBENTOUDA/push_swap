/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:37:35 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/12 22:36:35 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        else if (size_s == 5)
            sort_five(a, b, size_s);
        else
            sort_stack_a(a, b);
    }
}
void af()
{
    system("leaks push_swap");
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    atexit(af);
    a = NULL;
    b = NULL;
    if (ac < 2)
        return (0);
    av = check_input(av, ac);
    fill_stack(&a, av, ac);
    push_swap_sort(&a, &b);
    if (b)
        exit(1);
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
}
