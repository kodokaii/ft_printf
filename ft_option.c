/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 20:21:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

t_bool	ft_printf_check_flags(t_printf_format *format, t_printf_flags flags)
{
	return ((format->flags & flags) == flags);
}

t_bool	ft_printf_check_noflags(t_printf_format *format, t_printf_flags flags)
{
	return (((format->flags ^ flags) & flags) == flags);
}

t_uint	ft_printf_width_space(t_printf_format *format)
{
	t_uint	len;
	t_uint	var_len;

	len = 0;
	var_len = ft_max_uint(format->precision, format->var_len);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
	{
		while (var_len + len++ < format->width)
			ft_putchar_fd(' ', 1);
	}
	return (len);
}

t_uint	ft_printf_width_zero(t_printf_format *format)
{
	t_uint	len;

	len = 0;
	if (FLAGS(format, FT_PRINTF_ZERO)
		&& NFLAGS(format, FT_PRINTF_POINT) && NFLAGS(format, FT_PRINTF_MINUS))
	{
		while (format->var_len + len++ < format->width)
			ft_putchar_fd('0', 1);
	}
	return (len);
}

t_uint	ft_printf_precision(t_printf_format *format)
{
	t_uint	len;

	len = 0;
	if (FLAGS(format, FT_PRINTF_POINT))
	{
		while (format->var_len + len++ < format->precision)
			ft_putchar_fd('0', 1);
	}
	return (len);
}
