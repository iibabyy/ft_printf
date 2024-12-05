/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:52:44 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 13:53:05 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_space(t_data *data)
{
	if (type(INT, data) == false)
		return (EXIT_SUCCESS);
	if (flag(PLUS, data))
		return (EXIT_SUCCESS);
	if (data->arg.sign[0] == '-')
		return (EXIT_SUCCESS);
	else
		data->arg.sign[0] = ' ';
	return (EXIT_SUCCESS);
}
