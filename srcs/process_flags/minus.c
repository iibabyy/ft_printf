/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:50:36 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 13:50:58 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

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
