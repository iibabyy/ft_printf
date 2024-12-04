/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:15:13 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 21:22:08 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_arg(const char *format, int *index, t_data *data)
{
	char	*arg;

	arg = handle_arg(format, index, data);
	if (arg == NULL)
		return ((void)(data->error = true));
	join_arg(data);
	free(arg);
}

void	init_printf(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->fd = 1;
}

int	end_printf(t_data *data)
{
	flush_buffer(data);
	va_end(data->ap);
	if (data->error == true)
		return (-1);
	else
		return (data->total_size);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;
	int		i;

	if (format == NULL)
		return (-1);
	init_printf(&data);
	va_start(data.ap, format);
	if (check_args(format) == EXIT_FAILURE)
		return (va_end(data.ap), -1);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			printf_arg(format, &i, &data);
		else
			join_char(&data, format[i]);
		if (data.error == true)
			return (-1);
	}
	return (end_printf(&data));
}
