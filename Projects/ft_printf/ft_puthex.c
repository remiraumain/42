/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:21:23 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 12:09:50 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output the int `n` in base 16.
 *
 * @param n The integer to convert.
 * @param is_upper Bool `1` for uppercase. `0` for lowercase.
 * @return The lenght of the output.
 */
int	ft_puthex(unsigned int n, int is_upper)
{
	char	*base;
	int		len;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, is_upper);
	len += ft_putchar(base[n % 16]);
	return (len);
}
