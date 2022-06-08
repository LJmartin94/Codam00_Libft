/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libtest.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bpeeters <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 19:57:20 by bpeeters      #+#    #+#                 */
/*   Updated: 2019/11/20 20:16:17 by bpeeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <strings.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/stat.h>

static  char    f(unsigned int n, char c);
static	void	print_image(FILE *fptr);

int		main(void)
{

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |		ft_memset		  |
	\-*-*-*-*-*-*-*-*-*-*-*-*/

	char b1[50];
	char b2[50];
	size_t size = 10;

	memset(b1, 'x', 20);
	memset(b2, 'x', 20);

	memset(b1, '-', size);
	ft_memset(b2, '-', size);

	printf("\e[1;33mft_memset:\e[0m\n\n");
	printf("Basic test: ");
	if (!memcmp(b1, b2, 20))
		printf("\e[1;32m[OK]\e[0m	");
	else
		printf("\e[1;31m[KO]\e[0m	");

	memset(b1, 'x', 20);
	memset(b2, 'x', 20);

	memset(b1, '\200', size);
	ft_memset(b2, '\200', size);

	printf("Unsigned char test: ");
	if (!memcmp(b1, b2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memset(b1, 'x', sizeof(b1));
    memset(b2, 'x', sizeof(b2));

    memset(b1, '-', (0));
    ft_memset(b2, '-', (0));

    printf("Zero test: ");
    if (!memcmp(b1, b2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

	memset(b1, 'x', sizeof(b1));
    memset(b2, 'x', sizeof(b2));

    memset(b1, '\0', 1);
    ft_memset(b2, '\0', 1);

    printf("Null terminator test: ");
    if (!memcmp(b1, b2, 20))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    printf("\n");

	printf("\nPress \e[1;35mENTER\e[0m to continue\n");
	getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_bzero          |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	size = 5;
	memset(b1, 'x', 20);
	memset(b2, 'x', 20);

	bzero(b1, size);
	ft_bzero(b2, size);

	printf("\e[1;33mft_bzero\e[0m\n\n");

	printf("Basic test: ");
    if (!memcmp(b1, b2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	
	memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    bzero(b1, (0));
    ft_bzero(b2, (0));

    printf("Zero test: ");
    if (!memcmp(b1, b2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_memcpy          |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char	*str1;
	char	*str2;
	size = 5;
    memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    str1 = memcpy(b1, "Hoi", size);
    str2 = ft_memcpy(b2, "Hoi", size);

    printf("\e[1;33mft_memcpy\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    str1 = memcpy(b1, "Hoi", 0);
    str2 = ft_memcpy(b2, "Hoi", 0);

    printf("Zero test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m		");
    else
        printf("\e[1;31m[KO]\e[0m		");

	memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    str1 = memcpy(b1, "Hal\0lo\0daar\0", 15);
    str2 = ft_memcpy(b2, "Hal\0lo\0daar\0", 15);

    printf("Null terminator test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_memccpy         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    str1 = memccpy(b1, "Lorum ipsum", 'm', 8);
    str2 = ft_memccpy(b2, "Lorum ipsum", 'm', 8);

    printf("\e[1;33mft_memccpy\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");


	memset(b1, 'x', 20);
    memset(b2, 'x', 20);

    str1 = memccpy(b1, "There is \200 here", '\200', 20);
    str2 = ft_memccpy(b2, "There is \200 here", '\200', 20);

    printf("Unsigned char test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memset(b2, 'x', 20);

    str2 = ft_memccpy(b2, "Lorum ipsum dolor", 't', 20);

    printf("Not found test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memset(b2, 'x', 20);

	str2 = ft_memccpy(b2, "Hete thee", 't',  0);

	printf("\n");

    printf("Zero test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_memmove         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "abcdefghij", 11);
    memcpy(b2, "abcdefghij", 11);

    str1 = memmove(b1, b1 + 2, 11);
    str2 = ft_memmove(b2, b2 + 2, 11);

    printf("\e[1;33mft_memmove\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "abcdefghij", 11);
    memcpy(b2, "abcdefghij", 11);

    str1 = memmove(b1 + 2, b1, 11);
    str2 = ft_memmove(b2 + 2, b2, 11);

    printf("Overwrite test: ");
    if (!memcmp(str1, str2, 11))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();
	
	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_memchr         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "abcdefghij", 10);
    memcpy(b2, "abcdefghij", 10);

    str1 = memchr(b1, 'e', 10);
    str2 = ft_memchr(b2, 'e', 10);

    printf("\e[1;33mft_memchr\e[0m\n\n");

    printf("Basic test: ");
    if (*str1 == *str2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "\n hi \200", 7);
    memcpy(b2, "\n hi \200", 7);

    str1 = memchr(b1, '\200', 7);
    str2 = ft_memchr(b2, '\200', 7);

    printf("Unsigned char test: ");
    if (*str1 == *str2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b2, "Lorum ipsum dolor", 18);

    str2 = ft_memchr(b2, 't', 18);

    printf("No occur test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");	

	memcpy(b1, "Type \0 to end", 18);
	memcpy(b2, "Type \0 to end", 18);

	str2 = ft_memchr(b2, '\0', 18);
    str2 = ft_memchr(b2, '\0', 18);

	printf("\n");

    printf("The \\0 test: ");
    if (*str1 == *str2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\    
   |        ft_memcmp         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	int i1;
	int i2;

	memcpy(b1, "Lorum ipsum dolor", 18);
    memcpy(b2, "Lorum ipsum color", 18);

    i1 = memcmp(b1, b2, 15);
    i2 = ft_memcmp(b1, b2, 15);

    printf("\e[1;33mft_memcmp\e[0m\n\n");

    printf("Basic test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor", 18);
    memcpy(b2, "Lorum ipsum color", 18);

    i1 = memcmp(b1, b2, 10);
    i2 = ft_memcmp(b1, b2, 10);

    printf("Size test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m		");
    else
        printf("\e[1;31m[KO]\e[0m		");

	memcpy(b1, "Lorum\200ipsum", 18);
    memcpy(b2, "Lorum\200ipsum", 18);

    i1 = memcmp(b1, b2, 10);
    i2 = ft_memcmp(b1, b2, 10);

    printf("Unsigned char test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum\0\0\0", 18);
    memcpy(b2, "Lorum\0ipsum", 18);

    i1 = memcmp(b1, b2, 10);
    i2 = ft_memcmp(b1, b2, 10);

	printf("\n");

    printf("The \\0 test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strlen         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	size_t si1;
	size_t si2;

	memcpy(b1, "Lorum ipsum dolor\0", 18);
    memcpy(b2, "Lorum ipsum dolor\0", 18);

    si1 = strlen(b1);
    si2 = ft_strlen(b2);

    printf("\e[1;33mft_strlen\e[0m\n\n");

    printf("Basic test: ");
    if (si1 == si2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("Empty test: ");
    if (!ft_strlen(""))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_strlcpy         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0           ", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0           ", 40);

    si1 = strlcpy(b1, "Hallo", 6);
    si2 = ft_strlcpy(b2, "Hallo", 6);

    printf("\e[1;33mft_strlcpy\e[0m\n\n");

    printf("Basic test: ");
    if (si1 == si2 && memcmp(b1, b2, 10) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor sit amet\0           ", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0           ", 40);

    si1 = strlcpy(b1, "", 3);
    si2 = ft_strlcpy(b2, "", 3);

    printf("Empty test: ");
    if (si1 == si2 && memcmp(b1, b2, 15) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor sit amet\0           ", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0           ", 40);

    si1 = strlcpy(b1, "Hallo", 0);
    si2 = ft_strlcpy(b2, "Hallo", 0);

    printf("Zero length test: ");
    if (si1 == si2 && memcmp(b1, b2, 15) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_strlcat         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "dst\0                    ", 40);
    memcpy(b2, "dst\0                    ", 40);

    si1 = strlcat(b1, "src\0", 7);
    si2 = ft_strlcat(b2, "src\0", 7);

    printf("\e[1;33mft_strlcat\e[0m\n\n");

    printf("Basic test: ");
    if (si1 == si2 && memcmp(b1, b2, 10) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "dst\0                    ", 40);
    memcpy(b2, "dst\0                    ", 40);

    si1 = strlcat(b1, "src\0", 0);
    si2 = ft_strlcat(b2, "src\0", 0);

    printf("Zero length test: ");
    if (si1 == si2 && memcmp(b1, b2, 10) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m		");
    else
        printf("\e[1;31m[KO]\e[0m		");

	memcpy(b1, "\0                    ", 40);
    memcpy(b2, "\0                    ", 40);

    si1 = strlcat(b1, "\0", 0);
    si2 = ft_strlcat(b2, "\0", 0);

    printf("Empty test: ");
    if (si1 == si2 && memcmp(b1, b2, 10) == 0 && strlen(b1) == strlen(b2))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strchr         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    str1 = strchr(b1, 'i');
    str2 = ft_strchr(b2, 'i');

    printf("\e[1;33mft_strchr\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum\0ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum\0ipsum dolor sit amet\0", 40);

	str1 = strchr(b1, '\0');
    str2 = ft_strchr(b2, '\0');

    printf("The \\0 test: ");
    if (!memcmp(str1, str2, 20))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	str1 = strchr(b1, 'z');
    str2 = ft_strchr(b2, 'z');

    printf("Not found test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_strrchr         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    str1 = strrchr(b1, 'm');
    str2 = ft_strrchr(b2, 'm');

    printf("\e[1;33mft_strrchr\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 30))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	str1 = strrchr(b1, 'f');
    str2 = ft_strrchr(b2, 'f');

    printf("Not found test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum\0ipsum\0dolor\0sit\0amet\0", 40);
    memcpy(b2, "Lorum\0ipsum\0dolor\0sit\0amet\0", 40);

    str1 = strrchr(b1, '\0');
    str2 = ft_strrchr(b2, '\0');

    printf("The \\0 test: ");
    if (!memcmp(str1, str2, 30))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "\0", 40);
    memcpy(b2, "\0", 40);

    str1 = strrchr(b1, 'g');
    str2 = ft_strrchr(b2, 'g');

    printf("Empty test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_strnstr         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    str2 = ft_strnstr(b2, "", 20);

    printf("\e[1;33mft_strnstr\e[0m\n\n");

    printf("Empty needle test: ");
    if (!memcmp(str2, b2, 30))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    str1 = strnstr(b1, "ipsum", 20);
    str2 = ft_strnstr(b2, "ipsum", 20);

    printf("Needle found test: ");
    if (!memcmp(str1, str2, 30))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    str1 = strnstr(b1, "ipsa", 20);
    str2 = ft_strnstr(b2, "ipsa", 20);

    printf("Needle not found test: ");
    if (str2 == NULL)
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_strncmp         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
	memcpy(b2, "Lorum ipsum color sit amet\0", 40);

	i1 = strncmp(b1, b2, 20);
	i2 = ft_strncmp(b1, b2, 20);

    printf("\e[1;33mft_strncmp\e[0m\n\n");

    printf("Basic test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = strncmp(b1, b2, 5);
    i2 = ft_strncmp(b1, b2, 5);

    printf("Size test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m		");
    else
        printf("\e[1;31m[KO]\e[0m		");

	memcpy(b1, "", 0);
    memcpy(b2, "", 0);

    i1 = strncmp(b1, b2, 1);
    i2 = ft_strncmp(b1, b2, 1);

    printf("Empty test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    i1 = strncmp(b1, b2, 0);
    i2 = ft_strncmp(b1, b2, 0);

    printf("Size 0 test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

	memcpy(b1, "Lorum ipsum dolor sit amet\200", 40);
    memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

    i1 = strncmp(b1, b2, 30);
    i2 = ft_strncmp(b1, b2, 30);

    printf("Unsigned char test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "Lorum\0ipsum dolor sit amet\0", 40);
    memcpy(b2, "Lorum\0ipsud folor sit amet\0", 40);

    i1 = strncmp(b1, b2, 30);
    i2 = ft_strncmp(b1, b2, 30);

    printf("The \\0 test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_atoi           |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

    i1 = atoi(" -+123");
    i2 = ft_atoi(" -+123");

    printf("\e[1;33mft_atoi\e[0m\n\n");

    printf("Basic test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	i1 = atoi("	-500");
    i2 = ft_atoi("	-500");

    printf("Minus test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	i1 = atoi("-2147483648");
    i2 = ft_atoi("-2147483648");

    printf("Int min test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	i1 = atoi("-9999999999999999999999999");
    i2 = ft_atoi("-9999999999999999999999999");

    printf("Long min test: ");
    if (i1 == i2)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

	printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_isalpha         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 'F';

    printf("\e[1;33mft_isalpha\e[0m\n\n");

    printf("Upper test: ");
    if (isalpha(i1) == ft_isalpha(i1))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	i1 = 'a';

    printf("Lower test: ");
    if (isalpha(i1) == ft_isalpha(i1))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

	i1 = '4';

    printf("False test: ");
    if (isalpha(i1) == ft_isalpha(i1))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

	printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_isdigit         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = '8';

    printf("\e[1;33mft_isdigit\e[0m\n\n");

    printf("True test: ");
    if (isdigit(i1) == ft_isdigit(i1))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    i1 = 'd';

    printf("False test: ");
    if (isdigit(i1) == ft_isdigit(i1))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_isalnum         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 'X';

    printf("\e[1;33mft_isalnum\e[0m\n\n");

    printf("True test: ");
    if (ft_isalnum(i1) == isalpha(i1) || ft_isalnum(i1) == isdigit(i1))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = ' ';

    printf("False test: ");
    if (ft_isalnum(i1) == isalpha(i1) || ft_isalnum(i1) == isdigit(i1))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();


	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_isascii         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 126;

    printf("\e[1;33mft_isascii\e[0m\n\n");

    printf("True test: ");
    if (ft_isascii(i1) != 0)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = 300;

    printf("False test: ");
    if (ft_isascii(i1) == 0)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_isprint         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 32;

    printf("\e[1;33mft_isprint\e[0m\n\n");

    printf("True test: ");
    if (ft_isprint(i1) != 0)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = 12;

    printf("False test: ");
    if (ft_isprint(i1) == 0)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_toupper         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 113;

    printf("\e[1;33mft_toupper\e[0m\n\n");

    printf("True test: ");
    if (ft_toupper(i1) == 'Q')
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = 80;

    printf("False test: ");
    if (ft_toupper(i1) == i1)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();


	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |       ft_tolower         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	i1 = 83;

    printf("\e[1;33mft_tolower\e[0m\n\n");

    printf("True test: ");
    if (ft_tolower(i1) == 's')
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    i1 = 43;

    printf("False test: ");
    if (ft_tolower(i1) == i1)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_calloc         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	str1 = calloc(sizeof(char), 3);
	str2 = ft_calloc(sizeof(char), 3);

    printf("\e[1;33mft_calloc\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 3))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("%s %s", str1, str2);

	str1 = calloc(sizeof(char), 0);
	str2 = ft_calloc(sizeof(char), 0);

    printf("Zero test: ");
    if (!memcmp(str1, str2, 5))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("%s %s", str1, str2);

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();


	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strdup         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);
	memcpy(b2, "Lorum ipsum dolor sit amet\0", 40);

	str1 = strdup(b1);
    str2 = ft_strdup(b2);

    printf("\e[1;33mft_strdup\e[0m\n\n");

    printf("Basic test: ");
    if (!memcmp(str1, str2, 3) && str1 != &b1[0])
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "\0", 1);
    memcpy(b2, "\0", 1);

    str1 = strdup(b1);
    str2 = ft_strdup(b2);

    printf("Zero test: ");
    if (!memcmp(str1, str2, 2) && str2 != &b2[0])
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("%s %s", str1, str2);

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_substr         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum dolor sit amet\0", 40);

    str1 = ft_substr(b1, 6, 11);

    printf("\e[1;33mft_substr\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(str1, "ipsum dolor"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    str1 = ft_substr(b1, 30, 2);

    printf("Start test: ");
    if (!strcmp(str1, ""))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    str1 = ft_substr(b1, 22, 20);

    printf("Length test: ");
    if (!strcmp(str1, "amet"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memset(b1, '\0', 20);

    str1 = ft_substr(NULL, 2, 2);

    printf("Empty test: ");
    if (!str1)
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strjoin        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "Lorum ipsum \0", 20);
	memcpy(b2, "dolor sit amet\0", 20);

    str1 = ft_strjoin(b1, b2);

    printf("\e[1;33mft_strjoin\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(str1, "Lorum ipsum dolor sit amet") && str1 != &b1[0])
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    str1 = ft_strjoin(0, b2);

    printf("No s1 test: ");
    if (!str1)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    str1 = ft_strjoin(b1, 0);

    printf("No s2 test: ");
    if (!str1)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strtrim        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	memcpy(b1, "  Lorum ipsum dolor sit amet  ", 40);
    memcpy(b2, "Lo et", 20);

    str1 = ft_strtrim(b1, b2);

    printf("\e[1;33mft_strtrim\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(str1, "rum ipsum dolor sit am"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "     ", 6);
    memcpy(b2, " ", 2);

    str1 = ft_strtrim(b1, b2);

    printf("Only set test: ");
    if (!strcmp(str1, ""))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	memcpy(b1, "  Lorum ipsum dolor sit amet  ", 40);

    str1 = ft_strtrim(b1, "");

    printf("Empty set test: ");
    if (!strcmp(str1, b1))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_split         |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char c = ' ';
	char **arr;

	memcpy(b1, "Lorum ipsum dolor sit amet", 30);
    
    arr = ft_split(b1, c);

    printf("\e[1;33mft_split\e[0m\n\n");

    printf("Basic test: ");
    if (!(strcmp(arr[0], "Lorum") && strcmp(arr[1], "ipsum")
		&& strcmp(arr[2], "dolor") &&
		strcmp(arr[3], "sit") && strcmp(arr[4], "amet") && strcmp(arr[5], NULL)))
	{
        printf("\e[1;32m[OK]\e[0m	");
	}
    else
        printf("\e[1;31m[KO]\e[0m	");

	c = '.';

    arr = ft_split(b1, c);

    printf("No delim test: ");
    if (!strcmp(arr[0], "Lorum ipsum dolor sit amet"))
        printf("\e[1;32m[OK]\e[0m   ");
    else
        printf("\e[1;31m[KO]\e[0m   ");

    memcpy(b1, "     ", 6);

	c = ' ';

    arr = ft_split(b1, c);

    printf("Only delim test: ");
    if (arr[0] == NULL)
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    memcpy(b1, "  Lorum    ipsum    dolor    sit    amet  ", 40);

    arr = ft_split(b1, c);

	printf("\n");

    printf("Multiple delim test: ");
    if (!(strcmp(arr[0], "Lorum") && strcmp(arr[1], "ipsum")
		  && strcmp(arr[2], "dolor") &&
		  strcmp(arr[3], "sit") && strcmp(arr[4], "amet") && strcmp(arr[5], NULL)))
	{
        printf("\e[1;32m[OK]\e[0m	");
	}
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |         ft_itoa          |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	str1 = ft_itoa(123);

    printf("\e[1;33mft_itoa\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(str1, "123"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	str1 = ft_itoa(-534);

    printf("Minus test: ");
    if (!strcmp(str1, "-534"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	str1 = ft_itoa(2147483647);

    printf("Max int test: ");
    if (!strcmp(str1, "2147483647"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	str1 = ft_itoa(-2147483648);

    printf("Min int test: ");
    if (!strcmp(str1, "-2147483648"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |        ft_strmapi        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	str1 = memcpy(b1, "Lorum ipsum dolor sit amet\0", 30);

	str2 = ft_strmapi(str1, &f);

    printf("\e[1;33mft_strmapi\e[0m\n\n");

    printf("Basic test: ");
    if (!strcmp(str2, "Mpsvn!jqtvn!epmps!tju!bnfu"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	printf("\n");

	printf("\nPress \e[1;35mENTER\e[0m to continue\n");
	getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_putchar_fd       |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char BUF[10];
	char *pbuf;
	umask(0);
	int fd = open("libtest_putchar.txt", O_CREAT | O_RDWR, 0777);
	c = 'f';
	pbuf = BUF;
		
	printf("\e[1;33mft_putchar_fd\e[0m\n\n");

	ft_putchar_fd(c, fd);

	lseek(fd, 0, SEEK_SET);

	while (read(fd, pbuf, 1) == 1)
    {
		pbuf++;
        *pbuf = '\0';
	}
	close(fd);
	
    printf("FD test: ");
    if (!strcmp(BUF, "f"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_putstr_fd        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char BUF2[50];
    char *pbuf2;
    umask(0);
    fd = open("libtest_putstr.txt", O_CREAT | O_RDWR, 0777);
    char str3[] = "Lorum ipsum dolor sit amet";
    pbuf2 = BUF2;

    printf("\e[1;33mft_putstr_fd\e[0m\n\n");

    ft_putstr_fd(str3, fd);

    lseek(fd, 0, SEEK_SET);

    while (read(fd, pbuf2, 1) == 1)
    {
        pbuf2++;
        *pbuf2 = '\0';
    }
    close(fd);

    printf("FD test: ");
    if (!strcmp(BUF2, str3))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_putendl_fd       |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char BUF3[50];
    char *pbuf3;
    umask(0);
    fd = open("libtest_putendl.txt", O_CREAT | O_RDWR, 0777);
    pbuf3 = BUF3;

    printf("\e[1;33mft_putendl_fd\e[0m\n\n");

    ft_putendl_fd(str3, fd);

    lseek(fd, 0, SEEK_SET);

    while (read(fd, pbuf3, 1) == 1)
    {
        pbuf3++;
        *pbuf3 = '\0';
    }
    close(fd);

    printf("FD test: ");
    if (!strcmp(BUF3, "Lorum ipsum dolor sit amet\n"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	/*-*-*-*-*-*-*-*-*-*-*-*-\
   |      ft_putnbr_fd        |
    \-*-*-*-*-*-*-*-*-*-*-*-*/

	char BUF4[20];
    char *pbuf4;
    umask(0);
    fd = open("libtest_putnbr.txt", O_CREAT | O_RDWR, 0777);
    pbuf4 = BUF4;

    printf("\e[1;33mft_putnbr_fd\e[0m\n\n");

    ft_putnbr_fd(322, fd);

    lseek(fd, 0, SEEK_SET);

    while (read(fd, pbuf4, 1) == 1)
    {
        pbuf4++;
        *pbuf4 = '\0';
    }
    close(fd);

    printf("Basic test: ");
    if (!strcmp(BUF4, "322"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

	char BUF5[20];
    char *pbuf5;
    umask(0);
    fd = open("libtest_putnbrmin.txt", O_CREAT | O_RDWR, 0777);
    pbuf5 = BUF5;

    ft_putnbr_fd(-2147483648, fd);

    lseek(fd, 0, SEEK_SET);

    while (read(fd, pbuf5, 1) == 1)
    {
     	pbuf5++;
        *pbuf5 = '\0';
    }
    close(fd);

    printf("Min int test: ");
    if (!strcmp(BUF5, "-2147483648"))
        printf("\e[1;32m[OK]\e[0m	");
    else
        printf("\e[1;31m[KO]\e[0m	");

    printf("\n");

    printf("\nPress \e[1;35mENTER\e[0m to continue\n");
    getchar();

	printf("Thanks for playing! Press \e[1;35mENTER\e[0m to see a surprise ;)");
	getchar();

	char	*filename = "image.txt";
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

static	char	f(unsigned int n, char c)
{
	n += 1;
	return (c + 1);
}
