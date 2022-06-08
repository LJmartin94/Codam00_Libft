/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 02:23:31 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:52:29 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char chr;
	char *res;

	chr = (char)c;
	res = 0;
	while (*s != '\0')
	{
		if (*s == chr)
			res = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (res);
}
