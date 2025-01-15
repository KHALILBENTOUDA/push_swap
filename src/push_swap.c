/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:37:35 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/15 15:20:25 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_sort(t_stack **a, t_stack **b)
{
	int	size_s;

	size_s = 0;
	if (is_stack_sorted(a))
	{
		size_s = stack_size(*a);
		if (size_s == 2)
			sa(a, 0);
		else if (size_s == 3)
			sort_three(a);
		else if (size_s == 5 || size_s == 4)
			sort_four_five(a, b, size_s);
		else
			sort_stack_a(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	av = check_input(av);
	fill_stack(&a, av);
	push_swap_sort(&a, &b);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
