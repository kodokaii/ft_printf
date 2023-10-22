/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 22:02:26 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf_flags	ft_get_flags(char c)
{
	if (c == '+')
		return (FT_PRINTF_PLUS);
	if (c == '-')
		return (FT_PRINTF_MINUS);
	if (c == ' ')
		return (FT_PRINTF_SPACE);
	if (c == '#')
		return (FT_PRINTF_HASH);
	if (c == '.')
		return (FT_PRINTF_POINT);
	if (c == '0')
		return (FT_PRINTF_ZERO);
	return (FT_PRINTF_FLAG_NONE);
}

static t_printf_specifier	ft_get_specifier(char c)
{
	if (c == 'c')
		return (FT_PRINTF_CHAR);
	if (c == 's')
		return (FT_PRINTF_STRING);
	if (c == 'p')
		return (FT_PRINTF_POINTER);
	if (c == 'd' || c == 'i')
		return (FT_PRINTF_INT);
	if (c == 'u')
		return (FT_PRINTF_UNSIGNED);
	if (c == 'x')
		return (FT_PRINTF_HEXA_LOW);
	if (c == 'X')
		return (FT_PRINTF_HEXA_UP);
	if (c == '%')
		return (FT_PRINTF_PERCENTAGE);
	return (FT_PRINTF_SPECIFIER_NONE);
}

static t_printf_var	ft_get_var(t_printf_specifier specifier, va_list *arg_list)
{
	t_printf_var	var;

	var.p = NULL;
	if (specifier == FT_PRINTF_CHAR)
		var.c = va_arg(*arg_list, int);
	else if (specifier == FT_PRINTF_STRING)
		var.s = va_arg(*arg_list, char *);
	else if (specifier == FT_PRINTF_POINTER)
		var.p = va_arg(*arg_list, void *);
	else if (specifier == FT_PRINTF_INT)
		var.i = va_arg(*arg_list, int);
	else if (specifier == FT_PRINTF_UNSIGNED)
		var.u = va_arg(*arg_list, unsigned int);
	else if (specifier == FT_PRINTF_HEXA_LOW || specifier == FT_PRINTF_HEXA_UP)
		var.x = va_arg(*arg_list, unsigned int);
	return (var);
}

static char	*ft_get_format(const char *str,
			va_list *arg_list, t_printf_format *format)
{
	char	*current;

	current = (char *)str + 1;
	while (ft_strchr(FT_PRINTF_FLAGS, *current) && *current)
		format->flags |= ft_get_flags(*current++);
	if (*current == '*' && current++)
		format->width = va_arg(*arg_list, int);
	else if (ft_isdigit(*current))
		format->width = ft_strtoi(current, &current);
	if (*current == '.')
	{
		format->flags |= ft_get_flags(*current++);
		if (*current == '*' && current++)
			format->precision = va_arg(*arg_list, int);
		else if (ft_isdigit(*current))
			format->precision = ft_strtoi(current, &current);
	}
	format->specifier = ft_get_specifier(*current);
	if (ft_strchr(FT_PRINTF_SPECIFIER, *current) && *current)
	{
		format->var = ft_get_var(format->specifier, arg_list);
		return (current);
	}
	return ((char *)str);
}

int	ft_printf_parsing(const char *str, va_list *arg_list)
{
	t_printf_format	format;
	int				len;

	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&format, sizeof(t_printf_format));
			str = ft_get_format(str, arg_list, &format);
			if ((int)format.width < 0)
				format.flags |= FT_PRINTF_MINUS;
			format.width = ft_abs_int(format.width);
			format.precision = ft_abs_int(format.precision);
			len += ft_printf_format(&format);
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	return (len);
}
