/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 03:22:11 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

t_uint	ft_printf_hexa_low(t_printf_format *format)
{
	t_uint	n;
	t_uint	total_len;

	total_len = 0;
	n = format->var.x;
	format->var_len = ft_uintlen(n, 16);
	format->prefix_len = 2 * (FLAGS(format, FT_PRINTF_HASH) && n);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
		total_len += ft_printf_left_width_space(format);
	if (FLAGS(format, FT_PRINTF_HASH) && n)
		ft_putstr_fd("0x", 1);
	total_len += ft_printf_width_zero(format);
	total_len += ft_printf_precision(format);
	if (n || NFLAGS(format, FT_PRINTF_POINT) || format->precision)
		ft_putuint_base_fd(n, "0123456789abcdef", 1);
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_hexa_up(t_printf_format *format)
{
	t_uint	n;
	t_uint	total_len;

	total_len = 0;
	n = format->var.x;
	format->var_len = ft_uintlen(n, 16);
	format->prefix_len = 2 * (FLAGS(format, FT_PRINTF_HASH) && n);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
		total_len += ft_printf_left_width_space(format);
	if (FLAGS(format, FT_PRINTF_HASH) && n)
		ft_putstr_fd("0X", 1);
	total_len += ft_printf_width_zero(format);
	total_len += ft_printf_precision(format);
	if (n || NFLAGS(format, FT_PRINTF_POINT) || format->precision)
		ft_putuint_base_fd(n, "0123456789ABCDEF", 1);
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}
