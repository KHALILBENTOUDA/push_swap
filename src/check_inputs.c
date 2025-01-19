/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:02:27 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/16 13:09:31 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_signed_number(char **inputs)
{
	int		i;
	int		j;
	char	*nb;

	i = 0;
	while (inputs[i])
	{
		j = 0;
		nb = inputs[i];
		while (nb[j])
		{
			if ((nb[j] == '-' || nb[j] == '+') && ft_isdigit(nb[j + 1]))
				j++;
			while (ft_isdigit(nb[j]))
				j++;
			if (!ft_isdigit(nb[j]) && nb[j] != '\0')
				ft_exit();
		}
		i++;
	}
}

static void	is_max_min(char **inputs)
{
	int		i;
	char	*nb;

	i = 0;
	while (inputs[i])
	{
		nb = inputs[i];
		if (long_ft_atoi(inputs[i]) > 2147483647 || \
			long_ft_atoi(inputs[i]) < -2147483648)
			ft_exit();
		i++;
	}
}

static void	is_number_duplicated(char **inputs)
{
	int		i;
	int		j;

	i = 0;
	while (inputs[i])
	{
		j = i + 1;
		while (inputs[j])
		{
			if (ft_atoi(inputs[i]) == ft_atoi(inputs[j]))
				ft_exit();
			j++;
		}
		i++;
	}
}

static char	**is_one_string(char **inputs)
{
	int		i;
	char	*s;

	i = 1;
	s = NULL;
	while (inputs[i])
	{
		check_s(inputs[i]);
		s = ft_strjoin_new(s, inputs[i]);
		if (s)
			s = ft_strjoin_new(s, " ");
		i++;
	}
	inputs = ft_split(s, ' ');
	free(s);
	if (!inputs)
		ft_exit();
	return (inputs);
}

char	**check_input(char **inputs)
{
	inputs = is_one_string(inputs);
	is_signed_number(inputs);
	is_max_min(inputs);
	is_number_duplicated(inputs);
	return (inputs);
}
