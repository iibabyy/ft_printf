/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:34:18 by ibaby             #+#    #+#             */
/*   Updated: 2024/05/18 01:30:53 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	int		size;

	size = ft_strlen((char *)src) + 1;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (str = 0);
	str = ft_memmove(str, src, size);
	return (str);
}

/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>
int	main(void) {

	const char * original = "The original string.";

	// On duplique la chaîne de caractères initiale.
	char * copy = ft_strdup( original );

	// On passe chaque lettre en majuscule.
	char * ptr = copy;
	while( *ptr != '\0' ) {
		*ptr = toupper( *ptr );
		ptr++;
	}

	// On affiche la chaîne finale
	printf( "%s\n", copy );

	// Sans oublier de libérer l'espace mémoire au final.
	free( copy );

	return (EXIT_SUCCESS);
}
*/

/*
#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(int argc, const char *argv[])
{
	char	str[];
	char	*str_dup;

	str[] = "lorem ipsum dolor sit amet";
	alarm(5);
	if (argc == 1)
		return (0);
	if (atoi(argv[1]) == 1)
	{
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
		else
			free(str_dup);
	}
	return (0);
}
*/