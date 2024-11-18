/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolUtils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:44:51 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 17:18:16 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	isNumberType(t_data *data)
{
	return (data->arg.type == INT || data->arg.type == HEXA
		|| data->arg.type == UNS_INT || data->arg.type == DECIMAL);
}

bool	isHexaType(t_data *data)
{
	return (data->arg.type == HEXA || data->arg.type == HEXA_MAJ);
}
