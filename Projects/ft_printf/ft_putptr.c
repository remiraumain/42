/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:44:22 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 10:29:14 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert_hex(size_t n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += convert_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
/**
 * @brief Output the address of the pointer.
 *
 * @param ptr The pointer.
 * @return The lenght of the output. (nill) if NULL.
 */
int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += convert_hex((size_t)ptr);
	return (count);
}
