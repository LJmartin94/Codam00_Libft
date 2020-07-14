/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:42:52 by limartin          #+#    #+#             */
/*   Updated: 2019/11/27 18:17:37 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*res;

	if (!(alst) || !(new))
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		res = *alst;
		while (res->next)
		{
			res = res->next;
		}
		res->next = new;
	}
}
