/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:35:51 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/16 01:28:11 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

void	ft_multi_free(int pointers_num, void *pointer1, void *pointer2, ...)
{
	va_list			ap;
	unsigned char	*pointer;

	va_start(ap, pointer2);
	free(pointer1);
	free(pointer2);
	pointers_num -= 2;
	while (pointers_num-- > 0)
	{
		pointer = va_arg(ap, unsigned char *);
		free(pointer);
	}
}
