/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makhtar <makhtar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 19:07:35 by makhtar           #+#    #+#             */
/*   Updated: 2021/10/04 14:06:14 by makhtar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*work;

	if (lst != 0 && f != 0)
	{
		begin = ft_lstnew(f(lst->content));
		work = begin;
		while (lst->next)
		{
			lst = lst->next;
			work->next = ft_lstnew(f(lst->content));
			if (work->next == 0)
			{
				ft_lstclear(&begin, del);
				return (0);
			}
			work = work->next;
		}
		return (begin);
	}
	return (0);
}
