/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:44:22 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/06 11:58:36 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(size_t n)
{
	char	*base;
	int		len;

	base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += convert_hex(n / 16);
	len += ft_putchar(base[n % 16]);
	return (len);
}

/**
 * @brief Output the address of the pointer.
 *
 * @param ptr The pointer.
 * @return The lenght of the output. (nill) if NULL.
 */
int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	len = 0;
	len += ft_putstr("0x");
	len += convert_hex((size_t)ptr);
	return (len);
}
