/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:14:01 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/05 19:21:29 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*retval;

	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (str[i] == '\0' && (unsigned char)c != '\0')
		return (retval = 0);
	retval = (char *)str + i;
	return (retval);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		check;
	int		temp;

	free((i = 0, check = 0, temp = 0, va_start(ap, str), NULL));
	if (!str)
		return (va_end(ap), -1);
	while (str[i] != '\0')
	{
		while ((str[i] != '%') && (str[i] != '\0'))
		{
			temp = write(1, &str[i++], 1);
			if (temp < 0)
				return (-1);
			check += temp;
		}
		if (str[i] == '\0')
			return (va_end(ap), check);
		temp = convert_flag(str[++i], ap);
		if (temp < 0)
			return (va_end(ap), -1);
		free((check += temp, i++, NULL));
	}
	return (va_end(ap), check);
}

/*
int	num_flags(const char *str)
{
	char	*flags;
	int		i;
	int		count;

	flags = "cspdiuxX%";
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr(flags, str[i + 1]))
			{
				count++;
				i++;
			}
			else
			{
				return(ft_error("flags incorrects\n"));
			}
		}
		i++;
	}
	return (count);
}
*/

// cspdiuxX%
/*  thoughts
	-> savoir le type de l'arg avec c
	-> prendre l'arg avec va_arg
		.directement le bon arg ?
	-> transformer l'arg en string
		.fonctions pour chaque type ?
	-> afficher le string
*/
/*  conversions
		. %c Prints a single character.
		. %s Prints a string (as defined by the common C convention).
		. %p The void
			* pointer argument has to be printed in hexadecimal format.
		. %d Prints a decimal (base 10) number.
		. %i Prints an integer in base 10.
		. %u Prints an unsigned decimal (base 10) number.
		. %x Prints a number in hexadecimal (base 16) lowercase format.
		. %X Prints a number in hexadecimal (base 16) uppercase format.
		. %% Prints a percent sign
*/

int	convert_flag(const char flag, va_list ap)
{
	if (flag == 'c')
		return (print_char(va_arg(ap, int)));
	else if (flag == 's')
		return (print_str(va_arg(ap, char *)));
	else if (flag == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (flag == 'd')
		return ((print_nbr(va_arg(ap, int))));
	else if (flag == 'i')
		return ((print_nbr(va_arg(ap, int))));
	else if (flag == 'u')
		return ((print_unsigned(va_arg(ap, unsigned int))));
	else if (flag == 'x')
		return ((print_hexa(va_arg(ap, unsigned int), "0123456789abcdef")));
	else if (flag == 'X')
		return ((print_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF")));
	else if (flag == '\0')
		return (-1);
	else
		return ((write(1, "%", 1)));
}
