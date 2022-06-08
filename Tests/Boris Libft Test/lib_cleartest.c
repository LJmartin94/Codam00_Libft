/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_cleartest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bpeeters <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 15:50:24 by bpeeters      #+#    #+#                 */
/*   Updated: 2019/11/20 16:18:29 by bpeeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static  void    del(void *content)
{
	free(content);
}

int     main(void)
{
    /*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_lstclear        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	t_list  *elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	char    *data1 = strdup("Test1");
	char    *data2 = strdup("Test2");
	char    *data3 = strdup("Test3");
	char    *data4 = strdup("Test4");

	elem1 = ft_lstnew(data1);
	elem2 = ft_lstnew(data2);
	elem3 = ft_lstnew(data3);
	elem4 = ft_lstnew(data4);

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	printf("\e[1;33mft_lstclear:\e[0m\n\n");

	ft_lstclear(&elem1, &del);

	free(elem4);
	//free(data4);

	return (0);
}
