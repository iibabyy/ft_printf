/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:27:00 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 21:22:26 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_dprintf(int fd, t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->fd = fd;
}

int	ft_dprintf(int fd, const char *format, ...)
{
	t_data	data;
	int		i;

	if (format == NULL)
		return (-1);
	else if (fd < 0)
		return (-1);
	init_dprintf(fd, &data);
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
