/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:04:46 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:48:12 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	chr;
	size_t			i;
	void			*ptr;

	src = (unsigned char *)s;
	chr = (unsigned char)c;
	i = 0;
	ptr = 0;
	while (i < n)
	{
		if (src[i] == chr)
		{
			ptr = &src[i];
			return (ptr);
		}
		i++;
	}
	return (ptr);
}
