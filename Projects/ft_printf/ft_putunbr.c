/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:11:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 21:16:13 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output the unsigned integer `n`.
 *
 * @param n The unsigned integer to output.
 * @return The length of the nbr.
 */
int	ft_putunbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		ft_putunbr(n / 10);
		len++;
	}
	n = n % 10 + '0';
	write(1, &n, 1);
	return (len);
}
