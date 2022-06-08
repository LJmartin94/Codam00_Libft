/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 13:41:30 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:21:46 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	len;

	len = 0;
	while ((s[len] != '\0') && (len < n))
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strnlen(dst, dstsize);
	j = ft_strlen(src);
	if (dstsize <= i)
		return (dstsize + j);
	else if (dstsize > (i + j))
		ft_memmove(dst + i, src, j + 1);
	else if (dstsize <= (i + j))
		ft_memmove(dst + i, src, dstsize - i - 1);
	if (dstsize > 0)
		dst[dstsize - 1] = '\0';
	return (i + j);
}
