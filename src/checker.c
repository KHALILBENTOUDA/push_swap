/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:43:14 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/14 14:13:44 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute(t_stack **a, t_stack **b, char *command)
{
	if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
		ra(a, 1);
	else if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
		rra(a, 1);
	else if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
		rb(b, 1);
	else if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
		sa(a, 1);
	else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
		sb(b, 1);
	else if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
		rrb(b, 1);
	else if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
		rr(b, a, 1);
	else if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
		rrr(b, a, 1);
	else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
		pb(a, b, 1);
	else
		ft_exit();
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		i;

	i = 0;
	if (ac < 2)
		return (0);
	av = check_input(av);
	fill_stack(&a, av);
	while (i == 0)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute(&a, &b, line);
		free(line);
	}
	if (is_stack_sorted(&a) == 1 || b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}
