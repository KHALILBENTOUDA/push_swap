/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:11:18 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/15 12:53:01 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_str(char *str, int *char_counter)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_printf_str("(null)", char_counter));
	while (str[i])
	{
		if (ft_printf_char(str[i], char_counter) == -1)
			return (-1);
		i++;
	}
	return (0);
}
