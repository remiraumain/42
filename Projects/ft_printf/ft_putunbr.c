/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:11:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 10:06:06 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output the unsigned integer `n`.
 *
 * @param n The unsigned integer.
 * @return The length of the output.
 */
int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}
