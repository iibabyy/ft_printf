#include "includes/ft_printf.h"

int main()
{
	int real = printf("[%1s]\n", "");
	int fake = ft_printf("[%1s]\n", "");
	printf( "\nprintf =    %d\n", real);
	printf( "ft_printf = %d\n", fake);
}
