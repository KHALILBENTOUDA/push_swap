/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:39 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/15 12:52:08 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(int n, int *char_counter)
{
	long	nb;

	nb = n;
	if (nb == -2147483647)
		return (ft_printf_str("-2147483647", char_counter));
	if (nb < 0)
	{
		if (ft_printf_char('-', char_counter) == -1)
			return (-1);
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
	{
		if (ft_printf_char(nb + '0', char_counter) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_number(nb / 10, char_counter) == -1)
			return (-1);
		if (ft_printf_number(nb % 10, char_counter) == -1)
			return (-1);
	}
	return (0);
}
