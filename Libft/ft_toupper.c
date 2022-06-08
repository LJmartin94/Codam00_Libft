/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: limartin <limartin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/02 01:18:10 by limartin      #+#    #+#                 */
/*   Updated: 2022/06/08 10:19:34 by limartin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	int	i;

	i = c;
	if (c >= 'a' && c <= 'z')
		i = c - ('a' - 'A');
	return (i);
}