/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uglyLibftTester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: limartin <limartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 23:09:03 by limartin          #+#    #+#             */
/*   Updated: 2019/12/02 20:01:19 by limartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -o test uglyLibftTester.c libft.a && ./test |cat -e

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	ft_print_result(int n)
{
	char	c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

void	ft_splitprinter(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
	write(1, "String ", sizeof("String"));
	ft_putnbr_fd(i, 1);
	write(1, ": ", sizeof(":"));
	ft_putstr_fd(res[i], 1);
	write(1, "\n", sizeof("n"));
	i++;
	}
	write(1, "String ", sizeof("String"));
	ft_putnbr_fd(i, 1);
	write(1, ": ", sizeof(":"));
	write(1, &res[i], 1);
	write(1, "\n", 1);
}

int		main(void)
{
	char	dest[15];
	char	dest2[15];


	char	memset11[0];
	char	memset22[0];

	char	memset1[5];
	char	memset2[5];



//split
	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split("", '\0'));
	write(1, "Expected:   String 0: ", sizeof("Expected:   String 0: "));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split1[6];

	bzero(split1, 5);
	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split1, '\0'));
	write(1, "Expected:   String 0: ", sizeof("Expected:   String 0: "));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split4[30] = "     "; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split4, ' '));
	write(1, "Expected:   String 0: ", sizeof("Expected:   String 0: "));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split2[30] = "  This is a string of words  "; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split2, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split3[30] = " This is a string of words "; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split3, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split3a[30] = "This is a string of words "; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split3a, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split3b[30] = " This is a string of words"; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split3b, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split5[30] = "This is a string of words     "; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split5, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split6[30] = "This is a string of words"; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split6, ' '));
	write(1, "\n", 1);

//split
	write(1, "\n", 1);
	char split7[30] = "    This is a string of words"; 

	write(1, "Your split: ", sizeof("Expected:  "));
	ft_splitprinter(ft_split(split7, ' '));
	write(1, "\n", 1);


//memset
	write(1, "\n", 1);
	write(1, "(test 1) memset:    ", sizeof("(test 1) memset:    ")-1);
	ft_putstr_fd(memset("aaaa", 'c', 0), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_memset: ", sizeof("(test 1) ft_memset: ")-1);
	ft_putstr_fd(ft_memset("aaaa", 'c', 0), 1);
	write(1, "\n", 1);

	strcpy(memset1, "aaaa");
	strcpy(memset2, "aaaa");

//memset
	write(1, "\n", 1);
	write(1, "(test 2) memset:    ", sizeof("(test 1) memset:    ")-1);
	ft_putstr_fd(memset(memset1, 'c', 3), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_memset: ", sizeof("(test 1) ft_memset: ")-1);
	ft_putstr_fd(ft_memset(memset2, 'c', 3), 1);
	write(1, "\n", 1);

	strcpy(memset1, "aaaa");
	strcpy(memset2, "aaaa");

//memset
	write(1, "\n", 1);
	write(1, "(test 3) memset:    ", sizeof("(test 1) memset:    ")-1);
	ft_putstr_fd(memset(memset1, NULL, 3), 1);
	write(1, "\n", 1);
	write(1, "(test 3) ft_memset: ", sizeof("(test 1) ft_memset: ")-1);
	ft_putstr_fd(ft_memset(memset2, NULL, 3), 1);
	write(1, "\n", 1);

//memset
	write(1, "\n", 1);
	write(1, "(test 4) memset:    ABORTS", sizeof("(test 1) memset:    ABORTS")-1);
	//ft_putstr_fd(memset(memset11, 'c', 3), 1);
	write(1, "\n", 1);
	write(1, "(test 4) ft_memset: ", sizeof("(test 1) ft_memset: ")-1);
	ft_putstr_fd(ft_memset(memset22, 'c', 3), 1);
	write(1, "\n", 1);
	
//strnstr
	write(1, "\n", 1);
	write(1, "(test 1) strnstr:    ", sizeof("(test 1) strnstr:    ")-1);
	ft_putstr_fd(strnstr("ababc", "abc", 5), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strnstr: ", sizeof("(test 1) ft_strnstr: ")-1);
	ft_putstr_fd(ft_strnstr("ababc", "abc", 5), 1);
	write(1, "\n", 1);

//strnstr
	write(1, "\n", 1);
	write(1, "(test 1) strnstr:    ", sizeof("(test 1) strnstr:    ")-1);
	ft_putstr_fd(strnstr("Turlough's test is DDDDDank!", "DDDDank!", 50), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strnstr: ", sizeof("(test 1) ft_strnstr: ")-1);
	ft_putstr_fd(ft_strnstr("Turlough's test is DDDDDank!", "DDDDank!", 50), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 1) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("0"), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("0"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 2) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("-0"), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("-0"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 3) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi(" 5 5 5"), 1);
	write(1, "\n", 1);
	write(1, "(test 3) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi(" 5 5 5"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 4) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("a7"), 1);
	write(1, "\n", 1);
	write(1, "(test 4) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("a7"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 5) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi(""), 1);
	write(1, "\n", 1);
	write(1, "(test 5) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi(""), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 6) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("9223372036854775800"), 1);
	write(1, "\n", 1);
	write(1, "(test 6) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("9223372036854775800"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 7) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("9223372036854775801"), 1);
	write(1, "\n", 1);
	write(1, "(test 7) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("9223372036854775801"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 8) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("922337203685477580"), 1);
	write(1, "\n", 1);
	write(1, "(test 8) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("922337203685477580"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 9) atoi:    ", sizeof("(test 1) atoi:    ")-1);
	ft_putnbr_fd(atoi("9223372036854775807"), 1);
	write(1, "\n", 1);
	write(1, "(test 9) ft_atoi: ", sizeof("(test 1) ft_atoi: ")-1);
	ft_putnbr_fd(ft_atoi("9223372036854775807"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 10) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("9223372036854775808"), 1);
	write(1, "\n", 1);
	write(1, "(test 10) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("9223372036854775808"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 11) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-9223372036854775800"), 1);
	write(1, "\n", 1);
	write(1, "(test 11) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-9223372036854775800"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 12) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-9223372036854775801"), 1);
	write(1, "\n", 1);
	write(1, "(test 12) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-9223372036854775801"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 13) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-922337203685477580"), 1);
	write(1, "\n", 1);
	write(1, "(test 13) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-922337203685477580"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 14) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-9223372036854775807"), 1);
	write(1, "\n", 1);
	write(1, "(test 14) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-9223372036854775807"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 15) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-9223372036854775808"), 1);
	write(1, "\n", 1);
	write(1, "(test 15) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-9223372036854775808"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 16) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-9223372036854775809"), 1);
	write(1, "\n", 1);
	write(1, "(test 16) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-9223372036854775809"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 17) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("922337203685477580a"), 1);
	write(1, "\n", 1);
	write(1, "(test 17) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("922337203685477580a"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 18) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("2147483647"), 1);
	write(1, "\n", 1);
	write(1, "(test 18) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("2147483647"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 19) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("214748364"), 1);
	write(1, "\n", 1);
	write(1, "(test 19) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("214748364"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 20) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("2147483640"), 1);
	write(1, "\n", 1);
	write(1, "(test 20) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("2147483640"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 21) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("2147483641"), 1);
	write(1, "\n", 1);
	write(1, "(test 21) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("2147483641"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 22) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("--2147483648"), 1);
	write(1, "\n", 1);
	write(1, "(test 22) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("--2147483648"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 23) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-2147483648"), 1);
	write(1, "\n", 1);
	write(1, "(test 23) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-2147483648"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 24) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-214748364-8"), 1);
	write(1, "\n", 1);
	write(1, "(test 24) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-214748364-8"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 25) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("42"), 1);
	write(1, "\n", 1);
	write(1, "(test 25) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("42"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 26) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-42"), 1);
	write(1, "\n", 1);
	write(1, "(test 26) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-42"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 27) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("-+42"), 1);
	write(1, "\n", 1);
	write(1, "(test 27) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("-+42"), 1);
	write(1, "\n", 1);

//atoi
	write(1, "\n", 1);
	write(1, "(test 28) atoi:    ", sizeof("(test 1) atoi:    "));
	ft_putnbr_fd(atoi("+-42"), 1);
	write(1, "\n", 1);
	write(1, "(test 28) ft_atoi: ", sizeof("(test 1) ft_atoi: "));
	ft_putnbr_fd(ft_atoi("+-42"), 1);
	write(1, "\n", 1);

//strncmp
	write(1, "\n", 1);
	write(1, "(test 1) strncmp:    ", sizeof("(test 1) strncmp:    ")-1);
	ft_putnbr_fd((strncmp("AAA", "AAAA", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strncmp: ", sizeof("(test 1) ft_strncmp: ")-1);
	ft_putnbr_fd((ft_strncmp("AAA", "AAAA", 4)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 1) memcmp:    ", sizeof("(test 1) memcmp:    ")-1);
	ft_putnbr_fd((memcmp("AAA", "AAAA", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_memcmp: ", sizeof("(test 1) ft_memcmp: ")-1);
	ft_putnbr_fd((ft_memcmp("AAA", "AAAA", 4)), 1);
	write(1, "\n", 1);

//strncmp
	write(1, "\n", 1);
	write(1, "(test 2) strncmp:    ", sizeof("(test 1) strncmp:    ")-1);
	ft_putnbr_fd((strncmp("AAAA", "AAA", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_strncmp: ", sizeof("(test 1) ft_strncmp: ")-1);
	ft_putnbr_fd((ft_strncmp("AAAA", "AAA", 4)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 2) memcmp:     ", sizeof("(test 1) memcmp:     ")-1);
	ft_putnbr_fd((memcmp("AAAA", "AAA", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp("AAAA", "AAA", 4)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 3) memcmp:     ", sizeof("(test 1) memcmp:     ")-1);
	ft_putnbr_fd((memcmp("M", "", 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 3) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp("M", "", 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 3) moulinette: 77", sizeof("(test 3) moulinette: 77")-1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 4) memcmp:     ", sizeof("(test 1) memcmp:     ")-1);
	ft_putnbr_fd((memcmp("", "M", 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 4) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp("", "M", 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 4) moulinette: -77", sizeof("(test 3) moulinette: -77")-1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 5) memcmp:    ", sizeof("(test 1) memcmp:    ")-1);
	ft_putnbr_fd((memcmp("AAAZ", "AAAA", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 5) ft_memcmp: ", sizeof("(test 1) ft_memcmp: ")-1);
	ft_putnbr_fd((ft_memcmp("AAAZ", "AAAA", 4)), 1);
	write(1, "\n", 1);

//strncmp
	write(1, "\n", 1);
	write(1, "(test 6) strncmp:    ", sizeof("(test 1) strncmp:    ")-1);
	ft_putnbr_fd((strncmp("AAAA", "AAAZ", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 6) ft_strncmp: ", sizeof("(test 1) ft_strncmp: ")-1);
	ft_putnbr_fd((ft_strncmp("AAAA", "AAAZ", 4)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 7) memcmp:     ", sizeof("(test 1) memcmp:     ")-1);
	ft_putnbr_fd((memcmp("AAAA", "AAAZ", 4)), 1);
	write(1, "\n", 1);
	write(1, "(test 7) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp("AAAA", "AAAZ", 4)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 8) memcmp:     SEGFAULT", sizeof("(test 1) memcmp:     SEGFAULT")-1);
	//ft_putnbr_fd((memcmp(NULL, NULL, 100)), 1);
	write(1, "\n", 1);
	write(1, "(test 8) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	//ft_putnbr_fd((ft_memcmp(NULL, NULL, 100)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 9) memcmp:     ", sizeof("(test 1) memcmp:     ")-1);
	ft_putnbr_fd((memcmp("", NULL, 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 9) ft_memcmp:  ", sizeof("(test 1) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp("", NULL, 0)), 1);
	write(1, "\n", 1);

//memcmp
	write(1, "\n", 1);
	write(1, "(test 10) memcmp:     ", sizeof("(test 10) memcmp:     ")-1);
	ft_putnbr_fd((memcmp(NULL, "", 0)), 1);
	write(1, "\n", 1);
	write(1, "(test 10) ft_memcmp:  ", sizeof("(test 10) ft_memcmp:  ")-1);
	ft_putnbr_fd((ft_memcmp(NULL, "", 0)), 1);
	write(1, "\n", 1);

//bzero
	char	bzero1[50];
	char	bzero2[50];

	write(1, "\n", 1);
	write(1, "(test 1) bzero:    ", sizeof("(test 1) memse:    ")-1);
	memset(bzero1, 'c', 25);
	ft_bzero(bzero1 + 5, 10);
	write(1, bzero1, 25);
	write(1, "\n", 1);
	write(1, "(test 1) ft_bzero: ", sizeof("(test 1) ft_memse: ")-1);
	memset(bzero2, 'c', 25);
	ft_bzero(bzero2 + 5, 10);
	write(1, bzero2, 25);
	write(1, "\n", 1);

//calloc
	char	*calloc1;
	char	*calloc2;

	write(1, "\n", 1);
	write(1, "(test 1) calloc:    ", sizeof("(test 1) calloc:    ")-1);
	calloc1 = calloc(20, sizeof(char));
	calloc1[0] =  'c';
	calloc1[19] = 'c';
	write(1, calloc1, 20);
	write(1, "\n", 1);
	write(1, "(test 1) ft_calloc: ", sizeof("(test 1) ft_calloc: ")-1);
	calloc2 = ft_calloc(20, sizeof(char));
	calloc2[0] =  'c';
	calloc2[19] = 'c';
	write(1, calloc2, 20);
	write(1, "\n", 1);

//isalnum
	int i;
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_isalnum:    ", sizeof("(test 1) ft_isalnum:    ")-1);
	while (i < 128)
	{
		if (isalnum(i) != ft_isalnum(i))
			break;
		i++;
	}
	if (i != 128)
	{
		write(1, "FAIL", 4);
	}
	else
	{
		write(1, "Success", 7);
	}
	write(1, "\n", 1);

//isalpha
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_isalpha:    ", sizeof("(test 1) ft_isalpha:    ")-1);
	while (i < 128)
	{
		if (isalpha(i) != ft_isalpha(i))
			break;
		i++;
	}
	if (i != 128)
	{
		write(1, "FAIL", 4);
	}
	else
	{
		write(1, "Success", 7);
	}
	write(1, "\n", 1);

//isascii
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_isascii:    ", sizeof("(test 1) ft_isalpha:    ")-1);
	while (i < 128)
	{
		if (isascii(i) != ft_isascii(i))
			break;
		i++;
	}
	if (i != 128)
	{
		write(1, "FAIL", 4);
	}
	else
	{
		write(1, "Success", 7);
	}
	write(1, "\n", 1);

//isdigit
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_isdigit:    ", sizeof("(test 1) ft_isdigit:    ")-1);
	while (i < 128)
	{
		if (isdigit(i) != ft_isdigit(i))
			break;
		i++;
	}
	if (i != 128)
	{
		write(1, "FAIL", 4);
	}
	else
	{
		write(1, "Success", 7);
	}
	write(1, "\n", 1);

//isprint
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_isprint:    ", sizeof("(test 1) ft_isprint:    ")-1);
	while (i < 128)
	{
		if (isprint(i) != ft_isprint(i))
			break;
		i++;
	}
	if (i != 128)
	{
		write(1, "FAIL", 4);
	}
	else
	{
		write(1, "Success", 7);
	}
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 1) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((0), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(0), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 2) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((-0), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(-0), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 3) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((555), 1);
	write(1, "\n", 1);
	write(1, "(test 3) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(555), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 4) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((7), 1);
	write(1, "\n", 1);
	write(1, "(test 4) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(7), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 5) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((00), 1);
	write(1, "\n", 1);
	write(1, "(test 5) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(00), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 6) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((9223372036854775800), 1);
	write(1, "\n", 1);
	write(1, "(test 6) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(9223372036854775800), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 7) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((9223372036854775801), 1);
	write(1, "\n", 1);
	write(1, "(test 7) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(9223372036854775801), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 8) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((922337203685477580), 1);
	write(1, "\n", 1);
	write(1, "(test 8) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(922337203685477580), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 9) itoa:    ", sizeof("(test 1) itoa:    ")-1);
	ft_putnbr_fd((9223372036854775807), 1);
	write(1, "\n", 1);
	write(1, "(test 9) ft_itoa: ", sizeof("(test 1) ft_itoa: ")-1);
	ft_putstr_fd(ft_itoa(9223372036854775807), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 10) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((9223372036854775808), 1);
	write(1, "\n", 1);
	write(1, "(test 10) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(9223372036854775808), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 11) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-9223372036854775800), 1);
	write(1, "\n", 1);
	write(1, "(test 11) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-9223372036854775800), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 12) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-9223372036854775801), 1);
	write(1, "\n", 1);
	write(1, "(test 12) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-9223372036854775801), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 13) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-922337203685477580), 1);
	write(1, "\n", 1);
	write(1, "(test 13) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-922337203685477580), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 14) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-9223372036854775807), 1);
	write(1, "\n", 1);
	write(1, "(test 14) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-9223372036854775807), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 15) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-9223372036854775808), 1);
	write(1, "\n", 1);
	write(1, "(test 15) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-9223372036854775808), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 16) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-9223372036854775809), 1);
	write(1, "\n", 1);
	write(1, "(test 16) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-9223372036854775809), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 17) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((922337203685477580), 1);
	write(1, "\n", 1);
	write(1, "(test 17) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(922337203685477580), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 18) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((2147483647), 1);
	write(1, "\n", 1);
	write(1, "(test 18) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(2147483647), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 19) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((214748364), 1);
	write(1, "\n", 1);
	write(1, "(test 19) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(214748364), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 20) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((2147483640), 1);
	write(1, "\n", 1);
	write(1, "(test 20) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(2147483640), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 21) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((2147483641), 1);
	write(1, "\n", 1);
	write(1, "(test 21) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(2147483641), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 22) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-2147483648), 1);
	write(1, "\n", 1);
	write(1, "(test 22) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-2147483648), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 23) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-2147483648), 1);
	write(1, "\n", 1);
	write(1, "(test 23) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-2147483648), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 24) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-214748364-8), 1);
	write(1, "\n", 1);
	write(1, "(test 24) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-214748364-8), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 25) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((42), 1);
	write(1, "\n", 1);
	write(1, "(test 25) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(42), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 26) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-42), 1);
	write(1, "\n", 1);
	write(1, "(test 26) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-42), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 27) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((-+42), 1);
	write(1, "\n", 1);
	write(1, "(test 27) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(-+42), 1);
	write(1, "\n", 1);

//itoa
	write(1, "\n", 1);
	write(1, "(test 28) itoa:    ", sizeof("(test 1) itoa:    "));
	ft_putnbr_fd((+-42), 1);
	write(1, "\n", 1);
	write(1, "(test 28) ft_itoa: ", sizeof("(test 1) ft_itoa: "));
	ft_putstr_fd(ft_itoa(+-42), 1);
	write(1, "\n", 1);

//memchr
	write(1, "\n", 1);
	write(1, "(test 1) memchr:    ", sizeof("(test 1) memchr:    ")-1);
	ft_putstr_fd(memchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 100), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_memchr: ", sizeof("(test 1) ft_memchr: ")-1);
	ft_putstr_fd(ft_memchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 100), 1);
	write(1, "\n", 1);

//memchr
	write(1, "\n", 1);
	write(1, "(test 2) memchr:    ", sizeof("(test 1) memchr:    ")-1);
	ft_putstr_fd(memchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 0), 1);
	write(1, "\n", 1);
	write(1, "(test 2) ft_memchr: ", sizeof("(test 1) ft_memchr: ")-1);
	ft_putstr_fd(ft_memchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 0), 1);
	write(1, "\n", 1);
	
//memchr
	write(1, "\n", 1);
	write(1, "(test 3) memchr:    ", sizeof("(test 1) memchr:    ")-1);
	ft_putstr_fd(memchr(" c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 1), 1);
	write(1, "\n", 1);
	write(1, "(test 3) ft_memchr: ", sizeof("(test 1) ft_memchr: ")-1);
	ft_putstr_fd(ft_memchr(" c <- This is the first c, ccccccc, c <- This is the last one.", 'c', 1), 1);
	write(1, "\n", 1);

//strchr
	write(1, "\n", 1);
	write(1, "(test 1) strchr:    ", sizeof("(test 1) memchr:    ")-1);
	ft_putstr_fd(strchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strchr: ", sizeof("(test 1) ft_memchr: ")-1);
	ft_putstr_fd(ft_strchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);

//strrchr
	write(1, "\n", 1);
	write(1, "(test 1) strrchr:    ", sizeof("(test 1) memechr:    ")-1);
	ft_putstr_fd(strrchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strrchr: ", sizeof("(test 1) ft_memcehr: ")-1);
	ft_putstr_fd(ft_strrchr("c <- This is the first c, ccccccc, c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);

//strrchr
	write(1, "\n", 1);
	write(1, "(test 1) strrchr:    ", sizeof("(test 1) memechr:    ")-1);
	ft_putstr_fd(strrchr("c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);
	write(1, "(test 1) ft_strrchr: ", sizeof("(test 1) ft_memcehr: ")-1);
	ft_putstr_fd(ft_strrchr("c <- This is the last one.", 'c'), 1);
	write(1, "\n", 1);

//memmove
	char aaa[100] = "0123456789abcdef";
 	char baa[100] = "0123456789abcdef";
	char ptraa[100]; 
	char ptr2aa[100];
	int		mmoveint;

	mmoveint = 8;
	memset(ptraa, 'x', 10);
	memset(ptr2aa, 'x', 10);
	memmove(baa + 5, baa, mmoveint);
	ft_memmove(aaa + 5, aaa, mmoveint);

	write(1, "\n", 1);
	write(1, "memmove:    ", sizeof("memcpye:    ")-1);
	write(1, &baa, 20);
	write(1, "\n", 1);
	
	write(1, "ft_memmove: ", sizeof("sssmemcpye: ")-1);
	write(1, &aaa, 20);
	write(1, "\n", 1);

//memmove
	char aaaa[100] = "0123456789abcdef";
 	char baaa[100] = "0123456789abcdef";
	
	mmoveint = 8;
	memmove(baaa, baaa + 5, mmoveint);
	ft_memmove(aaaa, aaaa + 5, mmoveint);

	write(1, "\n", 1);
	write(1, "memmove:    ", sizeof("memcpye:    ")-1);
	write(1, &baaa, 20);
	write(1, "\n", 1);
	
	write(1, "ft_memmove: ", sizeof("sssmemcpye: ")-1);
	write(1, &aaaa, 20);
	write(1, "\n", 1);

//memcpy
	char aa[100] = "helloia";
 	char ba[100] = "helloia";
	char ptra[100]; 
	char ptr2a[100];

	memset(ptra, 'x', 10);
	memset(ptr2a, 'x', 10);
	memcpy(ptr2a + 1, ba, 8);
	ft_memcpy(ptra + 1, aa, 8);

	write(1, "\n", 1);
	write(1, "memcpy:    ", sizeof("memcpy:    ")-1);
	write(1, &ptr2a, 15);
	write(1, "\n", 1);
	
	write(1, "ft_memcpy: ", sizeof("sssmemcpy: ")-1);
	write(1, &ptra, 15);
	write(1, "\n", 1);
	

//strdup
	char original[50] = "Get dup'd";
	char *cpy;

	write(1, "\nstrdup test: \n", 15);
	cpy = strdup(original);
	ft_putstr_fd(cpy, 1);
	write(1, "\n", 1);
	ft_putstr_fd(original, 1);
	write(1, "\n", 1);

//strjoin
	char *join;

	write(1, "\nstrjoin test: \n", 16);
	join = ft_strjoin(original, cpy);
	ft_putstr_fd(join, 1);
	write(1, "\n", 1);
	ft_putstr_fd("Get dup'dGet dup'd", 1);
	write(1, "\n", 1);


//putchar_fd	
	i = 0;
	write(1, "\n", 1);
	write(1, "(test 1) ft_putchar:    ", sizeof("(test 1) ft_putchar:    ")-1);
	while (i < 128)
	{
		if (i == '\n')
			i++;
		ft_putchar_fd(i, 1);
		i++;
	}
	i = '\n';
	ft_putchar_fd(i, 1);
	i = 0;
	write(1, "(test 1) ft_putchar:    ", sizeof("(test 1) ft_putchar:    ")-1);
	while (i < 128)
	{
		if (i == '\n')
			i++;
		write(1, &i, 1);
		i++;
	}
	i = '\n';
	write(1, &i, 1);

//strlcat
	write(1, "\n", 1);
	write(1, "Do the following check using the \"-fsanitize=address\" flag\n", sizeof("Do the following check ussing the \"-fsanitize=addres\" flag\n")-1);
	memset(dest, 'r', 15);
	memset(dest2, 'r', 15);
	write(1, "\n", 1);
	write(1, "ft_strlcat: ", sizeof("ft_strlcat: ")-1);
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, "strlcat:    ", sizeof("strlcat:    ")-1);
	ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 5));
	write(1, "\n", 1);
	write(1, "ft_strlcat: ", sizeof("ft_strlcat: ")-1);
	write(1, dest, 15);
	write(1, "\n", 1);
	write(1, "strlcat:    ", sizeof("strlcat:    ")-1);
	write(1, dest2, 15);
	write(1, "\n", 1);



//memccpy
	char a[100] = "helloia";
 	char b[100] = "helloia";
	char ptr[100]; 
	char ptr2[100];

	memset(ptr, 'x', 10);
	memset(ptr2, 'x', 10);
	memccpy(ptr2 + 1, b, 'o', 8);
	ft_memccpy(ptr + 1, a, 'o', 8);

	printf("memccpy gives   : |%s| with address: %p\n", ptr2, &ptr2);
	printf("ft_memccpy gives: |%s| with address: %p\n", ptr, &ptr);
	printf("\n");


	write(1, "\n", 1);
	write(1, "Also check ft_putstr and ft_putnbr lol coz the tester requires those to work properly\n", sizeof("Also check ft_putstr and ft_putnbr lol coz the tester requires those to work properly\n")-1);
	write (1, "\n", 1);

	write(1, "And everything alphabetically beyond strjoin\n", 45);
	write (1, "\n", 1);

	write(1, "Also check the bonus manually\n", sizeof("Also check the bonus manually\n")-1);
	write (1, "\n", 1);
}
