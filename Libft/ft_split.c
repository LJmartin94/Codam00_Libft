/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 22:12:30 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:22:59 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_filler(char **res, char const *s, char c, size_t scount)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < scount)
	{
		while (s[j] == c)
			j++;
		k = 0;
		while ((s[j] != c) && (s[j] != '\0'))
		{
			res[i][k] = s[j];
			j++;
			k++;
		}
		res[i][k] = '\0';
		i++;
	}
	res[i] = NULL;
}

static	void	ft_freeall(size_t i, char **res)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
}

static	char	**ft_allocator(char **res, char const *s, char c, size_t scount)
{
	size_t	i;
	size_t	j;
	size_t	sublen;

	i = 0;
	j = 0;
	while (i < scount)
	{
		while ((s[j] == c) && (s[j] != '\0'))
			j++;
		sublen = 0;
		while ((s[j] != c) && (s[j] != '\0'))
		{
			j++;
			sublen++;
		}
		res[i] = (char *)malloc(sizeof(char) * (sublen + 1));
		if (res[i] == 0)
		{
			ft_freeall(i, res);
			return (0);
		}
		i++;
	}
	return (res);
}

static	size_t	ft_strcounter(char const *s, char c, size_t slen)
{
	size_t	i;
	size_t	scount;

	i = 0;
	scount = 0;
	while ((s[i] == c) && (s[i] != '\0'))
		i++;
	while (i < slen)
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			scount++;
		i++;
	}
	return (scount);
}

char	**ft_split(char const *s, char c)
{
	size_t	slen;
	size_t	scount;
	char	**res;

	if (!(s))
		return (0);
	slen = ft_strlen(s);
	scount = ft_strcounter(s, c, slen);
	res = (char **)malloc(sizeof(char *) * (scount + 1));
	if (res == 0)
		return (0);
	res = ft_allocator(res, s, c, scount + 1);
	if (res == 0)
		return (0);
	ft_filler(res, s, c, scount);
	return (res);
}
