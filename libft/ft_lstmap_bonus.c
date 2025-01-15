/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:57:37 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/08 00:19:21 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*list;
	t_list	*new;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	ptr = lst;
	list = NULL;
	while (ptr)
	{
		new_content = f(ptr->content);
		new = ft_lstnew(new_content);
		if (!new)
		{
			ft_lstclear(&list, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		ptr = ptr->next;
	}
	return (list);
}
