/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:33:55 by ibaby             #+#    #+#             */
/*   Updated: 2024/05/19 20:58:17 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numlen(int num)
{
	int	i;

	i = 0;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	reversetab(char *str)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}

void	reverse(char *str, int sign, int n)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else if (sign >= 0)
		reversetab(str);
	else
	{
		reversetab(str + 1);
		str[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	long	c;
	char	*str;

	sign = 1;
	i = 0;
	c = (long)n;
	if (n < 0)
	{
		sign = -sign;
		c = -c;
		i = 1;
	}
	str = malloc(sizeof(char) * (numlen(c) + 5));
	if (!str)
		return (0);
	while (c)
	{
		str[i++] = c % 10 + '0';
		c /= 10;
	}
	str[i] = '\0';
	reverse(str, sign, n);
	return (str);
}

/*
#include <stdio.h>
int main (int ac, char **av)
{
	if (ac == 2)
	{
		printf("il y a %d chiffres dans %d\n", numlen(ft_atoi(av[1])),
			ft_atoi(av[1]));
		printf("l'entier rentre en parametes est %s\n", ft_itoa(atoi(av[1])));
	}
	return (0);
}
*/

/*
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_print_result(char *s)
{
	int	len;

	if (!s)
		write(1, "NULL", 4);
	else
	{
		len = 0;
		while (s[len])
			len++;
		write(1, s, len);
		free(s);
	}
}

int	main(int argc, const char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
		ft_print_result(ft_itoa(0));
	else if (arg == 2)
		ft_print_result(ft_itoa(9));
	else if (arg == 3)
		ft_print_result(ft_itoa(-9));
	else if (arg == 4)
		ft_print_result(ft_itoa(10));
	else if (arg == 5)
		ft_print_result(ft_itoa(-10));
	else if (arg == 6)
		ft_print_result(ft_itoa(8124));
	else if (arg == 7)
		ft_print_result(ft_itoa(-9874));
	else if (arg == 8)
		ft_print_result(ft_itoa(543000));
	else if (arg == 9)
		ft_print_result(ft_itoa(-2147483648LL));
	else if (arg == 10)
		ft_print_result(ft_itoa(2147483647));
	return (0);
}
*/