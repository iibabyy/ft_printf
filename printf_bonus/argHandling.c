/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argHandling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 04:29:52 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 18:12:48 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	addFlag(t_data *data, int flag)
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

void	checkFlag(t_data *data)
{
	if (data->arg.flags & MINUS && data->arg.flags & ZERO)
		data->arg.flags = data->arg.flags & 11111101;		// ignorer le flag ZERO
	if (data->arg.flags & PLUS && data->arg.flags & SPACE)
		data->arg.flags = data->arg.flags & 11101111;
	if (data->arg.flags & HASH && (data->arg.type != HEXA && data->arg.type != HEXA_MAJ))
		data->arg.flags = data->arg.flags & 11110111;
}

void	getFlag(const char *format, int *index, t_data *data)
{
	int		i;
	int		temp;

	i = *index;
	if (format[i] == '%')
		return (joinChar(data, format[i]));
	while (isValidFlag(format[i]))		/*	while not at the end of the flag	*/
		addFlag(data, format[i++]);
	checkFlag(data);
	data->arg.min_width = parseAtoi(&format[i]);
	if (data->arg.min_width > 0)
		addFlag(data, WIDTH);
	while (ft_isdigit(format[i]))
		++i;
	if (format[i] == '.')
	{
		addFlag(data, DOT);
		++i;
		temp = i;
		while (ft_isdigit(format[i]))
			++i;
		data->arg.precision = parseAtoi(&format[temp]);
	}
	data->arg.type = format[i];
	*index = ++i;
}

void	getSign(char *tmp, t_data *data)
{
	if (type(PTR, data))
		return ((void)ft_strlcpy(data->arg.sign, "0x", 2));
	if (type(INT, data) == false)
		return ;
	if (tmp[0] != '-')
		return ;
	data->arg.sign[0] = '-';
	ft_memmove(tmp, tmp + 1, 
		ft_strlen(tmp + 1));
	printf("tmp: \n");
	printf("%s\n", (char *)tmp);
}

char	*nextArg(t_data *data)
{
	int		index;
	char	*tmp;

	tmp = malloc(1024 * sizeof(char));
	ft_memset(tmp, 0, 1024 * sizeof(char));
	index = 0;
	if (type(DECIMAL, data) == true)
		data->arg.type = INT;
	if (type(STR, data))
		return (ft_strdup(convert_str(va_arg(data->ap, char *))));
	else if (type(INT, data) || type(DECIMAL, data))
		convert_nbr((int)va_arg(data->ap, int), tmp, &index);
	else if (type(CHAR, data))
		convert_char((char)va_arg(data->ap, int), tmp);
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
	getSign(tmp, data);
	return (ft_strdup(tmp));
}
