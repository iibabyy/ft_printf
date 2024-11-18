/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:22:33 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 17:21:00 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	strjoin_char(char *str, long size, char c)
{
	long	i;

	i = -1;
	while (str[++i])
	{
		if (i + 2 > size)
			return ;
	}
	str[i] = c;
	str[i + 1] = '\0';
}

void	flushBuffer(t_data *data)
{
	if (data->size == 0)
		return ;
	if (write(STDOUT_FILENO, data->str, data->size) == -1)
		data->error = true;
	ft_memset(data->str, 0, data->size);
	data->size = 0;
}

void	joinChar(t_data *data, char c)
{
	data->str[data->size++] = c;
	++data->totalSize;
	if (c == '\n' || data->size == 1024)
		flushBuffer(data);
}

void	joinStr(t_data *data, char *str)
{
	if (type(CHAR, data))
		joinChar(data, *str++);
	else while (*str)
		joinChar(data, *str++);
}

long	parseAtoi(const char *str)
{
	int     i;
	int     sign;
	long     number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
			if (str[i] == '-')
					sign = -sign;
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			number = number * 10 + (str[i] - '0');
			if ((sign == 1 && number > INT_MAX) || (sign == -1 && number > (long)INT_MAX + 1))
				return (OUT_OF_RANGE);
			i++;
	}
	return (number * sign);
}
