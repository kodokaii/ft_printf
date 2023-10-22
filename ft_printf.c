/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/22 02:55:43 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(t_printf_format *format)
{
	if (format->specifier == FT_PRINTF_CHAR)
		return (ft_printf_char(format));
	if (format->specifier == FT_PRINTF_STRING)
		return (ft_printf_str(format));
	if (format->specifier == FT_PRINTF_POINTER)
		return (ft_printf_ptr(format));
	if (format->specifier == FT_PRINTF_INT)
		return (ft_printf_int(format));
	if (format->specifier == FT_PRINTF_UNSIGNED)
		return (ft_printf_uint(format));
	if (format->specifier == FT_PRINTF_HEXA_LOW)
		return (ft_printf_hexa_low(format));
	if (format->specifier == FT_PRINTF_HEXA_UP)
		return (ft_printf_hexa_up(format));
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
