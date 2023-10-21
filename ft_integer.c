/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 20:22:44 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags

t_uint	ft_printf_int(t_printf_format *format)
{
	t_uint	n;
	t_bool	sign;

	n = ft_abs_int(format->var.i);
	sign = (format->var.i < 0) || FLAGS(format, FT_PRINTF_PLUS);
	format->var_len = ft_uintlen(n, 10) + sign;
	if (FLAGS(format, FT_PRINTF_SPACE) && !sign && ++format->var_len)
		ft_putchar_fd(' ', 1);
	if (NFLAGS(format, FT_PRINTF_MINUS))
		format->var_len += ft_printf_width_space(format);
	if (sign)
	{
		if (FLAGS(format, FT_PRINTF_PLUS))
			ft_putchar_fd('+', 1);
		else
			ft_putchar_fd('-', 1);
	}
	format->var_len += ft_printf_width_zero(format);
	format->var_len += ft_printf_precision(format);
	if (n || NFLAGS(format, FT_PRINTF_POINT))
		ft_putunbr_fd(n, 1);
	format->var_len += ft_printf_width_space(format);
	return (format->var_len);
}
