/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:15:55 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:18:20 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_utils.h"

int		ft_printf(const char *format, ...);
char	*ft_sprintf(const char *format, ...);
int		ft_fprintf(int fd, const char *format, ...);

#endif
