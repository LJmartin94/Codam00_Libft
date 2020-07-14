/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:47:04 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:48:06 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	unsigned char	chr;
	size_t			i;
	void			*ptr;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	chr = (unsigned char)c;
	i = 0;
	ptr = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
		if (source[i - 1] == chr)
		{
			ptr = &dest[i];
			return (ptr);
		}
	}
	return (ptr);
}
