/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:17:26 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/30 10:12:11 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy n bytes from a source to a destination.
 *
 * Copies len bytes from string src to string dst. The two strings may overlap;
 * the copy is always done in a non-destructive manner.
 *
 * @param dest Pointer of the destination.
 * @param src Pointer of the source that is being copied.
 * @param n Number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_dest;
	char	*ptr_src;

	i = 0;
	ptr_dest = (char *)dest;
	ptr_src = (char *)src;
	if (dest == src || !n)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (ptr_dest > ptr_src)
			ptr_dest[n - i - 1] = ptr_src[n - i - 1];
		else
			ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
