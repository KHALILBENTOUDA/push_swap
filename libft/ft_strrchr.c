/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:53:27 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/08 16:24:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	conv_char;
	char	*store;

	conv_char = (char)c;
	store = NULL;
	while (*s)
	{
		if (*s == conv_char)
			store = (char *)s;
		s++;
	}
	if (conv_char == '\0')
		return ((char *)s);
	return (store);
}
