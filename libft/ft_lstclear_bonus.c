/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:28:59 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/08 15:34:00 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!del || !lst || !*lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		del(ptr->content);
		ptr = ptr->next;
		free(*lst);
		*lst = ptr;
	}
}
