/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 03:38:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

static t_uint	ft_printf_ptr_null(t_printf_format *format)
{
	char	*nul;
	t_uint	total_len;

	total_len = 0;
	nul = "(nil)";
	format->var_len = 5;
	total_len += ft_printf_left_width_space(format);
	ft_putstrn_fd(nul, format->var_len, 1);
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_str(t_printf_format *format)
{
	char	*str;
	t_uint	total_len;

	total_len = 0;
	str = format->var.s;
	if (!str)
		str = "(null)";
	format->var_len = ft_strlen(str);
	if (FLAGS(format, FT_PRINTF_POINT) && format->precision < format->var_len)
		format->var_len = format->precision;
	else
		format->precision = format->var_len;
	total_len += ft_printf_left_width_space(format);
	if (format->var.s || NFLAGS(format, FT_PRINTF_POINT) || format->precision)
		ft_putstrn_fd(str, format->var_len, 1);
	else
		format->var_len = 0;
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}

t_uint	ft_printf_ptr(t_printf_format *format)
{
	void	*ptr;
	t_uint	total_len;

	total_len = 0;
	ptr = format->var.p;
	if (!ptr)
		return (ft_printf_ptr_null(format));
	format->var_len = ft_llulen((t_llu)ptr, 16);
	format->prefix_len = (FLAGS(format, FT_PRINTF_PLUS)
			|| ft_printf_space(format)) + 2;
	total_len += ft_printf_left_width_space(format);
	ft_putstr_fd("0x", 1);
	if (FLAGS(format, FT_PRINTF_PLUS))
		ft_putchar_fd('+', 1);
	if (NFLAGS(format, FT_PRINTF_ZERO) || FLAGS(format, FT_PRINTF_POINT))
		total_len += ft_printf_width_zero(format);
	total_len += ft_printf_precision(format);
	ft_putllu_base_fd((t_llu)ptr, "0123456789abcdef", 1);
	total_len += ft_printf_right_width_space(format);
	total_len += format->var_len + format->prefix_len;
	return (total_len);
}
