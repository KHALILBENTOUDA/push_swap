/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:13:01 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/14 11:47:32 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long num, int *char_counter, int isupper)
{
	const char	*hex_base;

	hex_base = "0123456789abcdef";
	if (num < 16)
	{
		if (isupper && (hex_base[num] >= 'a' && hex_base[num] <= 'f'))
		{
			if (ft_printf_char((hex_base[num] - 32), char_counter) == -1)
				return (-1);
		}
		else
		{
			if (ft_printf_char(hex_base[num], char_counter) == -1)
				return (-1);
		}
	}
	else
	{
		if (ft_print_hex(num / 16, char_counter, isupper) == -1)
			return (-1);
		if (ft_print_hex(num % 16, char_counter, isupper) == -1)
			return (-1);
	}
	return (0);
}
