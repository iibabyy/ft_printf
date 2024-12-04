/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 03:10:05 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:24:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
	index = 0;
	convert_lhexa((unsigned long)pointer, "0123456789abcdef", tmp, &index);
}

char	*convert_char(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
