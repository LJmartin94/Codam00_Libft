/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 20:54:13 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:30:15 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	int	i;

	i = 0;
	if (c >= 0 && c <= 127)
		i = 1;
	return (i);
}