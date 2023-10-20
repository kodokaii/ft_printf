/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 01:40:45 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf_flags	ft_get_flags(char c)
{
	if (c == '+')
		return (FT_PRINTF_PLUS);
	if (c == ' ')
		return (FT_PRINTF_SPACE);
	if (c == '#')
		return (FT_PRINTF_HASH);
	if (c == '.')
		return (FT_PRINTF_POINT);
	if (c == '0')
		return (FT_PRINTF_ZERO);
	return (ft_PRINTF_FLAG_NONE);
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
	str = ft_strchr(str, '%');
	if (str)
	{
		str++;
		while (ft_strchr(FT_PRINTF_FLAGS, *str))
			format->flags |= ft_get_flags(*str++);
		if (*str == '*' && str++)
			format->width = va_arg(*arg_list, int);
		else if (ft_isdigit(*str))
			format->width = ft_strtoi(str, (char **)&str);
		if (*str == '.')
		{
			format->flags |= ft_get_flags(*str++);
			if (*str == '*' && str++)
				format->precision = va_arg(*arg_list, int);
			else if (ft_isdigit(*str))
				format->precision = ft_strtoi(str, (char **)&str);
		}
		format->specifier = ft_get_specifier(*str);
		if (ft_strchr(FT_PRINTF_SPECIFIER, *str) && str++)
			format->var = ft_get_var(format->specifier, arg_list);
	}
	return ((char *)str);
}

int	ft_printf_parsing(const char *str, va_list *arg_list, t_list **format_list)
{
	t_printf_format	*format;
	t_list			*new;

	while (str)
	{
		format = ft_calloc(1, sizeof(t_printf_format));
		if (!format)
			return (ENOMEM);
		str = ft_get_format(str, arg_list, format);
		if (str)
		{
			new = ft_lstnew(format);
			if (!new)
				return (ENOMEM);
			ft_lstadd_back(format_list, new);
		}
	}
	return (0);
}
