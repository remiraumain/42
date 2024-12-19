/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:46 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/05 10:05:07 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Output the character `c`.
 *
 * @param c The character.
 * @return The lenght of the output.
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
