/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:30:32 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/15 11:18:11 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pointer(void *ptr, int *char_counter)
{
	unsigned long	number_p;

	number_p = (unsigned long)ptr;
	if (ft_printf_str("0x", char_counter) == -1)
		return (-1);
	if (ft_print_hex(number_p, char_counter, 0) == -1)
		return (-1);
	return (0);
}
