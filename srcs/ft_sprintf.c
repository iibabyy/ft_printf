/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:31:24 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:23:56 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*		FT_SPRINTF	*/

void	init_sprintf(t_data *data)
{
	ft_memset(data, 0, sizeof(t_data));
	data->fd = 1;
	data->sprintf = true;
}

char	*end_sprintf(t_data *data)
{
	if (end_printf(data) == -1)
		return (NULL);
	return (data->sprintf_buffer);
}

char	*ft_sprintf(const char *format, ...)
{
	t_data	data;
	int		i;

	if (format == NULL)
		return (NULL);
	init_sprintf(&data);
	va_start(data.ap, format);
	if (check_args(format) == EXIT_FAILURE)
		return (va_end(data.ap), NULL);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			printf_arg(format, &i, &data);
		else
			join_char(&data, format[i]);
		if (data.error == true)
			return (NULL);
	}
	return (end_sprintf(&data));
}
