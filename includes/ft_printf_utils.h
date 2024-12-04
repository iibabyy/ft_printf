/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 02:17:13 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:28:01 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include "libft.h"

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*		DEFINES		*/

# define INTMAX  2147483647
# define INTMIN -2147483648
# define OUT_OF_RANGE 2147483649

/*		ARGS 		*/

# define MINUS	00000001		//(unsigned char)
# define ZERO	00000010		//(unsigned char)
# define DOT		00000100		//(unsigned char)
# define HASH	00001000		//(unsigned char)
# define SPACE	00010000		//(unsigned char)
# define PLUS	00100000		//(unsigned char)
# define WIDTH	01000000		//(unsigned char)

/*		TYPES		*/

# define CHAR 'c'
# define STR 's'
# define PTR 'p'
# define INT 'i'
# define DECIMAL 'd'
# define UNS_INT 'u'
# define HEXA 'x'
# define HEXA_MAJ 'X'

# define HEXA_BASE "0123456789abcdef"
# define HEXA_MAJ_BASE "0123456789ABCDEF"

/*		STRUCT		*/

typedef struct s_arg
{
	size_t	size;
	char	*content;
	char	sign[3];
	long	precision;
	long	min_width;
	char	type;
	int		flags;
}	t_arg;

typedef struct s_data
{
	va_list	ap;
	t_arg	arg;
	char	str[1024];
	char	*sprintf_buffer;
	int		fd;
	int		size;
	long	total_size;
	bool	error;
	bool	sprintf;
}	t_data;

/*		ARG HANDLE		*/

int		process_flags(t_data *data);
char	*handle_arg(const char *format, int *index, t_data *data);

int		process_padding(t_data *data);
int		process_plus(t_data *data);
int		process_space(t_data *data);
int		process_hash(t_data *data);
int		process_dot(t_data *data);
int		process_minus(t_data *data);
int		process_zero(t_data *data);

/*		FT_PRINTF	*/

void	printf_arg(const char *format, int *index, t_data *data);
void	init_printf(t_data *data);
int		end_printf(t_data *data);

/*		UTILS		*/

int		join_at_begin(char *str, t_data *data);
int		join_at_end(char *str, t_data *data);
bool	flag(int flag, t_data *data);
bool	type(char type, t_data *data);
int		add_sign(t_data *data);
void	join_char(t_data *data, char c);
void	join_str(t_data *data, char *str);
long	parseAtoi(const char *str);
void	flush_buffer(t_data *data);
bool	need(int need, t_data *data);
void	join_arg(t_data *data);
long	parse_atoi(const char *str);

/*		PARSING		*/

int		check_args(const char *ptr);
bool	is_valid_type(char c);
bool	is_valid_flag(char c);

void	add_flag(t_data *data, int flag);
void	get_flag(const char *format, int *index, t_data *data);
char	*next_arg(t_data *data);

/*		CONVERT		*/

char	*convert_str(char *str);
void	convert_lhexa(unsigned long int num, char *hex, char *temp, int *index);
void	convert_pointer(void *pointer, char *tmp);
char	*convert_char(char c);
void	convert_nbr(int c, char *tmp, int *index);
void	convert_unsigned(unsigned int c, char *tmp, int *index);
void	convert_hexa(unsigned int num, char *hex, char *temp, int *index);

#endif
