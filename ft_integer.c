/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 03:36:27 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

t_uint	ft_printf_char(t_printf_format *format)
{
	t_byte	n;
	t_uint	total_len;

	total_len = 0;
	n = ft_abs_char(format->var.c);
	format->var_len = 1;
	total_len += ft_printf_left_width_space(format);
	ft_putchar_fd(n, 1);
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_int(t_printf_format *format)
{
	t_uint	n;
	t_uint	total_len;

	total_len = 0;
	n = ft_abs_int(format->var.i);
	format->var_len = ft_uintlen(n, 10);
	format->prefix_len = (format->var.i < 0)
		|| FLAGS(format, FT_PRINTF_PLUS) || ft_printf_space(format);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
		total_len += ft_printf_left_width_space(format);
	if (0 <= format->var.i && FLAGS(format, FT_PRINTF_PLUS))
		ft_putchar_fd('+', 1);
	if (format->var.i < 0)
		ft_putchar_fd('-', 1);
	total_len += ft_printf_width_zero(format);
	total_len += ft_printf_precision(format);
	if (n || NFLAGS(format, FT_PRINTF_POINT) || format->precision)
		ft_putuint_fd(n, 1);
	else
		format->var_len = 0;
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_uint(t_printf_format *format)
{
	t_uint	n;
	t_uint	total_len;

	total_len = 0;
	n = format->var.u;
	format->var_len = ft_uintlen(n, 10);
	format->prefix_len = FLAGS(format, FT_PRINTF_PLUS)
		|| ft_printf_space(format);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
		total_len += ft_printf_left_width_space(format);
	if (FLAGS(format, FT_PRINTF_PLUS))
		ft_putchar_fd('+', 1);
	total_len += ft_printf_width_zero(format);
	total_len += ft_printf_precision(format);
	if (n || NFLAGS(format, FT_PRINTF_POINT) || format->precision)
		ft_putuint_fd(n, 1);
	else
		format->var_len = 0;
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_percentage(t_printf_format *format)
{
	(void)format;
	ft_putchar_fd('%', 1);
	return (1);
}
