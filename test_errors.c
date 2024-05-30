/*#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int     ft_putchar(char c);
int     convert_flag(const char flag, va_list ap);
int     ft_printf(const char *str, ...);
int     num_flags(const char *str);
int     print_char(char c);
int     print_str(char *str);
int     print_nbr(int n);
int     print_hexa(int n, char *hex);
int     error(char *error_mssg);

int main(int ac, char **av)
{
    char *test = "printf: %s";
    char *ft_test = "ft_printf: %%";
    char flag = av[1][0];

    ft_test[12] = flag;
    *(test + 7) = flag;
    if (flag == 'i' || flag == 'u' || flag == 'd' || flag == 'x' || flag == 'X')
    {
        int param = atoi(av[2]);
        printf(test, param);
        write(1, "\n", 1);
        ft_printf(ft_test, param);
    }
    else
    {
        char *param = av[2];
        printf(test, param);
        write(1, "\n", 1);
        ft_printf(ft_test, param);
    }
    return (0);
}
*/
/*int ft_putchar(char c)
{
    if (write(1, &c, 1) < 0)
    {
        return (-1);
    }
    return (1);
}
int     convert_flag(const char flag, va_list ap)
{
    if (flag == 'c')
    {
        return(print_char(va_arg(ap, int)));            //                  thoughts
    }                                                           //transformer les types en strings (sauf pour un char ?)
    else if (flag == 's')                                          // -> putstr
    {                                                           //
        return(print_str(va_arg(ap, char *)));
    }
    else if (c == 'p')
    {
        //voir comment est exprimé un pointeur
        //et le transformer en hexadecimal ?
    }
    else if (flag == 'd') //same as int
    {
        return((print_nbr(va_arg(ap, int))));
    }
    else if (flag == 'i')
    {
        return((print_nbr(va_arg(ap, int))));
    }
    else if (flag == 'u')
    {
        return((print_nbr(va_arg(ap, unsigned int))));
    }
    else if (flag == 'x')
    {
        return((print_hexa(va_arg(ap, int), "0123456789abcdef")));
    }
    else if (flag == 'X')
    {
        return((print_hexa(va_arg(ap, int), "0123456789ABCDEF")));
    }
    else if (flag == '%')
    {
        return((write(1, "%", 1)));
    }
    else
    {
        return (-1);
    }
}
int     ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;

    va_start(ap, str);
    while (str[i] != '\0')
    {
        while ((str[i] != '%') && (str[i] != '\0'))
        {
            write(1, &str[i], 1);
            i++;
        }
        if (str[i] == '\0')
        {
            return (i);
        }
        if (convert_flag(str[++i], ap) < 0)
        {
            return (-1);   
        }
        i++;
    }
    va_end(ap);
    return (i);
}
int     num_flags(const char *str)
{
    char    *flags = "cspdiuxX%";
    int     i;
    int     count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == '%')
        {
            if (str[i + 1] est un flag)
            {
                count++;
                i++;
            }
            else
            {
                return(error("flags incorrects\n"));
            }
        }
        i++;
    }
    return (count);
}
int print_char(char c)
{
    int check;

    check = write(1, &c, 1);
    if (check < 0)
        return(error("error: print_char failed\n"));
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
            return(error("error: print_str failed\n"));
        check++;
        i++;
    }
    return (check);
}
int print_nbr(int n)
{
    long    c;
    int     check;

    c = (long)n;
    if (c < 0)
    {
        if (ft_putchar('-') < 0)
            return (error("error: print_nbr failed\n"));
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
            return (error("error: print_nbr failed\n"));
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
int error(char *error_mssg)
{
    int i;

    i = 0;
    while (error_mssg[i])
    {
        if (write(1, &error_mssg[i], 1) < 0)
            return (-1);
    }
    return (-1);
}*/