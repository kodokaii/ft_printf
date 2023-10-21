/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 21:49:47 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(t_printf_format *format)
{
	if (format->specifier == FT_PRINTF_INT)
		return (ft_printf_int(format));
	if (format->specifier == FT_PRINTF_PERCENTAGE)
		return (ft_printf_percentage(format));
	return (ft_printf_percentage(format));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_list;
	int		len;

	va_start(arg_list, str);
	len = ft_printf_parsing(str, &arg_list);
	va_end(arg_list);
	return (len);
}
