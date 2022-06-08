/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:46:56 by limartin          #+#    #+#             */
/*   Updated: 2019/11/25 15:03:43 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	plen;
	size_t	slen;
	size_t	i;
	size_t	j;
	char	*res;

	if (!((s1) && (s2)))
		return (0);
	plen = ft_strlen(s1);
	slen = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (plen + slen + 1));
	i = 0;
	j = 0;
	while ((i <= (plen + slen)) && res)
	{
		if (i < plen)
			res[i] = s1[i];
		if ((i >= plen) && (i <= (plen + slen)))
			res[i] = s2[j];
		if ((i >= plen) && (i <= (plen + slen)))
			j++;
		i++;
	}
	return (res);
}
