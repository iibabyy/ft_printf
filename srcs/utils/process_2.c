/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:58:28 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:24:12 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*		PROCESS SPACE		*/

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

/*		PROCESS HASH		*/

int	process_hash(t_data *data)
{
	if (type(HEXA, data) == false && type(HEXA_MAJ, data) == false)
		return (EXIT_SUCCESS);
	if (data->arg.content[0] == '0')
		return (EXIT_SUCCESS);
	else if (type(HEXA, data))
		ft_strlcpy(data->arg.sign, "0x", 3);
	else if (type(HEXA_MAJ, data))
		ft_strlcpy(data->arg.sign, "0X", 3);
	return (EXIT_SUCCESS);
}

/*		PROCESS PLUS		*/

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
