/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 06:14:31 by limartin          #+#    #+#             */
/*   Updated: 2019/11/28 03:28:39 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while ((i < len) && (haystack[i] != '\0'))
	{
		j = 0;
		while (haystack[i] == needle[j] && (i < len))
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i - j);
		}
		if ((j > 0) && !(haystack[i] == needle[j] && ((i) < len)))
			i = i - j + 1;
		if (j == 0)
			i++;
	}
	return (0);
}
