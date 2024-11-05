/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 07:27:41 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output the integer `n`.
 *
 * @param n The integer to output.
 * @return The length of the nbr.
 */
int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		len++;
		write(1, "-", 1);
		n = n * -1;
	}
	if (n > 9)
	{
		len++;
		ft_putnbr(n / 10);
	}
	len++;
	n = n % 10 + '0';
	write(1, &n, 1);
	return (len);
}
