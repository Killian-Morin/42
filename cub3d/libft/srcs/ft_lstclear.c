/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:39:14 by kmorin            #+#    #+#             */
/*   Updated: 2023/09/07 11:21:34 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
