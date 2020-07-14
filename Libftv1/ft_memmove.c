/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:57:45 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:48:34 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	if ((dst == 0) && (src == 0))
		return (0);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source >= dest)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
		len = 0;
	}
	while (len > 0)
	{
		len--;
		dest[len] = source[len];
	}
	return (dst);
}
