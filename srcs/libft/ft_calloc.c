/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:33:28 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/16 01:28:36 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t el_count, size_t el_size)
{
	unsigned char	*buffer;

	buffer = malloc(el_size * el_count);
	if (!buffer)
		return (NULL);
	buffer = ft_memset(buffer, 0, (el_count * el_size));
	return (buffer);
}
