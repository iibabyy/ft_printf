/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:52:44 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 21:38:50 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*		PROCESS PADDING		*/

int	process_padding(t_data *data)
{
	char	*tmp;
	int		width_needed;
	int		arg_len;

	if (flag(WIDTH, data) == false)
		return (EXIT_SUCCESS);
	if (flag(MINUS, data) || (flag(ZERO, data) && flag(HASH, data) == false && flag(DOT, data) == false))
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

/*		PROCESS MINUS		*/

int	process_minus(t_data *data)
{
	int	width_needed;
	int	arg_len;

	if (flag(WIDTH, data) == false)
		return (EXIT_SUCCESS);
	arg_len = data->arg.size + ft_strlen(data->arg.sign);
	width_needed = data->arg.min_width - arg_len;
	if (width_needed <= 0)
		return (EXIT_SUCCESS);
	while (width_needed--)
	{
		if (join_at_end(" ", data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*		PROCESS ZERO		*/

int	process_zero(t_data *data)
{
	char	*tmp;
	int		width_needed;
	int		arg_len;

	if (flag(WIDTH, data) == false || flag(DOT, data) || flag(MINUS, data) || flag(HASH, data))
		return (EXIT_SUCCESS);
	else if (type(PTR, data) || type(CHAR, data) || type(STR, data))
		return (EXIT_SUCCESS);
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

/*		PROCESS DOT		*/

int	process_dot(t_data *data)
{
	int		precision_needed;
	int		arg_len;

	if (type(CHAR, data) || type(PTR, data))
		return (EXIT_SUCCESS);
	arg_len = data->arg.size;
	precision_needed = data->arg.precision - arg_len;
	if (precision_needed < 0 && type(STR, data) == false)
		return (EXIT_SUCCESS);
	else if (precision_needed > 0 && type(STR, data))
		return (EXIT_SUCCESS);
	while (precision_needed < 0)
	{
		data->arg.content[--arg_len] = 0;
		++precision_needed;
		--data->arg.size;
	}
	while (precision_needed > 0)
	{
		if (join_at_begin("0", data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		--precision_needed;
	}
	return (EXIT_SUCCESS);
}
