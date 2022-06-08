/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_bonustest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: bpeeters <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 13:19:58 by bpeeters      #+#    #+#                 */
/*   Updated: 2019/11/20 20:22:31 by bpeeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static	void    del(void *content);
static	void	f_iter(void *content);
static	void	*f_map(void *content);
static	void	print_image(FILE *fptr);

int	main(void)
{

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_lstnew         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char	*data1 = strdup("Test1");
	t_list	*elem1;

	elem1 = ft_lstnew(data1);
	printf("\e[1;33mft_lstnew:\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(elem1->content, data1) && elem1->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

	printf("\nPress \e[1;35mENTER\e[0m to continue\n");
	getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_lstadd_front     |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char	*data2 = strdup("Test2");
	char	*data3 = strdup("Test3");
	t_list	*elem2;
	t_list	*elem3;
	t_list	*empty;
	t_list	*temp;

	empty = NULL;
	elem2 = ft_lstnew(data2);
	elem3 = ft_lstnew(data3);
	temp = ft_lstnew(data1);
	ft_lstadd_front(&elem3, elem2);
	ft_lstadd_front(&elem2, elem1);

    printf("\e[1;33mft_lstadd_front:\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(elem1->next->content, data2) && !strcmp(elem1->next->next->content, data3) && elem1->next->next->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	ft_lstadd_front(&empty, temp);

    printf("Empty test: ");
    if (temp->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_lstsize        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	int i;

    i = ft_lstsize(elem1);

    printf("\e[1;33mft_lstsize:\e[0m\n\n");

    printf("Basic test: ");
    if (i == 3)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	empty = NULL;
	i = ft_lstsize(empty);

    printf("Empty test: ");
    if (i == 0)
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_lstlast        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

    temp = ft_lstlast(elem1);

    printf("\e[1;33mft_lstlast:\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(temp->content, data3) && temp->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	temp = ft_lstlast(NULL);

	printf("Empty test: ");
	if (temp == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_lstadd_back      |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

    char    *data4 = strdup("Test4");
    t_list  *elem4;

	elem4 = ft_lstnew(data4);
	temp = ft_lstnew(data1);
    ft_lstadd_back(&elem1, elem4);

    printf("\e[1;33mft_lstadd_back:\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(elem1->next->next->next->content, data4) && elem1->next->next->next->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	empty = NULL;
    ft_lstadd_back(&empty, temp);

    printf("Empty test: ");
    if (!strcmp(temp->content, data1) && temp->next == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_lstiter        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	ft_lstiter(elem1, &f_iter);

	printf("\e[1;33mft_lstiter:\e[0m\n\n");

	printf("Basic test: ");
    if (!strcmp(elem1->content, "Zest1") && !strcmp(elem1->next->content, "Zest2") \
		&& !strcmp(elem1->next->next->content, "Zest3") && \
		!strcmp(elem1->next->next->next->content, "Zest4"))
	{
        printf("\e[1;32m[OK]\e[0m	");
	}
    else
        printf("\e[1;31m[KO]\e[0m	");

	empty = NULL;

	ft_lstiter(empty, &f_iter);

	printf("Empty test: ");
    if (empty == NULL)
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_lstmap         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	t_list	*new;
	
	new = ft_lstmap(elem1, &f_map, &del);

	printf("\e[1;33mft_lstmap:\e[0m\n\n");

	printf("Basic test: ");
    if (!strcmp(new->content, "Koude Pasta") && !strcmp(new->next->content, "Koude Pasta") \
        && !strcmp(new->next->next->content, "Koude Pasta") && \
        !strcmp(new->next->next->next->content, "Koude Pasta"))
    {
        printf("\e[1;32m[OK]\e[0m	");
    }
    else
        printf("\e[1;31m[KO]\e[0m	");

	empty = NULL;
	new = ft_lstmap(empty, &f_map, &del);

	printf("Empty test: ");
    if (new == NULL)
    {
     	printf("\e[1;32m[OK]\e[0m	");
    }
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	printf("Wow, you completed the bonuses! To celebrate, let's press \e[1;35mENTER\e[0m to enter the temple :)");
	getchar();

	char	*filename = "bonusimage.txt";
	FILE	*fptr = NULL;

	if ((fptr = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "error opening %s\n", filename);
		return (1);
	}

	print_image(fptr);

	fclose(fptr);

	printf("\n");

	return (0);
}

static	void	print_image(FILE *fptr)
{
	char	read_string[500];

	while (fgets(read_string, sizeof(read_string), fptr) != NULL)
		printf("%s", read_string);
}

static	void	del(void *content)
{
	free(content);
}

static	void	f_iter(void *content)
{
	memset(content, 'Z', 1);
}

static	void	*f_map(void *content)
{
	content = strdup("Koude Pasta");
	return (content);
}
