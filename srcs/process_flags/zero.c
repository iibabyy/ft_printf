/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:50:10 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 14:38:31 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

bool	zero_needed(t_data *data)
{
	if (flag(WIDTH, data) == false || flag(DOT, data)
		|| flag(MINUS, data) || flag(HASH, data))
		return (false);
	if (type(PTR, data) || type(CHAR, data) || type(STR, data))
		return (false);
	return (true);
}

int	process_zero(t_data *data)
{
	char	*tmp;
	int		width_needed;
	int		arg_len;

	if (zero_needed(data) == false)
		return (false);
	arg_len = data->arg.size + ft_strlen(data->arg.sign);
	width_needed = data->arg.min_width - arg_len;
	if (width_needed <= 0)
		return (EXIT_SUCCESS);
	tmp = malloc(sizeof(char) * (width_needed + 1));
	if (tmp == NULL)
		return (EXIT_FAILURE);
	ft_memset(tmp, '0', sizeof(char) * width_needed);
	tmp[width_needed] = '\0';
	if (join_at_begin(tmp, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	free(tmp);
	return (EXIT_SUCCESS);
}
