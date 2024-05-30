#ifndef FT_PRINTF_H_
#define FT_PRINTF_H_

#include <stdarg.h>
#include <unistd.h>

int     print_nbr(int n);
int     convert_flag(const char flag, va_list ap);
int     num_flags(const char *str);
int     ft_printf(const char *str, ...);
int     ft_putchar(char c);
int ft_error(char *error_mssg);
int print_str(char *str);
int print_char(char c);
int print_hexa(int n, char *base);
int print_pointer(void *pointer);
int print_lhexa(long num, char *hex);

#endif