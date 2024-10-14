/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:17 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 08:44:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Replace n bytes of the memory at the location pointed by s with the
 *  constant byte c.
 * 
 * The ft_memset() function fills the first n bytes of the memory area pointed
 *  to by s with the constant byte c.
 * 
 * @param s Pointer of the memory's location.
 * @param c The constant byte that is used for the replacement.
 * @param n Number of bytes to erase.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
}
