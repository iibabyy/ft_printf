/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:33 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 13:51:46 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

bool	padding_needed(t_data *data)
{
	if (flag(WIDTH, data) == false)
		return (false);
	else if (flag(MINUS, data))
		return (false);
	else if (flag(ZERO, data) == true
			&& flag(HASH, data) == false
			&& flag(DOT, data) == false)
		return (false);
	return (true);
}

int	process_padding(t_data *data)
{
	char	*tmp;
	int		width_needed;
	int		arg_len;

	if (padding_needed(data) == false)
		return (EXIT_SUCCESS);
	arg_len = data->arg.size;
	width_needed = data->arg.min_width - arg_len;
	if (width_needed <= 0)
		return (EXIT_SUCCESS);
	tmp = malloc(sizeof(char) * (width_needed + 1));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	ft_memset(tmp, ' ', sizeof(char) * width_needed);
	tmp[width_needed] = '\0';
	if (join_at_begin(tmp, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(tmp);
	return (EXIT_SUCCESS);
}
