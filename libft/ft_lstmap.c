/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:48:36 by kmorin            #+#    #+#             */
/*   Updated: 2022/11/19 13:59:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*newlist;
	t_list	*check;

	if (!f || !del)
		return (NULL);
	check = NULL;
	while (lst)
	{
		newlist = ft_lstnew((*f)(lst->content));
		if (!newlist)
		{
			while (check)
			{
				newlist = check->next;
				(*del)(check->content);
				free(check);
				check = newlist;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&check, newlist);
		lst = lst->next;
	}
	return (check);
}
