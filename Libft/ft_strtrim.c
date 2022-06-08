/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 02:48:02 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:20:28 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_startget(char const *s1, char const *set, size_t setlen)
{
	size_t	start;
	size_t	j;

	start = 0;
	j = 0;
	while (j < setlen)
	{
		if (s1[start] == set[j])
		{
			start++;
			j = 0;
		}
		else
			j++;
	}
	return (start);
}

static	size_t	ft_endget(char const *s1, char const *set, size_t setlen)
{
	size_t	end;
	size_t	j;

	end = ft_strlen(s1);
	j = 0;
	while (j <= setlen)
	{
		if ((s1[end] == set[j]) && (end > 0))
		{
			end--;
			j = 0;
		}
		else
			j++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	setlen;

	if (!(s1))
		return (0);
	if (!(set))
		return (ft_strdup(s1));
	setlen = ft_strlen(set);
	start = ft_startget(s1, set, setlen);
	end = ft_endget(s1, set, setlen);
	if (end < start)
		return (ft_strdup(""));
	res = ft_substr(s1, start, (end - start + 1));
	return (res);
}
