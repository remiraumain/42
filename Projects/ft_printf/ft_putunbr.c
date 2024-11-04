/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:11:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 22:02:05 by rraumain         ###   ########.fr       */
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
	if (n > 9)
		ft_putunbr(n / 10);
	n = n % 10 + '0';
	return (write(1, &n, 1));
}
