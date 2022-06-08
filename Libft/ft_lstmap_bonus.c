/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:36:12 by limartin          #+#    #+#             */
/*   Updated: 2019/11/27 18:09:07 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_mapper(t_list *head, t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	void	*data;
	t_list	*link;

	data = f(lst->content);
	link = ft_lstnew(data);
	if (link == 0)
	{
		del(data);
		ft_lstclear(&head, del);
		return (1);
	}
	ft_lstadd_back(&head, link);
	return (0);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = 0;
	if (!(f))
		return (0);
	if (lst)
	{
		head = ft_lstnew(f(lst->content));
		if (head == 0)
			return (0);
		while (lst->next)
		{
			lst = lst->next;
			if (ft_mapper(head, lst, f, del))
				return (0);
		}
	}
	return (head);
}
