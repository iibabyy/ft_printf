#include "../includes/ft_printf.h"
#include <stdio.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat"
#pragma clang diagnostic ignored "-Wint-conversion"
#pragma clang diagnostic ignored "-Wunused-function"
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"

char 	*ok = "\033[42m\033[37m[OK]\033[0m";
char 	*ko = "\033[45m\033[37m[KO]\033[0m";

char 	*ok2 = "\033[44m\033[37m[OK]\033[0m";
char 	*ko2 = "\033[41m\033[37m[KO]\033[0m";

static void test_percent(void)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POURCENT ===\n");
	r_a = ft_printf("|%%|%%%%|%%%%%%|%%-%%|\n");
	r_b = printf("|%%|%%%%|%%%%%%|%%-%%|\n");
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%%|%-%|%5%|%-5%|%05%|%-05%|%50%|% %|%5.0%|%0%|%#0%|\n");
	r_b = printf("|%%|%-%|%5%|%-5%|%05%|%-05%|%50%|% %|%5.0%|%0%|%#0%|\n");
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_character(char a, char b, char c, char d, char e)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS CARACTERES (undefined behavior : '0 #+.') ===\n");
	r_a = ft_printf("|%c|%c|%c|%c|%c|\n", a, b, c, d, e);
	r_b = printf("|%c|%c|%c|%c|%c|\n", a, b, c, d, e);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%-c|\n", a, b, c, a);
	r_b = printf("|%c|%5c|%-5c|%-c|\n", a, b, c, a);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c||\n", 0, 0, 0, 0, 0);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c||\n", 0, 0, 0, 0, 0);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 8, 8, 8, 8, 8, 8);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 8, 8, 8, 8, 8, 8);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 9, 9, 9, 9, 9, 9);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 9, 9, 9, 9, 9, 9);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 10, 10, 10, 10, 10, 10);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 10, 10, 10, 10, 10, 10);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 11, 11, 11, 11, 11, 11);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 11, 11, 11, 11, 11, 11);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 12, 12, 12, 12, 12, 12);
	r_b = printf("|%c|%5c|%-5c|%12c|%-12c|%-c|\n", 12, 12, 12, 12, 12, 12);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf(">|---%c__|---%5c__|---%-5c__|---%12c__|---%-12c__|---%-c__|<\n", 13, 13, 13, 13, 13, 13);
	r_b = printf(">|---%c__|---%5c__|---%-5c__|---%12c__|---%-12c__|---%-c__|<\n", 13, 13, 13, 13, 13, 13);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%-c|\n", 127, 127, 127, 127);
	r_b = printf("|%c|%5c|%-5c|%-c|\n", 127, 127, 127, 127);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%-c|\n", 128, 128, 128, 128);
	r_b = printf("|%c|%5c|%-5c|%-c|\n", 128, 128, 128, 128);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%5c|%-5c|%-c|\n", -1, -1, -1, -1);
	r_b = printf("|%c|%5c|%-5c|%-c|\n", -1, -1, -1, -1);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%c|%c|--\n", d, e);
	r_b = printf("|%c|%c|--\n", d, e);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

}

static void test_strs(char *str1, char *str2)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS STRINGS (undefined behavior : '0 #+') ===\n");
	r_a = ft_printf("|%s|%s|%s|\n", str1, str2, "");
	r_b = printf("|%s|%s|%s|\n", str1, str2, "");
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%10s|%10s|%2s|%2s|\n", str1, str2, str1, str2);
	r_b = printf("|%10s|%10s|%2s|%2s|\n", str1, str2, str1, str2);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10s|%-10s|%-1s|%-1s|%-s|%-s|\n", str1, str2, str1, str2, str1, str2);
	r_b = printf("|%-10s|%-10s|%-1s|%-1s|%-s|%-s|\n", str1, str2, str1, str2, str1, str2);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5s|%.5s|%.6s|%.7s|%.0s|%.0s|%4.0s|%4.0s|%10.0s|%10.0s|\n", str1, str2, str2, str2, str1, str2, str1, str2, str1, str2);
	r_b = printf("|%.5s|%.5s|%.6s|%.7s|%.0s|%.0s|%4.0s|%4.0s|%10.0s|%10.0s|\n", str1, str2, str2, str2, str1, str2, str1, str2, str1, str2);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5s|%10.7s|%10.1s|%10.1s|%2.10s|%2.10s|%2.4s|%2.4s|\n", str1, str2, str1, str2, str1, str2, str1, str2);
	r_b = printf("|%10.5s|%10.7s|%10.1s|%10.1s|%2.10s|%2.10s|%2.4s|%2.4s|\n", str1, str2, str1, str2, str1, str2, str1, str2);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5s|%-10.5s|%-10.1s|%-10.1s|%-2.10s|%-2.10s|%-2.4s|%-2.4s|\n", str1, str2, str1, str2, str1, str2, str1, str2);
	r_b = printf("|%-10.5s|%-10.5s|%-10.1s|%-10.1s|%-2.10s|%-2.10s|%-2.4s|%-2.4s|\n", str1, str2, str1, str2, str1, str2, str1, str2);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_integer_d(int n1, int n2, int n3, int n4, int n5, int n6, int n7)
{
	int	r_a;
	int	r_b;


	puts("\n=== TEST FLAGS POUR LES NOMBRES (undefined behavior : '#') ===\n");

	r_a = ft_printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n", -1, -9, 10, 11, -14, -15, -16, -99, -100, -101);
	r_b = printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n", -1, -9, 10, 11, -14, -15, -16, -99, -100, -101);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%-2d|%-1d|%-3d|%-4d|%-5d|%-6d|%-1d|%-2d|%-3d|\n", -1, -9, 10, 11, -14, -15, -16, -99, -100, -101);
	r_b = printf("|%-2d|%-1d|%-3d|%-4d|%-5d|%-6d|%-1d|%-2d|%-3d|\n", -1, -9, 10, 11, -14, -15, -16, -99, -100, -101);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10d|%-11d|%-13d|%-14d|%-15d|\n", INT_MIN, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	r_b = printf("|%-10d|%-11d|%-13d|%-14d|%-15d|\n", INT_MIN, LONG_MAX, UINT_MAX, ULONG_MAX, 9223372036854775807LL);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-9d|%-10d|%-11d|%-12d|%-13d|%-14d|%-15d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, 42);
	r_b = printf("|%-9d|%-10d|%-11d|%-12d|%-13d|%-14d|%-15d|\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, 42);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%d|%d|%d|%d|%d|%d|%d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%d|%d|%d|%d|%d|%d|%d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%5d|%5d|%5d|%5d|%5d|%5d|%5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%5d|%5d|%5d|%5d|%5d|%5d|%5d|\n", n1, n2, n3, n4, n5, n6, n7);
	 printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10d|%10d|%10d|%10d|%10d|%10d|%10d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10d|%10d|%10d|%10d|%10d|%10d|%10d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010d|%010d|%010d|%010d|%010d|%010d|%010d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%010d|%010d|%010d|%010d|%010d|%010d|%010d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-d|%-d|%-d|%-d|%-d|%-d|%-d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-d|%-d|%-d|%-d|%-d|%-d|%-d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-5d|%-5d|%-5d|%-5d|%-5d|%-5d|%-5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-5d|%-5d|%-5d|%-5d|%-5d|%-5d|%-5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10d|%-10d|%-10d|%-10d|%-10d|%-10d|%-10d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10d|%-10d|%-10d|%-10d|%-10d|%-10d|%-10d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5d|%.5d|%.5d|%.5d|%.5d|%.5d|%.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.5d|%.5d|%.5d|%.5d|%.5d|%.5d|%.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.0d|%.0d|%.0d|%.0d|%.0d|%.0d|%.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.0d|%.0d|%.0d|%.0d|%.0d|%.0d|%.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	  printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|%0.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	  printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|%10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|%+10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|%+10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|%10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|% 10.0d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|%-10.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|%+0.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% d|% d|% d|% d|% d|% d|% d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% d|% d|% d|% d|% d|% d|% d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% -d|% -d|% -d|% -d|% -d|% -d|% -d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% -d|% -d|% -d|% -d|% -d|% -d|% -d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+-d|%+-d|%+-d|%+-d|%+-d|%+-d|%+-d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+-d|%+-d|%+-d|%+-d|%+-d|%+-d|%+-d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+d|%+d|%+d|%+d|%+d|%+d|%+d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+d|%+d|%+d|%+d|%+d|%+d|%+d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|%+.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|%+-.5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% .5d|% .5d|% .5d|% .5d|% .5d|% .5d|% .5d|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% .5d|% .5d|% .5d|% .5d|% .5d|% .5d|% .5d|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_integer_i(int n1, int n2, int n3, int n4, int n5, int n6, int n7)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POUR LES NOMBRES (%i) ===\n");
	r_a = ft_printf("|%i|%i|%i|%i|%i|%i|%i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%i|%i|%i|%i|%i|%i|%i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%5i|%5i|%5i|%5i|%5i|%5i|%5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%5i|%5i|%5i|%5i|%5i|%5i|%5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10i|%10i|%10i|%10i|%10i|%10i|%10i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10i|%10i|%10i|%10i|%10i|%10i|%10i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010i|%010i|%010i|%010i|%010i|%010i|%010i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%010i|%010i|%010i|%010i|%010i|%010i|%010i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-5i|%-5i|%-5i|%-5i|%-5i|%-5i|%-5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-5i|%-5i|%-5i|%-5i|%-5i|%-5i|%-5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-i|%-i|%-i|%-i|%-i|%-i|%-i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-i|%-i|%-i|%-i|%-i|%-i|%-i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10i|%-10i|%-10i|%-10i|%-10i|%-10i|%-10i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10i|%-10i|%-10i|%-10i|%-10i|%-10i|%-10i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5i|%.5i|%.5i|%.5i|%.5i|%.5i|%.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.5i|%.5i|%.5i|%.5i|%.5i|%.5i|%.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.0i|%.0i|%.0i|%.0i|%.0i|%.0i|%.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.0i|%.0i|%.0i|%.0i|%.0i|%.0i|%.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|%0.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|%10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|%+10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|%+10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|%10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|% 10.0i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|%-10.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|%+0.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% i|% i|% i|% i|% i|% i|% i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% i|% i|% i|% i|% i|% i|% i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% -i|% -i|% -i|% -i|% -i|% -i|% -i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% -i|% -i|% -i|% -i|% -i|% -i|% -i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+-i|%+-i|%+-i|%+-i|%+-i|%+-i|%+-i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+-i|%+-i|%+-i|%+-i|%+-i|%+-i|%+-i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+i|%+i|%+i|%+i|%+i|%+i|%+i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+i|%+i|%+i|%+i|%+i|%+i|%+i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|%+.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|%+-.5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|% .5i|% .5i|% .5i|% .5i|% .5i|% .5i|% .5i|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|% .5i|% .5i|% .5i|% .5i|% .5i|% .5i|% .5i|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_integer_u(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4, unsigned int n5, unsigned int n6, unsigned int n7)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POUR LES NOMBRES (%u) ===\n");
	r_a = ft_printf("|%u|%u|%u|%u|%u|%u|%u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%u|%u|%u|%u|%u|%u|%u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%5u|%5u|%5u|%5u|%5u|%5u|%5u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%5u|%5u|%5u|%5u|%5u|%5u|%5u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10u|%10u|%10u|%10u|%10u|%10u|%10u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10u|%10u|%10u|%10u|%10u|%10u|%10u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010u|%010u|%010u|%010u|%010u|%010u|%010u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%010u|%010u|%010u|%010u|%010u|%010u|%010u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-5u|%-5u|%-5u|%-5u|%-5u|%-5u|%-5u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-5u|%-5u|%-5u|%-5u|%-5u|%-5u|%-5u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10u|%-10u|%-10u|%-10u|%-10u|%-10u|%-10u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10u|%-10u|%-10u|%-10u|%-10u|%-10u|%-10u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5u|%.5u|%.5u|%.5u|%.5u|%.5u|%.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.5u|%.5u|%.5u|%.5u|%.5u|%.5u|%.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.0u|%.0u|%.0u|%.0u|%.0u|%.0u|%.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%.0u|%.0u|%.0u|%.0u|%.0u|%.0u|%.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|%0.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|%10.5u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|%10.0u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|\n", n1, n2, n3, n4, n5, n6, n7);
	r_b = printf("|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|%-10.5u|\n", n1, n2, n3, n4, n5, n6, n7);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_integer_x(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POUR LES NOMBRES HEXADECIMAUX (%x)  (undefined behavior : ' +') ===\n");
	r_a = ft_printf("|%x|%x|%x|%x|\n", n1, n2, n3, n4);
	r_b = printf("|%x|%x|%x|%x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%0x|%0x|%0x|%0x|\n", n1, n2, n3, n4);
	r_b = printf("|%0x|%0x|%0x|%0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10x|%-10x|%-10x|%-10x|\n", n1, n2, n3, n4);
	r_b = printf("|%-10x|%-10x|%-10x|%-10x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010x|%010x|%010x|%010x|\n", n1, n2, n3, n4);
	r_b = printf("|%010x|%010x|%010x|%010x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5x|%.5x|%.5x|%.5x|\n", n1, n2, n3, n4);
	r_b = printf("|%.5x|%.5x|%.5x|%.5x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.0x|%.0x|%.0x|%.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%.0x|%.0x|%.0x|%.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.0x|%0.0x|%0.0x|%0.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%0.0x|%0.0x|%0.0x|%0.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.10x|%0.10x|%0.10x|%0.10x|\n", n1, n2, n3, n4);
	r_b = printf("|%0.10x|%0.10x|%0.10x|%0.10x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5x|%10.5x|%10.5x|%10.5x|\n", n1, n2, n3, n4);
	r_b = printf("|%10.5x|%10.5x|%10.5x|%10.5x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.0x|%10.0x|%10.0x|%10.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%10.0x|%10.0x|%10.0x|%10.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010.0x|%010.0x|%010.0x|%010.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%010.0x|%010.0x|%010.0x|%010.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-x|%-x|%-x|%-x|\n", n1, n2, n3, n4);
	r_b = printf("|%-x|%-x|%-x|%-x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5x|%-10.5x|%-10.5x|%-10.5x|\n", n1, n2, n3, n4);
	r_b = printf("|%-10.5x|%-10.5x|%-10.5x|%-10.5x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.0x|%-10.0x|%-10.0x|%-10.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%-10.0x|%-10.0x|%-10.0x|%-10.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#x|%#x|%#x|%#x|\n", n1, n2, n3, n4);
	r_b = printf("|%#x|%#x|%#x|%#x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#10.5x|%#10.5x|%#10.5x|%#10.5x|\n", n1, n2, n3, n4);
	r_b = printf("|%#10.5x|%#10.5x|%#10.5x|%#10.5x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#10.0x|%#10.0x|%#10.0x|%#10.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%#10.0x|%#10.0x|%#10.0x|%#10.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#010.0x|%#010.0x|%#010.0x|%#010.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%#010.0x|%#010.0x|%#010.0x|%#010.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#010.5x|%#010.5x|%#010.5x|%#010.5x|\n", n1, n2, n3, n4);
	r_b = printf("|%#010.5x|%#010.5x|%#010.5x|%#010.5x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#0.10x|%#0.10x|%#0.10x|%#0.10x|\n", n1, n2, n3, n4);
	r_b = printf("|%#0.10x|%#0.10x|%#0.10x|%#0.10x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#0.0x|%#0.0x|%#0.0x|%#0.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%#0.0x|%#0.0x|%#0.0x|%#0.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#-10.0x|%#-10.0x|%#-10.0x|%#-10.0x|\n", n1, n2, n3, n4);
	r_b = printf("|%#-10.0x|%#-10.0x|%#-10.0x|%#-10.0x|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_integer_xup(unsigned int n1, unsigned int n2, unsigned int n3, unsigned int n4)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POUR LES NOMBRES HEXADECIMAUX (%X) (undefined behavior : ' +') ===\n");
	r_a = ft_printf("|%X|%X|%X|%X|\n", n1, n2, n3, n4);
	r_b = printf("|%X|%X|%X|%X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%0X|%0X|%0X|%0X|\n", n1, n2, n3, n4);
	r_b = printf("|%0X|%0X|%0X|%0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10X|%-10X|%-10X|%-10X|\n", n1, n2, n3, n4);
	r_b = printf("|%-10X|%-10X|%-10X|%-10X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010X|%010X|%010X|%010X|\n", n1, n2, n3, n4);
	r_b = printf("|%010X|%010X|%010X|%010X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.5X|%.5X|%.5X|%.5X|\n", n1, n2, n3, n4);
	r_b = printf("|%.5X|%.5X|%.5X|%.5X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%.0X|%.0X|%.0X|%.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%.0X|%.0X|%.0X|%.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.0X|%0.0X|%0.0X|%0.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%0.0X|%0.0X|%0.0X|%0.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%0.10X|%0.10X|%0.10X|%0.10X|\n", n1, n2, n3, n4);
	r_b = printf("|%0.10X|%0.10X|%0.10X|%0.10X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.5X|%10.5X|%10.5X|%10.5X|\n", n1, n2, n3, n4);
	r_b = printf("|%10.5X|%10.5X|%10.5X|%10.5X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%10.0X|%10.0X|%10.0X|%10.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%10.0X|%10.0X|%10.0X|%10.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%010.0X|%010.0X|%010.0X|%010.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%010.0X|%010.0X|%010.0X|%010.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-X|%-X|%-X|%-X|\n", n1, n2, n3, n4);
	r_b = printf("|%-X|%-X|%-X|%-X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.5X|%-10.5X|%-10.5X|%-10.5X|\n", n1, n2, n3, n4);
	r_b = printf("|%-10.5X|%-10.5X|%-10.5X|%-10.5X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-10.0X|%-10.0X|%-10.0X|%-10.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%-10.0X|%-10.0X|%-10.0X|%-10.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#X|%#X|%#X|%#X|\n", n1, n2, n3, n4);
	r_b = printf("|%#X|%#X|%#X|%#X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#10.5X|%#10.5X|%#10.5X|%#10.5X|\n", n1, n2, n3, n4);
	r_b = printf("|%#10.5X|%#10.5X|%#10.5X|%#10.5X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#10.0X|%#10.0X|%#10.0X|%#10.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%#10.0X|%#10.0X|%#10.0X|%#10.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#010.0X|%#010.0X|%#010.0X|%#010.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%#010.0X|%#010.0X|%#010.0X|%#010.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#010.5X|%#010.5X|%#010.5X|%#010.5X|\n", n1, n2, n3, n4);
	r_b = printf("|%#010.5X|%#010.5X|%#010.5X|%#010.5X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#0.10X|%#0.10X|%#0.10X|%#0.10X|\n", n1, n2, n3, n4);
	r_b = printf("|%#0.10X|%#0.10X|%#0.10X|%#0.10X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#0.0X|%#0.0X|%#0.0X|%#0.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%#0.0X|%#0.0X|%#0.0X|%#0.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%#-10.0X|%#-10.0X|%#-10.0X|%#-10.0X|\n", n1, n2, n3, n4);
	r_b = printf("|%#-10.0X|%#-10.0X|%#-10.0X|%#-10.0X|\n", n1, n2, n3, n4);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);
}

static void test_pointer_p(void *p1, void *p2, void *p3, void *p4, void *p5)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== TEST FLAGS POUR LES POINTEURS (%p) (undefined behavior : '#. 0+') ===\n");
	r_a = ft_printf("|%p|%p|\n", ULONG_MAX, -ULONG_MAX);
	r_b = printf("|%p|%p|\n", ULONG_MAX, -ULONG_MAX);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%p|%p|%p|%p|%p|\n", p1, p2, p3, p4, p5);
	r_b = printf("|%p|%p|%p|%p|%p|\n", p1, p2, p3, p4, p5);
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("|%-p|%-p|%-p|%-p|%-p|\n", p1, p2, p3, p4, p5);
	r_b = printf("|%-p|%-p|%-p|%-p|%-p|\n", p1, p2, p3, p4, p5);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%9p|%19p|%15p|%17p|%9p|%2p|\n", p1, p2, p3, p4, p5, p5);
	r_b = printf("|%9p|%19p|%15p|%17p|%9p|%2p|\n", p1, p2, p3, p4, p5, p5);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	r_a = ft_printf("|%-9p|%-20p|%-20p|%-20p|%-9p|\n", p1, p2, p3, p4, p5);
	r_b = printf("|%-9p|%-20p|%-20p|%-20p|%-9p|\n", p1, p2, p3, p4, p5);
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

}

static	void test_special(void)
{
	int	r_a;
	int	r_b;

	puts("\n\n\n=== CAS SPECIAUX ===\n");
	r_a = ft_printf(NULL);
	puts("");
	r_b = printf(NULL);
	puts("");
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf(0);
	puts("");
	r_b = printf(0);
	puts("");
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	r_a = ft_printf("Str simple...");
	puts("");
	r_b = printf("Str simple...");
	puts("");
	printf("%s %d, %d\n\n", r_a == r_b ? ok2 : ko2, r_a, r_b);

	puts("\n\n\n=== Comportement imprevisible ===\n");

	r_a = ft_printf("Str %.......", 3);
	puts("");
	r_b = printf("Str %......", 3);
	puts("");
	printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);


	// r_a = ft_printf(10);
	// puts("");
	// r_b = printf(10);
	// puts("");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// r_a = ft_printf(-10);
	// puts("");
	// r_b = printf(-10);
	// puts("");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// puts("\nDebut % 1");
	// r_a = ft_printf("%");
	// puts("\nFin % 1");
	// puts("\nDebut % 1");
	// r_b = printf("%");
	// puts("\nFin % 1");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// puts("\nDebut % 2");
	// r_a = ft_printf("Tout va bien mais....  >>>%");
	// puts("\nFin % 2");
	// puts("\nDebut % 2");
	// r_b = printf("Tout va bien mais....  >>>%");
	// puts("\nFin % 2");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// puts("\nDebut % 3");
	// r_a = ft_printf("Tout va bien mais....  >>>%  >>>");
	// puts("\nFin % 3");
	// puts("\nDebut % 3");	r_b = printf("Tout va bien mais....  >>>%  >>>");
	// puts("\nFin % 3");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// r_a = ft_printf("%d%", 5);
	// r_b = printf("%d%", 5);
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// r_a = ft_printf("%t");
	// r_b = printf("%t");
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

	// r_a = ft_printf("%t", 800);
	// r_b = printf("%t", 800);
	// printf("%s %d, %d\n\n", r_a == r_b ? ok : ko, r_a, r_b);

}

int main(void)
{
	test_percent();
	test_character('A', 'B', 'C', '\r', '\t');
	test_strs("-*o\\o*-", NULL);
	test_integer_d(0x7FFFFFFF, (int)0x80000000, 0, 1, -1, 10, -10);
	test_integer_i(0x7FFFFFFF, (int)0x80000000, 0, 1, -1, 10, -10);
	test_integer_u(0xFFFFFFFF, 100, 10, 1, 0, 9, 99);
	 test_integer_x(0xFFFFFFFF, 0, 1, 42);
	test_integer_xup(0x7FFFFFFF, 0xF, 32, (int)0777);
	 test_pointer_p((void *)0x0, (void *)test_pointer_p, (void *)0x1234ABC, (void *)0xFFFFFFFF, NULL);
	test_special();
	return (0);
}

#pragma clang diagnostic push
