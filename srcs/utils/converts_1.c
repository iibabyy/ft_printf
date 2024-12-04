/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:25:00 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:24:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	convert_nbr(int num, char *tmp, int *index)
{
	long	c;

	c = (long)num;
	if (c < 0)
	{
		tmp[*index] = '-';
		c = -c;
		*index += 1;
	}
	if (c >= 10)
	{
		convert_nbr(c / 10, tmp, index);
		convert_nbr(c % 10, tmp, index);
	}
	else if (c <= 9)
	{
		tmp[*index] = c + 48;
		*index += 1;
	}
}

void	convert_unsigned(unsigned int c, char *tmp, int *index)
{
	if (c >= 10)
	{
		convert_nbr(c / 10, tmp, index);
		convert_nbr(c % 10, tmp, index);
	}
	else if (c <= 9)
	{
		tmp[*index] = c + 48;
		*index += 1;
	}
}

char	*convert_str(char *str)
{
	if (str == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

void	convert_hexa(unsigned int num, char *hex, char *temp, int *index)
{
	if (num >= 16)
	{
		convert_lhexa(num / 16, hex, temp, index);
		convert_lhexa(num % 16, hex, temp, index);
	}
	else if (num < 16)
	{
		temp[*index] = hex[num];
		*index += 1;
	}
}
