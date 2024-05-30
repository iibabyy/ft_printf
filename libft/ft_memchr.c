/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:34:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/05/18 19:47:59 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *str, int tofind, size_t n)
{
	unsigned const char	*s;

	s = str;
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)tofind)
		{
			return ((unsigned char *)s);
		}
		s++;
	}
	return (0);
}

/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	ft_print_result(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void	check_memchr(void *s, char c, int n)
{
	const char	*str;

	str = ft_memchr(s, c, n);
	if (!str)
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int	main(int argc, const char *argv[])
{
	int	arg;
	int	tab[7];

		tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		check_memchr("bonjour", 'b', 4);
	else if (arg == 2)
		check_memchr("bonjour", 'o', 7);
	else if (arg == 3)
		check_memchr("bonjourno", 'n', 2);
	else if (arg == 4)
		check_memchr("bonjour", 'j', 6);
	else if (arg == 5)
		check_memchr("bonjour", 's', 7);
	else if (arg == 6)
	{
		printf("%s", (char *)ft_memchr(tab, -1, 7));
	}
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void) {

	char data[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	const unsigned int size = 10;

	// On recherche une valeur inhéxistante :
	void * found = ft_memchr( data, 57, size );
	printf( "57 is %s\n", ( found != 0 ? "found" : "not found" ) );

	// On recherche une valeur existante :
	found = ft_memchr( data, 50, size );
	printf( "50 is %s\n", ( found != 0 ? "found" : "not found" ) );
	if ( found != 0 ) {
		printf( "La valeur à la position calculée est %d\n",
			*((char *) found) );
	}

	return (0);
}
*/