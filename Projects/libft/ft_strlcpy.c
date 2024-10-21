/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:25:13 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/21 17:48:15 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copie up to dstsize 1 characters from the string src to dst.
 *
 * The ft_strlcpy() functions copy and concatenate strings with the same input
 * 	parameters and output result. ft_strlcpy() take the full size of the
 * 	destination buffer and guarantee NUL-termination if there is room.
 *
 * @param dst Pointer of the string's destination.
 * @param src Pointer of the string's source.
 * @param dstsize Size of the destination.
 * @return The total length of the string they tried to create.
 *
 * @note Note that room for the NUL should be included in dstsize. Also note
 * 	that ft_strlcpy() only operate on true ''C'' strings. This means that for
 * 	ft_strlcpy() src must be NUL-terminated and for strlcat() both src and
 * 	dst() must be NUL-terminated.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (i < dstsize)
			dst[i] = src[i];
		i++;
	}
	if (0 < dstsize)
	{
		if (i < dstsize)
			dst[i] = '\0';
		else
			dst[dstsize - 1] = '\0';
	}
	return (i);
}
