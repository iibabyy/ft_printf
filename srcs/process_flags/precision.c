/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:49:30 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 14:42:00 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	null_str_precision(t_data *data)
{
	if (data->arg.precision < 6)
	{
		data->arg.content[0] = '\0';
		data->arg.size = 0;
	}
	return (EXIT_SUCCESS);
}

bool	dot_needed(t_data *data)
{
	if (type(CHAR, data) || type(PTR, data))
		return (false);
	return (true);
}

int	process_dot(t_data *data)
{
	int		precision_needed;
	int		arg_len;

	if (dot_needed(data) == false)
		return (EXIT_SUCCESS);
	else if (data->arg.null_str == true)
		return (null_str_precision(data));
	arg_len = data->arg.size;
	precision_needed = data->arg.precision - arg_len;
	if (precision_needed < 0 && type(STR, data) == false)
		return (EXIT_SUCCESS);
	else if (precision_needed > 0 && type(STR, data))
		return (EXIT_SUCCESS);
	while (precision_needed < 0)
	{
		data->arg.content[--arg_len] = 0;
		--data->arg.size;
		++precision_needed;
	}
	while (precision_needed-- > 0)
	{
		if (join_at_begin("0", data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
