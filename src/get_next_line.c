/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 18:23:41 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/14 13:37:33 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_new(char *s1, char *s2)
{
	int		strlen;
	char	*str;
	int		i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	strlen = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * strlen + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	strlen = 0;
	while (s2[strlen])
		str[i++] = s2[strlen++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buff;
	int		readed;
	char	*line;

	line = NULL;
	buff = malloc(2);
	if (!buff)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buff, 1);
		if (readed == 0)
			break ;
		buff[readed] = '\0';
		line = ft_strjoin_new(line, buff);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			break ;
	}
	free(buff);
	return (line);
}
