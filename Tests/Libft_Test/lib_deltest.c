/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_deltest.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bpeeters <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:37:14 by bpeeters      #+#    #+#                 */
/*   Updated: 2019/11/20 16:31:38 by bpeeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static	void	del(void *content)
{
	free(content);
}

int		main(void)
{
	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_lstdelone       |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	t_list  *tbdel;
	char	*data1 = strdup("Test1");

	tbdel = ft_lstnew(data1);
	ft_lstdelone(tbdel, &del);

	printf("\e[1;33mft_lstdelone:\e[0m\n\n");

	free(data1);
	free(tbdel);

	return (0);
}
