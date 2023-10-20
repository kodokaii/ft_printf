/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 01:39:27 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_skip_format(const char *str)
{
	char	*current;

	current = (char *)str;
	while (ft_strchr(FT_PRINTF_FLAGS, *current))
		current++;
	if (*current == '*')
		current++;
	else
		while (ft_isdigit(*current))
			current++;
	if (*current == '.')
	{
		current++;
		if (*current == '*')
			current++;
		else
			while (ft_isdigit(*current))
				current++;
	}
	if (ft_strchr(FT_PRINTF_SPECIFIER, *str))
		return (current++);
	return ((char *)str);
}

int	ft_printf(const char *str, ...)
{
	t_list	*format_list;
	t_list	*current;
	va_list	arg_list;

	format_list = NULL;
	va_start(arg_list, str);
	ft_printf_parsing(str, &arg_list, &format_list);
	va_end(arg_list);
	current = format_list;
	while (*str)
	{
		if (*str == '%')
		{
			ft_putnbr_fd(((t_printf_format *)current->content)->var.i, 1);
			str = ft_skip_format(str);
			current = current->next;
		}
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	return (0);
}
