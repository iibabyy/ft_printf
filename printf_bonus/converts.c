/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 03:25:00 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 15:36:07 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert_lhexa(unsigned long int num, char *hex, char *temp, int *index)
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

void	convert_pointer(void *pointer, char *tmp)
{
	int	index;

	if (pointer == 0)
	{
		ft_strlcat(tmp, "(nil)", 1024);
		return ;
	}
	// ft_strlcat(tmp, "0x", 1024);
	index = 0;
	convert_lhexa((unsigned long)pointer, "0123456789abcdef", tmp, &index);
}

void	convert_char(char c, char *tmp)
{
	tmp[0] = c;
	tmp[1] = '\0';
}



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

char 	*convert_str(char *str)
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
