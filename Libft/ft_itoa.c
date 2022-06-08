/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:54:29 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:30:54 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_intlen(long int num)
{
	size_t		len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		len;
	size_t		i;
	char		*res;

	num = n;
	len = ft_intlen(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	i = 0;
	if (n < 0)
	{
		res[i] = '-';
		num *= -1;
		i++;
	}
	res[len] = '\0';
	while (len != i)
	{
		len--;
		res[len] = (num % 10) + '0';
		num /= 10;
	}
	return (res);
}
