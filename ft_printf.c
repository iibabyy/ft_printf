#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "printf.h"

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

int     ft_printf(const char *str, ...)
{
    va_list ap;
    int     i;

    va_start(ap, str);
    while (str[i] != '\0')
    {
        while ((str[i] != '%') && (str[i] != '\0'))
        {
            if (write(1, &str[i], 1) <= -1)
                return (-1);
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

/*
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
<<<<<<< HEAD
            if (str[i + 1] (est dans flags))
=======
            if (ft_strchr(flags, str[i + 1]))
>>>>>>> 2d75fe8 (functional, francinette errors remaining)
            {
                count++;
                i++;
            }
            else
            {
                return(ft_error("flags incorrects\n"));
            }
        }
        i++;
    }
    return (count);
}
*/

//cspdiuxX%
/*  thoughts
    -> savoir le type de l'arg avec c
    -> prendre l'arg avec va_arg
        .directement le bon arg ?
    -> transformer l'arg en string
        .fonctions pour chaque type ?
    -> afficher le string
*/
/*  conversions
        . %c Prints a single character.
        . %s Prints a string (as defined by the common C convention).
        . %p The void * pointer argument has to be printed in hexadecimal format.
        . %d Prints a decimal (base 10) number.
        . %i Prints an integer in base 10.
        . %u Prints an unsigned decimal (base 10) number.
        . %x Prints a number in hexadecimal (base 16) lowercase format.
        . %X Prints a number in hexadecimal (base 16) uppercase format.
        . %% Prints a percent sign
*/

int     convert_flag(const char flag, va_list ap)
{
    if (flag == 'c')
    {
        return(print_char(va_arg(ap, int)));
    }
    else if (flag == 's')
    {
        return(print_str(va_arg(ap, char *)));
    }
    else if (flag == 'p')
    {
        return(print_pointer(va_arg(ap, void *)));
    }
    else if (flag == 'd')
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
