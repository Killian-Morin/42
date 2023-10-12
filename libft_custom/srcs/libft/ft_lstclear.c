/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:39:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/10/12 15:23:43 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;
	t_list	*t;

	if (lst)
	{
		s = *lst;
		while (s)
		{
			t = s->next;
			if (!s)
				return ;
			if (s->content)
				(*del)(s->content);
			free(s);
			s = t;
		}
		*lst = NULL;
	}
}
