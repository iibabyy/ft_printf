/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 00:22:33 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:24:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	flush_buffer(t_data *data)
{
	char	*sprintf;
	size_t	buffer_size;

	if (data->size == 0)
		return ;
	if (data->sprintf == true)
	{
		buffer_size = data->total_size - data->size;
		sprintf = malloc(sizeof(char) * (data->total_size + 1));
		if (sprintf == NULL)
			return ((void)(data->error = true));
		if (data->sprintf_buffer != NULL)
		{
			ft_memcpy(sprintf, data->sprintf_buffer, buffer_size);
			free(data->sprintf_buffer);
		}
		ft_memcpy(sprintf + buffer_size, data->str, data->size);
		sprintf[data->total_size] = '\0';
		data->sprintf_buffer = sprintf;
		return ;
	}
	else if (write(data->fd, data->str, data->size) == -1)
		data->error = true;
	ft_memset(data->str, 0, data->size);
	data->size = 0;
}

void	join_char(t_data *data, char c)
{
	data->str[data->size++] = c;
	++data->total_size;
	if (c == '\n' || data->size == 1024)
		flush_buffer(data);
}

void	join_arg(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->arg.size)
		join_char(data, data->arg.content[i++]);
}

void	join_str(t_data *data, char *str)
{
	while (*str)
		join_char(data, *str++);
}

long	parse_atoi(const char *str)
{
	int		i;
	int		sign;
	long	number;

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
		if ((sign == 1 && number > INT_MAX)
			|| (sign == -1 && number > (long)INT_MAX + 1))
			return (OUT_OF_RANGE);
		i++;
	}
	return (number * sign);
}
