/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/21 23:24:42 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	ft_printf_check_flags(t_printf_format *format, t_printf_flags flags)
{
	return ((format->flags & flags) == flags);
}

t_bool	ft_printf_check_noflags(t_printf_format *format, t_printf_flags flags)
{
	return (((format->flags ^ flags) & flags) == flags);
}
