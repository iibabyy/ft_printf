/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:14:01 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/05 19:23:45 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

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
