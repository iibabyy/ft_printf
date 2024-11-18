/* ************************************************************************** */

/*                                                                            */

/*                                                        :::      ::::::::   */

/*   ft_printf.h                                        :+:      :+:    :+:   */

/*                                                    +:+ +:+         +:+     */

/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */

/*                                                +#+#+#+#+#+   +#+           */

/*   Created: 2024/11/15 23:15:55 by ibaby             #+#    #+#             */

/*   Updated: 2024/11/18 15:33:57 by ibaby            ###   ########.fr       */

/*                                                                            */

/* ************************************************************************** */


#ifndef ft_printf_H
# define ft_printf_H

#include "libft/libft.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/*		DEFINES		*/

#define INTMAX  2147483647
#define INTMIN -2147483648
#define OUT_OF_RANGE 2147483649

/*		ARGS 		*/

#define MINUS	00000001		//(unsigned char)
#define ZERO	00000010		//(unsigned char)
#define DOT		00000100		//(unsigned char)
#define HASH	00001000		//(unsigned char)
#define SPACE	00010000		//(unsigned char)
#define PLUS	00100000		//(unsigned char)
#define WIDTH	01000000		//(unsigned char)

/*		TYPES		*/

#define CHAR 'c'
#define STR 's'
#define PTR 'p'
#define INT 'i'
#define DECIMAL 'd'
#define UNS_INT 'u'
#define HEXA 'x'
#define HEXA_MAJ 'X'

#define HEXA_BASE "0123456789abcdef"
#define HEXA_MAJ_BASE "0123456789ABCDEF"

/*		STRUCT		*/

typedef struct s_arg {
	char	*content;
	char	*sign;
	long	precision;
	long	min_width;
	char	type;
	int		flags;
}	t_arg;

typedef struct s_data {
	va_list	ap;
	t_arg	arg;
	char	str[1024];
	int		size;
	long	totalSize;
	bool	error;
}	t_data;

/*		PRINTF		*/

int		ft_printf(const char *format, ...);

/*		UTILS		*/

bool	flag(int flag, t_data *data);
bool	type(char type, t_data *data);
void	joinChar(t_data *data, char c);
void	joinStr(t_data *data, char *str);
long	parseAtoi(const char *str);
void	strjoin_char(char *str, long size, char c);
void	flushBuffer(t_data *data);
bool	need(int need, t_data *data);
bool	isNumberType(t_data *data);
bool	isHexaType(t_data *data);

/*		PARSING		*/

int		checkArgs(const char *ptr);
bool	isValidType(char c);
bool	isValidFlag(char c);

void	addFlag(t_data *data, int flag);
void	getFlag(const char *format, int *index, t_data *data);
char	*nextArg(t_data *data);

/*		CONVERT		*/

char 	*convert_str(char *str);
void	convert_lhexa(unsigned long int num, char *hex, char *temp, int *index);
void	convert_pointer(void *pointer, char *tmp);
void	convert_char(char c, char *tmp);
void	convert_nbr(int c, char *tmp, int *index);
void	convert_unsigned(unsigned int c, char *tmp, int *index);
void	convert_hexa(unsigned int num, char *hex, char *temp, int *index);

#endif