/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:04:08 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:24:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	join_at_begin(char *str, t_data *data)
{
	char	*new_value;
	size_t	new_size;
	size_t	str_len;

	str_len = ft_strlen(str);
	new_size = data->arg.size + str_len;
	new_value = ft_calloc(sizeof(char), new_size + 1);
	if (new_value == NULL)
		return (free(data->arg.content), EXIT_FAILURE);
	ft_strlcpy(new_value, str, str_len + 1);
	ft_memcpy(new_value + str_len, data->arg.content, data->arg.size);
	free(data->arg.content);
	data->arg.content = new_value;
	data->arg.size = new_size;
	return (EXIT_SUCCESS);
}

int	join_at_end(char *str, t_data *data)
{
	char	*new_value;
	size_t	new_size;
	size_t	str_len;

	str_len = ft_strlen(str);
	new_size = data->arg.size + str_len + 1;
	new_value = ft_calloc(sizeof(char), new_size);
	if (new_value == NULL)
		return (free(data->arg.content), EXIT_FAILURE);
	ft_memcpy(new_value, data->arg.content, data->arg.size);
	ft_strlcpy(new_value + data->arg.size, str, str_len + 1);
	free(data->arg.content);
	data->arg.content = new_value;
	data->arg.size = new_size - 1;
	return (EXIT_SUCCESS);
}

bool	flag(int flag, t_data *data)
{
	return (data->arg.flags & flag);
}

bool	type(char type, t_data *data)
{
	return (data->arg.type == type);
}

int	add_sign(t_data *data)
{
	if (type(STR, data) || type(CHAR, data))
		return (EXIT_SUCCESS);
	if (join_at_begin(data->arg.sign, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
