/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:21:05 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/19 09:53:19 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_b(t_stack **b, int nb_index, int nb_b)
{
	while (nb_b != (*b)->value)
	{
		if (nb_index > stack_size(*b) / 2)
			rrb(b, 0);
		else
			rb(b, 0);
	}
}

void	ft_rotate_a(t_stack **a, int next_index, int next_nb)
{
	while (next_nb != (*a)->value)
	{
		if (next_index > stack_size(*a) / 2)
			rra(a, 0);
		else
			ra(a, 0);
	}
}

t_stack	*get_last_node(t_stack *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	check_s(char *str)
{
	int		i;
	int		valid;
	char	*base;

	i = 0;
	valid = 0;
	base = "0123456789";
	while (str[i])
	{
		if (ft_strchr(base, str[i]))
			valid = 1;
		i++;
	}
	if (valid == 0)
		ft_exit();
}
