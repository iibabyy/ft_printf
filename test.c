// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <stdarg.h>
// #include "libft.h"


// #include "printf.h"

// int     ft_printf(const char *str, ...);
// int     num_flags(const char *str);
// int print_char(char c);
// int print_str(char *str);
// int print_nbr(int n);
// int print_hexa(int n, char *hex);
// int print_lhexa(long num, char *hex);
// int print_pointer(void *pointer);
// int ft_putchar(char c)
// {
//     if (write(1, &c, 1) < 0)
//     {
//         return (-1);
//     }
//     return (1);
// }
// int error(char *error_mssg)
// {
//     int i;

//     i = 0;
//     while (error_mssg[i])
//     {
//         if (write(1, &error_mssg[i], 1) < 0)
//             return (-1);
//     }
//     return (-1);
// }


// int     main()
// {
//     char *test = "bonjour";
//     long _test = (long)test;
//     ft_printf("ft_printf: %p", test);
//     printf("\nprintf:    %p", test);
// }

// int print_pointer(void *pointer)
// {
//     unsigned long   p; 

//     p = (unsigned long)pointer;
//     if (write(1, "0x", 2) < 2)
//         return(error("error: failed writing a pointer"));
//     if (print_lhexa((long)p, "0123456789abcdef") < 0)
//         return(-1); 
//     return (0);
// }

#include "printf.h"
#include <stdio.h>

int     ft_printf(const char *str, ...);

int     main()
{
    char	*str = " NULL %s NULL ";
	int		check;
	char	*arg1 = 0;
	int		*arg2 = 0;
    // ft_printf("ft_printf:\nchar: %c / string: %s / int: %i / dec: %d / unsign int: %u\nhexa: %x / HEXA: %X / pointer: %p / percent sign: %%", _char, _string, _int, _int, u_int, _hexa, _hexa, _pointer);
    // printf("\n\nprintf:\nchar: %c / string: %s / int: %i / dec: %d / unsign int: %u\nhexa: %x / HEXA: %X / pointer: %p / percent sign: %%", _char, _string, _int, _int, u_int, _hexa, _hexa, _pointer);
    check = ft_printf(str, arg1);
	printf("\nft_printf return value: %i\n", -1);
	check = printf(str, arg1);
	printf("\nprintf return value:    %i\n", -1);
	return 0;
}

// int     convert_flag(const char flag, va_list ap)
// {
//     if (flag == 'c')
//     {
//         return(print_char(va_arg(ap, int)));
//     }
//     else if (flag == 's')
//     {
//         return(print_str(va_arg(ap, char *)));
//     }
//     else if (flag == 'p')
//     {
//         return(print_pointer(va_arg(ap, void *)));
//     }
//     else if (flag == 'd')
//     {
//         return((print_nbr(va_arg(ap, int))));
//     }
//     else if (flag == 'i')
//     {
//         return((print_nbr(va_arg(ap, int))));
//     }
//     else if (flag == 'u')
//     {
//         return((print_nbr(va_arg(ap, unsigned int))));
//     }
//     else if (flag == 'x')
//     {
//         return((print_hexa(va_arg(ap, int), "0123456789abcdef")));
//     }
//     else if (flag == 'X')
//     {
//         return((print_hexa(va_arg(ap, int), "0123456789ABCDEF")));
//     }
//     else if (flag == '%')
//     {
//         return((write(1, "%", 1)));
//     }
//     else
//     {
//         return (-1);
//     }
// }

// int print_char(char c)
// {
//     int check;

//     check = write(1, &c, 1);
//     if (check < 0)
//         return(error("error: print_char failed\n"));
//     return (check);
// }

// int print_str(char *str)
// {
//     int check;
//     int i;

//     i = 0;
//     check = 0;
//     while (str[i])
//     {
//         if (write(1, &str[i], 1) < 0)
//             return(error("error: print_str failed\n"));
//         check++;
//         i++;
//     }
//     return (check);
// }

// int print_nbr(int n)
// {
//     long    c;
//     int     check;

//     c = (long)n;
//     check = 0;
//     if (c < 0)
//     {
//         if (ft_putchar('-') < 0)
//             return (error("error: print_nbr failed\n"));
//         check++;
//         c = -c;
//     }
//     if (c >= 10)
//     {
//         check += print_nbr(c / 10);
//         check += print_nbr(c % 10);
//     }
//     else if (c <= 9)
//     {
//         if (ft_putchar(c + 48) < 0)
//             return (error("error: print_nbr failed\n"));
//         check++;
//     }
//     return (check);
// }

// int print_hexa(int n, char *hex)
// {
//     long    num;

//     num = (long)n;
//     if (num < 0)
//     {
//         if (ft_putchar('-') < 0)
//             return (-1);
//         num = -num;
//     }
//     if (num >= 16)
//     {
//         if (print_hexa((num / 16), hex) < 0 || print_hexa((num % 16), hex) < 0)
//             return (-1);
//     }
//     else if (num < 16)
//     {
//         if (ft_putchar(hex[num]) < 0)
//             return (-1);
//     }
//     return (0);
// }

// int print_lhexa(long num, char *hex)
// {
//     if (num < 0)
//     {
//         if (ft_putchar('-') < 0)
//             return (-1);
//         num = -num;
//     }
//     if (num >= 16)
//     {
//         if (print_lhexa((num / 16), hex) < 0 || print_lhexa((num % 16), hex) < 0)
//             return (-1);
//     }
//     else if (num < 16)
//     {
//         if (ft_putchar(hex[num]) < 0)
//             return (-1);
//     }
//     return (0);
// }

// int     ft_printf(const char *str, ...)
// {
//     va_list ap;
//     int     i;

//     va_start(ap, str);
//     while (str[i] != '\0')
//     {
//         while ((str[i] != '%') && (str[i] != '\0'))
//         {
//             write(1, &str[i], 1);
//             i++;
//         }
//         if (str[i] == '\0')
//         {
//             return (i);
//         }
//         if (convert_flag(str[++i], ap) < 0)
//         {
//             return (-1);   
//         }
//         i++;
//     }
//     va_end(ap);
//     return (i);
// }