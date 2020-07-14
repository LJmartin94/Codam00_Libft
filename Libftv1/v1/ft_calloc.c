/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:35:26 by limartin          #+#    #+#             */
/*   Updated: 2019/11/21 17:46:16 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)malloc((size) * (count));
	if (res == 0)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
