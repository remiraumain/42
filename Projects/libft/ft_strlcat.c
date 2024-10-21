/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:43:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/21 18:17:03 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenates src to dst, ensuring null-termination.
 *
 * Appends src to dst, copying up to dstsize - strlen(dst) - 1 characters,
 * ensuring the result is null-terminated if there's space. Takes the total
 * size of the buffer (dstsize) into account, and returns the length of the
 * string they tried to create (initial length of dst + length of src).
 *
 * @param dst Destination string (must be null-terminated).
 * @param src Source string (must be null-terminated).
 * @param dstsize Total size of the destination buffer (including space for
 * 	null terminator).
 * @return Total length of the string it tried to create (dst + src).
 * If the return value is >= dstsize, truncation occurred.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	cpy_len;

	i = 0;
	j = 0;
	k = 0;
	while (i < size && dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	if (size <= i)
		return (size + j);
	cpy_len = size - i - 1;
	while (k < cpy_len && src[k] != '\0')
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (i + j);
}
