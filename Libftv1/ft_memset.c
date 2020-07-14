/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:55:03 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:49:29 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*array;
	unsigned char	fill;
	size_t			i;

	array = (unsigned char *)b;
	fill = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		array[i] = fill;
		i++;
	}
	return (b);
}
