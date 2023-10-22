/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 23:32:39 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags
#define STATE	ft_printf_check_state
#define NSTATE	ft_printf_check_nostate

void	ft_printf_hexa_low(t_printf_format *format)
{
	t_uint	x;
	t_bool	display;

	x = format->var.u;
	display = (x || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX_HASH
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(x, 16));
	if (x)
		ft_printf_init_prefix(format, "0x");
	else
		ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	if (display)
		ft_putuint_base_fd(x, "0123456789abcdef", 1);
	ft_printf_before_var(format);
}

void	ft_printf_hexa_up(t_printf_format *format)
{
	t_uint	x;
	t_bool	display;

	x = format->var.u;
	display = (x || NFLAGS(format, PRINTF_POINT) || format->precision);
	format->state = PRINTF_PREFIX_HASH
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	ft_printf_init_len(format, ft_uintlen(x, 16));
	if (x)
		ft_printf_init_prefix(format, "0X");
	else
		ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	if (display)
		ft_putuint_base_fd(x, "0123456789ABCDEF", 1);
	ft_printf_before_var(format);
}
