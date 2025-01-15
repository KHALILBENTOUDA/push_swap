/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:01:48 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/04 12:24:27 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cmp_s1;
	unsigned char	*cmp_s2;

	i = 0;
	cmp_s1 = (unsigned char *)s1;
	cmp_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (cmp_s1[i] != cmp_s2[i])
			return (cmp_s1[i] - cmp_s2[i]);
		i++;
	}
	return (0);
}
