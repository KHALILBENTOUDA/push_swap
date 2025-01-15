/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:18:51 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/08 00:10:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;

	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (t_dst < t_src)
		ft_memcpy(t_dst, t_src, len);
	else
	{
		while (len-- > 0)
			t_dst[len] = t_src[len];
	}
	return (dst);
}
