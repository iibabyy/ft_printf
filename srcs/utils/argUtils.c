/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 04:29:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:27:15 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	add_flag(t_data *data, int flag)
{
	if (flag == '0')
		data->arg.flags |= ZERO;
	else if (flag == '-')
		data->arg.flags |= MINUS;
	else if (flag == '#')
		data->arg.flags |= HASH;
	else if (flag == ' ')
		data->arg.flags |= SPACE;
	else if (flag == '+')
		data->arg.flags |= PLUS;
	else if (flag == '.')
		data->arg.flags |= DOT;
	else if (flag == WIDTH)
		data->arg.flags |= WIDTH;
}

void	check_flag(t_data *data)
{
	if (data->arg.flags & MINUS && data->arg.flags & ZERO)
		data->arg.flags = data->arg.flags & 11111101;
	if (data->arg.flags & PLUS && data->arg.flags & SPACE)
		data->arg.flags = data->arg.flags & 11101111;
	if (data->arg.flags & HASH
		&& (data->arg.type != HEXA && data->arg.type != HEXA_MAJ))
		data->arg.flags = data->arg.flags & 11110111;
}

void	get_flag(const char *format, int *index, t_data *data)
{
	int		i;

	i = *index;
	if (format[i] == '%')
		return (join_char(data, format[i]));
	while (is_valid_flag(format[i]))
		add_flag(data, format[i++]);
	check_flag(data);
	data->arg.min_width = parse_atoi(&format[i]);
	if (data->arg.min_width > 0)
		add_flag(data, WIDTH);
	while (ft_isdigit(format[i]))
		++i;
	if (format[i] == '.')
	{
		add_flag(data, '.');
		++i;
		data->arg.precision = parse_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			++i;
	}
	data->arg.type = format[i];
	*index = i;
}

void	get_sign(char *tmp, t_data *data)
{
	if (type(PTR, data) && ft_strcmp(tmp, "(nil)") != 0)
		return ((void)ft_strlcpy(data->arg.sign, "0x", 3));
	if (type(INT, data) == false)
		return ;
	if (tmp[0] != '-')
		return ;
	data->arg.sign[0] = '-';
	ft_memmove(tmp, tmp + 1,
		ft_strlen(tmp));
}

char	*next_arg(t_data *data)
{
	int		index;
	char	tmp[1024];

	ft_memset(tmp, 0, sizeof(char) * 1024);
	index = 0;
	if (type(DECIMAL, data) == true)
		data->arg.type = INT;
	if (type(STR, data))
		return (convert_str(va_arg(data->ap, char *)));
	else if (type(CHAR, data))
		return (convert_char((char)va_arg(data->ap, int)));
	else if (type(INT, data) || type(DECIMAL, data))
		convert_nbr((int)va_arg(data->ap, int), tmp, &index);
	else if (type(PTR, data))
		convert_pointer((void *)va_arg(data->ap, void *), tmp);
	else if (type(UNS_INT, data))
		convert_unsigned((unsigned)va_arg(data->ap, unsigned), tmp, &index);
	else if (type(HEXA, data))
		convert_hexa((unsigned)va_arg(data->ap, unsigned), HEXA_BASE,
			tmp, &index);
	else if (type(HEXA_MAJ, data))
		convert_hexa((unsigned)va_arg(data->ap, unsigned), HEXA_MAJ_BASE,
			tmp, &index);
	get_sign(tmp, data);
	return (ft_strdup(tmp));
}
