/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:21:23 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 10:03:35 by rraumain         ###   ########.fr       */
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
	int		count;

	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, is_upper);
	count += ft_putchar(base[n % 16]);
	return (count);
}
