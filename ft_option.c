/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 01:07:25 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

t_uint	ft_printf_space(t_printf_format *format)
{
	if (format->prefix_len || NFLAGS(format, FT_PRINTF_SPACE))
		return (0);
	ft_putchar_fd(' ', 1);
	return (1);
}

t_uint	ft_printf_left_width_space(t_printf_format *format)
{
	t_uint	len;
	t_uint	var_len;

	len = 0;
	var_len = ft_max_uint(format->precision, format->var_len)
		+ format->prefix_len;
	if (NFLAGS(format, FT_PRINTF_MINUS))
	{
		while (var_len + len < format->width)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
	}
	return (len);
}

t_uint	ft_printf_right_width_space(t_printf_format *format)
{
	t_uint	len;
	t_uint	var_len;

	len = 0;
	var_len = ft_max_uint(format->precision, format->var_len)
		+ format->prefix_len;
	if (FLAGS(format, FT_PRINTF_MINUS))
	{
		while (var_len + len < format->width)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
	}
	return (len);
}

t_uint	ft_printf_width_zero(t_printf_format *format)
{
	t_uint	len;
	t_uint	var_len;

	len = 0;
	var_len = format->var_len + format->prefix_len;
	if (FLAGS(format, FT_PRINTF_ZERO)
		&& NFLAGS(format, FT_PRINTF_POINT) && NFLAGS(format, FT_PRINTF_MINUS))
	{
		while (var_len + len < format->width)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
	}
	return (len);
}

t_uint	ft_printf_precision(t_printf_format *format)
{
	t_uint	len;

	len = 0;
	if (FLAGS(format, FT_PRINTF_POINT))
	{
		while (format->var_len + len < format->precision)
		{
			ft_putchar_fd('0', 1);
			len++;
		}
	}
	return (len);
}
