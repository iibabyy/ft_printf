/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:54:06 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/05 13:54:31 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	process_plus(t_data *data)
{
	if (type(INT, data) == false)
		return (EXIT_SUCCESS);
	if (data->arg.sign[0] == '-')
		return (EXIT_SUCCESS);
	else
		data->arg.sign[0] = '+';
	return (EXIT_SUCCESS);
}
