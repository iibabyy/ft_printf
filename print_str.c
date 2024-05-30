#include <stdlib.h>

char    *float_to_str(float n)              //      y = x,1234  ->  x = y - (y % 1)
{
    char    *str;
    int     numlen;

    i = 0;
    numlen = 0;
    while ((n % 1) != 0)        //  plus de chiffres apres la virgule
    {
        n *=10;
    }
    while (n >= 10)
    {
        n /= 10;
        numlen++;
    }
    if (n % 10 != 0)
    {
        numlen++;
    }
    str = malloc(sizeof(char) * (numlen + 1));
    str[numlen] = '\0';
    return (str);
}