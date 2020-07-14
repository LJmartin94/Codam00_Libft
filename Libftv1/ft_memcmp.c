/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:46:31 by limartin          #+#    #+#             */
/*   Updated: 2019/11/28 03:38:42 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				res;

	if ((!(s1) || !(s2)) && n == 0)
		return (0);
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	if (n == 0)
		res = ((unsigned char)str1[i]) - ((unsigned char)str2[i]);
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			res = ((unsigned char)str1[i]) - ((unsigned char)str2[i]);
			return (res);
		}
		i++;
	}
	return (res);
}
