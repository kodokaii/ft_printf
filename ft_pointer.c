/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 23:02:52 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define FLAGS	ft_printf_check_flags
#define NFLAGS	ft_printf_check_noflags
#define STATE	ft_printf_check_state
#define NSTATE	ft_printf_check_nostate

void	ft_printf_str(t_printf_format *format)
{
	char	*str;
	t_uint	len;
	t_bool	display;

	str = format->var.s;
	display = (str || NFLAGS(format, PRINTF_POINT) || 5 < format->precision);
	format->state = PRINTF_WIDTH_SPACE | PRINTF_DISPLAY * display;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (FLAGS(format, PRINTF_POINT))
		len = ft_min_uint(format->precision, len);
	ft_printf_init_len(format, len);
	ft_printf_init_prefix(format, "");
	ft_printf_after_var(format);
	if (display)
		ft_putstrn_fd(str, len, 1);
	ft_printf_before_var(format);
}

void	ft_printf_ptr(t_printf_format *format)
{
	void	*ptr;
	t_bool	display;

	ptr = format->var.p;
	display = !!ptr;
	format->state = PRINTF_PREFIX
		| PRINTF_PREFIX_HASH
		| PRINTF_WIDTH_SPACE
		| PRINTF_WIDTH_ZERO
		| PRINTF_PRECISION
		| PRINTF_DISPLAY * display;
	format->flags |= PRINTF_HASH;
	format->var_len = 5;
	ft_printf_init_len(format, ft_llulen((t_llu)ptr, 16));
	ft_printf_init_prefix(format, "0x");
	ft_printf_after_var(format);
	if (ptr)
		ft_putllu_base_fd((t_llu)ptr, "0123456789abcdef", 1);
	else
		ft_putstr_fd("(nil)", 1);
	ft_printf_before_var(format);
}
