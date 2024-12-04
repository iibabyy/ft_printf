/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argHandle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:16:09 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 21:25:14 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_flags(t_data *data)
{
	if (flag(DOT, data) && (type(INT, data) || type(UNS_INT, data) || type(HEXA, data) || type(HEXA_MAJ, data)) && data->arg.content[0] == '0' && data->arg.precision == 0)
	{
		data->arg.content[--data->arg.size] = '\0';
	}
	if (flag(PLUS, data) && process_plus(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(SPACE, data) && process_space(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(HASH, data) && process_hash(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(DOT, data) && process_dot(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(MINUS, data) && process_minus(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(ZERO, data) && process_zero(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (add_sign(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (process_padding(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

char	*handle_arg(const char *format, int *index, t_data *data)
{
	ft_memset(&data->arg, 0, sizeof(t_arg));
	*index += 1;
	if (format[*index] == '%')
	{
		data->arg.content = ft_strdup("%");
		if (data->arg.content == NULL)
			return (NULL);
		return (data->arg.size = 1, data->arg.content);
	}
	get_flag(format, index, data);
	data->arg.content = next_arg(data);
	if (data->arg.content == NULL)
		return (NULL);
	if (type(CHAR, data))
		data->arg.size = 1;
	else
		data->arg.size = ft_strlen(data->arg.content);
	if (data->arg.flags == 0)
		add_sign(data);
	else if (process_flags(data) == EXIT_FAILURE)
		data->error = true;
	return (data->arg.content);
}
