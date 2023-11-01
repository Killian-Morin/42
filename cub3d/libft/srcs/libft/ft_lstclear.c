/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:39:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/18 14:43:52 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;
	t_list	*temp;

	if (!*del)
		return ;
	s = *lst;
	while (s)
	{
		temp = s->next;
		ft_lstdelone(s, del);
		s = temp;
	}
	*lst = NULL;
}
