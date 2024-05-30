#include <unistd.h>
#include "printf.h"

int print_char(char c)
{
    int check;

    check = write(1, &c, 1);
    if (check < 0)
        return(ft_error("error: print_char failed\n"));
    return (check);
}

int print_str(char *str)
{
    int check;
    int i;

    i = 0;
    check = 0;
    while (str[i])
    {
        if (write(1, &str[i], 1) < 0)
            return(ft_error("error: print_str failed\n"));
        check++;
        i++;
    }
    return (check);
}

int print_nbr(int n)
{
    long    c;
    int     check;

	check = 0;
    c = (long)n;
    check = 0;
    if (c < 0)
    {
        if (ft_putchar('-') < 0)
            return (ft_error("error: print_nbr failed\n"));
        check++;
        c = -c;
    }
    if (c >= 10)
    {
        check += print_nbr(c / 10);
        check += print_nbr(c % 10);
    }
    else if (c <= 9)
    {
        if (ft_putchar(c + 48) < 0)
            return (ft_error("error: print_nbr failed\n"));
        check++;
    }
    return (check);
}

int print_hexa(int n, char *hex)
{
    long    num;

    num = (long)n;
    if (num < 0)
    {
        if (ft_putchar('-') < 0)
            return (-1);
        num = -num;
    }
    if (num >= 16)
    {
        if (print_hexa((num / 16), hex) < 0 || print_hexa((num % 16), hex) < 0)
            return (-1);
    }
    else if (num < 16)
    {
        if (ft_putchar(hex[num]) < 0)
            return (-1);
    }
    return (0);
}

int print_lhexa(long num, char *hex)
{
    if (num < 0)
    {
        if (ft_putchar('-') < 0)
            return (-1);
        num = -num;
    }
    if (num >= 16)
    {
        if (print_lhexa((num / 16), hex) < 0 || print_lhexa((num % 16), hex) < 0)
            return (-1);
    }
    else if (num < 16)
    {
        if (ft_putchar(hex[num]) < 0)
            return (-1);
    }
    return (0);
}

int print_pointer(void *pointer)
{
    unsigned long   p; 

    p = (unsigned long)pointer;
    if (write(1, "0x", 2) < 2)
        return(ft_error("error: failed writing a pointer"));
    if (print_lhexa((long)p, "0123456789abcdef") < 0)
        return(-1); 
    return (0);
}