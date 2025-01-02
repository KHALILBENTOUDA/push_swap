/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:54:25 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/15 11:21:36 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int nb, int *char_counter)
{
	if (nb < 10)
	{
		if (ft_printf_char(nb + '0', char_counter) == -1)
			return (-1);
	}
	else
	{
		if (ft_printf_unsigned(nb / 10, char_counter) == -1)
			return (-1);
		if (ft_printf_char(nb % 10 + '0', char_counter) == -1)
			return (-1);
	}
	return (0);
}
