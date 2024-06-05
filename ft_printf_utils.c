/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 19:18:10 by ibaby             #+#    #+#             */
/*   Updated: 2024/06/05 19:23:22 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	if (write(1, &c, 1) < 0)
	{
		return (-1);
	}
	return (1);
}

int	print_lhexa(unsigned long int num, char *hex)
{
	int	check;
	int	temp;

	check = 0;
	temp = 0;
	if (num >= 16)
	{
		temp = print_lhexa(num / 16, hex);
		if (temp < 0)
			return (-1);
		check += temp;
		temp = print_lhexa(num % 16, hex);
		if (temp < 0)
			return (-1);
		check += temp;
	}
	else if (num < 16)
	{
		if (ft_putchar(hex[num]) < 0)
			return (-1);
		check++;
	}
	return (check);
}

int	print_pointer(void *pointer)
{
	unsigned long	p;
	int				check;
	int				temp;

	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	temp = 0;
	p = (unsigned long)pointer;
	check = write(1, "0x", 2);
	if (check < 0)
		return (-1);
	temp = print_lhexa(p, "0123456789abcdef");
	if (temp < 0)
		return (-1);
	check += temp;
	return (check);
}

int	convert_flag(const char flag, va_list ap)
{
	if (flag == 'c')
		return (print_char(va_arg(ap, int)));
	else if (flag == 's')
		return (print_str(va_arg(ap, char *)));
	else if (flag == 'p')
		return (print_pointer(va_arg(ap, void *)));
	else if (flag == 'd')
		return ((print_nbr(va_arg(ap, int))));
	else if (flag == 'i')
		return ((print_nbr(va_arg(ap, int))));
	else if (flag == 'u')
		return ((print_unsigned(va_arg(ap, unsigned int))));
	else if (flag == 'x')
		return ((print_hexa(va_arg(ap, unsigned int), "0123456789abcdef")));
	else if (flag == 'X')
		return ((print_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF")));
	else if (flag == '\0')
		return (-1);
	else
		return ((write(1, "%", 1)));
}

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*retval;

	i = 0;
	while (str[i] && str[i] != (unsigned char)c)
		i++;
	if (str[i] == '\0' && (unsigned char)c != '\0')
		return (retval = 0);
	retval = (char *)str + i;
	return (retval);
}
