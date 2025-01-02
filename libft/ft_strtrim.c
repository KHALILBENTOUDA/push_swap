/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:18:48 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/10 13:34:03 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s;
	size_t	e;
	size_t	i;
	char	*res;

	s = 0;
	e = 0;
	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (s1[s] && ft_strchr(set, s1[s]))
		s++;
	e = ft_strlen(s1);
	while (e > s && ft_strchr(set, s1[e - 1]))
		e--;
	res = (char *)malloc((e - s) + 1);
	if (!res)
		return (NULL);
	while (e > s)
		res[i++] = s1[s++];
	res[i] = '\0';
	return (res);
}
