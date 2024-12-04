/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 02:17:04 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:27:15 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

bool	is_valid_type(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X');
}

bool	is_valid_flag(char c)
{
	return (c == '-' || c == '#' || c == ' ' || c == '+' || c == '0');
}

int	invalid_flag(char c)
{
	ft_putstr_fd("Error: unexpected flag `", STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	return (EXIT_FAILURE);
}

int	check_nbr(const char **ptr)
{
	const char	*tmp;
	long int	number;

	tmp = *ptr;
	if (ft_isdigit(*tmp) == false)
		return (EXIT_SUCCESS);
	number = parse_atoi(tmp);
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

int	check_args(const char *ptr)
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
			while (is_valid_flag(*ptr))
				++ptr;
			if (check_nbr(&ptr) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			if (*ptr == '.')
			{
				++ptr;
				if (check_nbr(&ptr) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			if (is_valid_type(*ptr) == false)
				return (invalid_flag(*ptr));
			++ptr;
		}
	}
	return (EXIT_SUCCESS);
}
