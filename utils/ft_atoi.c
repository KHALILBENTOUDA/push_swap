/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:27:37 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/16 10:29:57 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	store;
	int			si;

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
	{
		if (store > (9223372036854775807 - (str[i] - '0')) / 10 && si == 1)
			return (-1);
		if (store > (9223372036854775807 - (str[i] - '0')) / 10 && si == -1)
			return (0);
		store = store * 10 + (str[i++] - '0');
	}
	return (store * si);
}
