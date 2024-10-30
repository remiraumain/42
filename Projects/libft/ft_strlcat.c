/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:43:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/30 07:29:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Append a string to another with size limit.
 *
 * Appends the null-terminated string `src` to the end of `dst`, ensuring
 * that the total length does not exceed `size` (including the null terminator).
 * If `size` is less than or equal to the length of `dst`, `dst` is left
 * unchanged, and `size + srclen` is returned.
 *
 * @param dst The destination string to append to.
 * @param src The source string to append.
 * @param size The total size of the destination buffer.
 * @return The initial length of `dst` plus the length of `src`.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!size)
		return (srclen);
	dstlen = ft_strlen(dst);
	if (size <= dstlen)
		return (size + srclen);
	if (size > dstlen + 1)
		ft_strlcpy(dst + dstlen, src, size - dstlen);
	return (dstlen + srclen);
}
