/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:49:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/30 11:20:17 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erase `n` bytes of the memory at the location pointed by `s`.
 *
 * Erases  the data in the n bytes of the memory starting at the location
 * pointed to by `s`, by writing zeros (bytes containing '\0') to that area.
 *
 * @param s Pointer of the memory's location.
 * @param n Number of bytes to erase.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
