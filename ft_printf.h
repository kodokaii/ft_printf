/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/19 17:25:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPECIFIER "cspdiuxX%"

enum	e_specifier
{
	CHAR,
	STRING,
	POINTER,
	INT,
	UNSIGNED,
	HEXA_LOW,
	HEXA_UP,
	PERCENTAGE
};

enum	e_flags
{
	PLUS	= 1,
	SPACE	= 2,
	HASH	= 4,
	ZERO	= 8,
	WIDTH	= 16
};

typedef struct s_format
{
	void		*ptr;
	int			width;
	e_flags		flags;
	e_specifier	specifier;
}	t_format;

int	ft_printf(const char *str, ...);
int	ft_printf_parsing(char *str, t_format *format);

#endif
