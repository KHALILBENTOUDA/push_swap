/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:05:45 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/13 16:12:21 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free(char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}

long	long_ft_atoi(const char *str)
{
	int		i;
	long	store;
	int		si;

	i = 0;
	si = 1;
	store = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			si *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		store = store * 10 + (str[i++] - '0');
	return (store * si);
}

void	ft_free_stack(t_stack **head)
{
	if (!head)
		return ;
	if (*head != NULL)
	{
		while (*head)
		{
			free(*head);
			*head = (*head)->next;
		}
	}
}

int	turn_around(int stack_len, int index)
{
	if (index >= stack_len - 1)
		return (0);
	else
		return (index + 1);
}
