/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 02:44:54 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define FT_PRINTF_SPECIFIER	"cspdiuxX%"
# define FT_PRINTF_FLAGS		"-+ #0"

typedef enum e_printf_specifier
{
	FT_PRINTF_SPECIFIER_NONE	= 0,
	FT_PRINTF_CHAR				= 1,
	FT_PRINTF_STRING			= 2,
	FT_PRINTF_POINTER			= 3,
	FT_PRINTF_INT				= 4,
	FT_PRINTF_UNSIGNED			= 5,
	FT_PRINTF_HEXA_LOW			= 6,
	FT_PRINTF_HEXA_UP			= 7,
	FT_PRINTF_PERCENTAGE		= 8
}	t_printf_specifier;

typedef enum e_printf_flags
{
	FT_PRINTF_FLAG_NONE			= 0,
	FT_PRINTF_PLUS				= 1,
	FT_PRINTF_MINUS				= 2,
	FT_PRINTF_SPACE				= 4,
	FT_PRINTF_HASH				= 8,
	FT_PRINTF_ZERO				= 16,
	FT_PRINTF_POINT				= 32
}	t_printf_flags;

typedef union u_printf_var
{
	char			c;
	char			*s;
	void			*p;
	int				i;
	unsigned int	u;
	unsigned int	x;
}	t_printf_var;

typedef struct s_printf_format
{
	t_printf_var		var;
	t_printf_flags		flags;
	t_printf_specifier	specifier;
	t_uint				var_len;
	t_uint				prefix_len;
	t_uint				width;
	t_uint				precision;
}	t_printf_format;

int		ft_printf(const char *str, ...);
int		ft_printf_parsing(const char *str, va_list *arg);
int		ft_printf_format(t_printf_format *format);

t_bool	ft_printf_check_flags(t_printf_format *format, t_printf_flags flags);
t_bool	ft_printf_check_noflags(t_printf_format *format, t_printf_flags flags);

t_uint	ft_printf_space(t_printf_format *format);
t_uint	ft_printf_left_width_space(t_printf_format *format);
t_uint	ft_printf_right_width_space(t_printf_format *format);
t_uint	ft_printf_width_zero(t_printf_format *format);
t_uint	ft_printf_precision(t_printf_format *format);

t_uint	ft_printf_char(t_printf_format *format);
t_uint	ft_printf_str(t_printf_format *format);
t_uint	ft_printf_ptr(t_printf_format *format);
t_uint	ft_printf_int(t_printf_format *format);
t_uint	ft_printf_uint(t_printf_format *format);
t_uint	ft_printf_hexa_low(t_printf_format *format);
t_uint	ft_printf_hexa_up(t_printf_format *format);
t_uint	ft_printf_percentage(t_printf_format *format);

#endif
