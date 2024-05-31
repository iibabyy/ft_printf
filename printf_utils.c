#include "printf.h"
#include <unistd.h>

int ft_putchar(char c)
{
    if (write(1, &c, 1) < 0)
    {
        return (-1);
    }
    return (1);
}

int ft_error(char *error_mssg)
{
    int i;

    i = 0;
    while (error_mssg[i])
    {
        if (write(1, &error_mssg[i], 1) < 0)
            return (-1);
    }
    return (-1);
}