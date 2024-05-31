#include <unistd.h>
#include "printf.h"

int print_char(char c)
{
    int check;
	int temp;

	temp = 0;
	check = 0;
	temp = write(1, &c, 1);
    if (temp < 0)
        return(-1);
    check += temp;
    return (check);
}

int print_str(char *str)
{
    int check;
    int i;

    i = 0;
    check = 0;
	if (!str)
		return(0);
    while (str[i])
    {
		if (write(1, &str[i], 1) < 0)
            return(-1);
        check++;
        i++;
    }
    return (check);
}

int print_nbr(int n)
{
    long    c;
    int     check;
	int		temp;

	check = 0;
    c = (long)n;
    temp = 0;
    if (c < 0)
    {
        if (ft_putchar('-') < 0)
            return (-1);
		check++;
        c = -c;
    }
    if (c >= 10)
    {
        temp = print_nbr(c / 10);
		if (temp < 0)
			return (-1);
		check += temp;
        temp = print_nbr(c % 10);
		if (temp < 0)
			return (-1);
		check += temp;
    }
    else if (c <= 9)
    {
        if (ft_putchar(c + 48) < 0)
            return (-1);
        check++;
    }
    return (check);
}

int print_unsigned(unsigned int c)
{
    int     check;
	int		temp;

	check = 0;
    temp = 0;
    if (c < 0)
    {
        if (ft_putchar('-') < 0)
            return (-1);
		check++;
        c = -c;
    }
    if (c >= 10)
    {
        temp = print_unsigned(c / 10);
		if (temp < 0)
			return (-1);
		check += temp;
        temp = print_unsigned(c % 10);
		if (temp < 0)
			return (-1);
		check += temp;
    }
    else if (c <= 9)
    {
        if (ft_putchar(c + 48) < 0)
            return (-1);
        check++;
    }
    return (check);
}

int print_hexa(unsigned int n, char *hex)
{
    long    num;
	int		check;
	int		temp;

    num = (long)n;
	check = 0;
	temp = 0;
    if (num >= 16)
    {
		temp = print_hexa(num / 16, hex);
		if (temp < 0)
			return (-1);
		check += temp;
        temp = print_hexa(num % 16, hex);
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

int print_lhexa(unsigned long int num, char *hex)
{
	int		check;
	int		temp;

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

int print_pointer(void *pointer)
{
    unsigned long   p;
	int				check;
	int				temp;

	if (pointer == 0)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	temp = 0;
    p = (unsigned long)pointer;
	check = write(1, "0x", 2);
    if (check < 0)
		return(-1);
	temp = print_lhexa(p, "0123456789abcdef");
    if (temp < 0)
		return(-1);
	check += temp;
    return (check);
}