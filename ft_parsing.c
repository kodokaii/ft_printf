/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/19 23:30:28 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_find_format(char **str)
{
	char	*specifier;

	*str = ft_strchr(*str, '%');
	if (!*str)
		return (0);
	specifier = ft_strpbrk(*str + 1, SPECIFIER);
	if (!specifier)
		return (0);
	return (specifier - *str + 1);
}

static size_t	ft_format_count(char *str)
{
	size_t	format_count;

	format_count = 0;
	while (ft_find_format(&str))
	{
		format_count++;
		str++;
	}
	return (format_count);
}

int	ft_printf_parsing(char *str, t_format *format)
{
	size_t		format_count;

	format_count = ft_format_count(str);
	format = ft_calloc(format_count, sizeof(t_format));
	if (format_count && !format)
		return (ENOMEM);
}
