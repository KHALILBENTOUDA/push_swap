/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:57:42 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/10 11:16:03 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_len(long dig)
{
	size_t	i;

	i = 0;
	if (dig <= 0)
	{
		dig = -dig;
		i = 1;
	}
	while (dig > 0)
	{
		dig /= 10;
		i++;
	}
	return (i);
}

static char	*store(char *p, long num, size_t digitCount)
{
	while (num > 0)
	{
		p[--digitCount] = (num % 10) + '0';
		num /= 10;
	}
	return (p);
}

char	*ft_itoa(int n)
{
	size_t	len_digit;
	char	*p;
	long	num;

	num = n;
	len_digit = digit_len(num);
	p = (char *)malloc(len_digit + 1);
	if (!p)
		return (NULL);
	p[len_digit] = '\0';
	if (num <= 0)
	{
		if (num == 0)
		{
			p[0] = '0';
			return (p);
		}
		num = -num;
		p[0] = '-';
	}
	store(p, num, len_digit);
	return (p);
}
