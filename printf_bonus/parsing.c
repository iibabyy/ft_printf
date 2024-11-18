/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:17:04 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 15:36:07 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	isValidType(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X');
}

bool	isValidFlag(char c)
{
	return (c == '-' || c == '#' || c == ' ' || c == '+' || c == '0');
}

int	invalidFlag(char c)
{
	ft_putstr_fd("Error: unexpected flag `", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	checkNbr(const char **ptr)
{
	const char	*tmp;
	long int	number;

	tmp = *ptr;
	if (ft_isdigit(*tmp) == false)
		return (EXIT_SUCCESS);
	number = parseAtoi(tmp);
	if (number == OUT_OF_RANGE)
	{
		ft_putendl_fd("Error: number too large", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (ft_isdigit(*tmp) == true)
		++tmp;
	*ptr = tmp;
	return (EXIT_SUCCESS);
}

int	checkArgs(const char *ptr)
{
	while (*ptr)
	{
		if (*ptr++ == '%')
		{
			if (*ptr == '%')
			{
				++ptr;
				continue ;
			}
			while (isValidFlag(*ptr))
				++ptr;
			if (checkNbr(&ptr) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			if (*ptr == '.')
			{
				++ptr;
				if (checkNbr(&ptr) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			if (isValidType(*ptr) == false)		/*		invalid type	*/
				return (invalidFlag(*ptr));
			++ptr;
		}
	}
	return (EXIT_SUCCESS);
}
