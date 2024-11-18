/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:15:13 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/18 18:14:16 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	flag(int flag, t_data *data)
{
	return (data->arg.flags & flag);
}

bool	type(char type, t_data *data)
{
	return (data->arg.type == type);
}

int	processPlus(t_data *data)
{
	if (type(INT, data) == false)
		return (EXIT_SUCCESS);
	if (data->arg.sign[0] == '-')
		return (EXIT_SUCCESS);
	else
		data->arg.sign[0] = '+';
	return (EXIT_SUCCESS);
}

int	processSpace(t_data *data)
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

int	processHash(t_data *data)
{
	if (type(HEXA, data) == false && type(HEXA_MAJ, data) == false)
		return (EXIT_SUCCESS);
	ft_strlcpy(data->arg.sign, "0x", 3);
	return (EXIT_SUCCESS);
}

int	processDot(t_data *data)
{
	char	*tmp;
	int		precisionNeeded;
	int		argLen;

	argLen = ft_strlen(data->arg.content);
	precisionNeeded = data->arg.precision - argLen;
	if (precisionNeeded == 0)
		return (EXIT_SUCCESS);
	while (argLen > precisionNeeded)
	{
		data->arg.content[--argLen] = 0;
	}
	while (argLen++ > precisionNeeded)
	{
		tmp = data->arg.content;
		data->arg.content = ft_strjoin("0", data->arg.content);
		free(tmp);
		if (data->arg.content == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	processMinus(t_data *data)
{
	int	widthNeeded;
	int	argLen;

	if (flag(WIDTH, data) == false)
		return (EXIT_SUCCESS);
	argLen = ft_strlen(data->arg.content);
	widthNeeded = data->arg.min_width - argLen;
	if (widthNeeded <= 0)
		return (EXIT_SUCCESS);
	while (argLen++ < widthNeeded)
	{
		data->arg.content = ft_re_strjoin(data->arg.content, " ");
		if (data->arg.content == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	processZero(t_data *data)
{
	char	*tmp;
	int		widthNeeded;
	int		argLen;

	if (flag(WIDTH, data) == false || flag(MINUS, data))
		return (EXIT_SUCCESS);
	argLen = ft_strlen(data->arg.content);
	widthNeeded = data->arg.min_width - argLen;
	if (widthNeeded <= 0)
		return (EXIT_SUCCESS);
	tmp = malloc(sizeof(char) * widthNeeded);
	if (tmp == NULL)
		return (EXIT_FAILURE);
	ft_memset(tmp, '0', sizeof(char) *widthNeeded);
	tmp = ft_re_strjoin(tmp, data->arg.content);
	free(data->arg.content);
	data->arg.content = tmp;
	if (tmp == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	addSign(t_data *data)
{
	char	*tmp;

	tmp = ft_strjoin(data->arg.sign, data->arg.content);
	free(data->arg.content);
	data->arg.content = tmp;
	if (tmp == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	addPadding(t_data *data)
{
	char	*tmp;
	int		widthNeeded;
	int		argLen;

	if (flag(WIDTH, data) == false)
		return (EXIT_SUCCESS);
	if (flag(MINUS, data) || flag(ZERO, data))
		return (EXIT_SUCCESS);
	argLen = ft_strlen(data->arg.content);
	widthNeeded = data->arg.min_width - argLen;
	if (widthNeeded <= 0)
		return (EXIT_SUCCESS);
	tmp = malloc(sizeof(char) * widthNeeded);
	if (tmp == NULL)
		return (EXIT_FAILURE);
	ft_memset(tmp, ' ', sizeof(char) *widthNeeded);
	tmp = ft_re_strjoin(tmp, data->arg.content);
	free(data->arg.content);
	data->arg.content = tmp;
	if (tmp == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	processFlags(t_data *data)
{
	if (flag(PLUS, data) && processPlus(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(SPACE, data) && processSpace(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(HASH, data) && processHash(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(DOT, data) && processDot(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(MINUS, data) && processMinus(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (flag(ZERO, data) && processZero(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (addSign(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else if (addPadding(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	handleArg(const char *format, int *index, t_data *data)
{
	ft_memset(&data->arg, 0, sizeof(t_data));
	data->arg.sign = malloc(10000);
	*index += 1;
	if (format[*index] == '%')
		return (joinStr(data, "%"));
	getFlag(format, index, data);
	data->arg.content = nextArg(data);
	if (data->arg.content == NULL)
		return ((void)(data->error = true));
	if (data->arg.flags == 0)
		joinStr(data, data->arg.sign);
	else if (processFlags(data) == EXIT_FAILURE)
		data->error = true;
	joinStr(data, data->arg.content);
	free(data->arg.content);
	data->arg.content = NULL;
	if (data->error != true)
		flushBuffer(data);
}

int ft_printf(const char *format, ...)
{
	t_data	data;
	int			i;

	if (format == NULL)
		return (0);
	ft_memset(&data, 0, sizeof(t_data));
	va_start(data.ap, format);
	if (checkArgs(format) == EXIT_FAILURE)
		return (va_end(data.ap), -1);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			handleArg(format, &i, &data);
		else
			joinChar(&data, format[i]);
		if (data.error == true)
			return (-1);
	}
	flushBuffer(&data);
	va_end(data.ap);
	printf("%s\n", data.arg.sign);
	printf("%s\n", data.str);
	if (data.error == true)
		return (-1);
	else
		return (data.totalSize);
}

/*
| Flag      | c (char) | s (string) | p (pointer) | d/i (int) | u (unsigned int) | x/X (hex int) | f/g/e (float) |
|-----------|----------|------------|-------------|-----------|------------------|---------------|---------------|
| -         | Yes      | Yes        | Yes         | Yes       | Yes              | Yes           | Yes           |
| 0         | No       | No         | No          | Yes       | Yes              | Yes           | Yes           |
| .         | No       | Yes        | No          | Yes       | Yes              | Yes           | Yes           |
| #         | No       | No         | No          | No        | No               | Yes           | Yes           |
| +         | No       | No         | No          | Yes       | No               | No            | Yes           |
| (space)   | No       | No         | No          | Yes       | No               | No            | Yes           |
| Min Width | Yes      | Yes        | Yes         | Yes       | Yes              | Yes           | Yes           |

Min Width = number

*/