/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2023/10/19 16:50:23 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	len;	
	char	*dst;

	len = ft_intlen(n, 10);
	dst = malloc(len + 1);
	if (dst)
	{
		i = 0;
		if (n < 0)
		{
			i = 1;
			dst[0] = '-';
			n = -n;
		}
		dst[len] = 0;
		while (i < len--)
		{
			dst[len] = '0' + (unsigned int)n % 10;
			n = (unsigned int)n / 10;
		}
	}
	return (dst);
}
