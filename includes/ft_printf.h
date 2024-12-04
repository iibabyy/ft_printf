/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:15:55 by ibaby             #+#    #+#             */
/*   Updated: 2024/12/04 03:51:18 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf_utils.h"

/*		PRINTF		*/
int		ft_printf(const char *format, ...);

/*		SPRINTF		*/
char	*ft_sprintf(const char *format, ...);

/*		DPRINTF		*/
int		ft_dprintf(int fd, const char *format, ...);

#endif
