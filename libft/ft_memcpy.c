/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:54:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 11:24:22 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies n bytes from a source to a destination.
 * 
 * The ft_memcpy() function copies n bytes from memory area src to memory area
 *  dest. The memory areas must not overlap. Use ft_memmove if the memory areas
 *  do overlap.
 * 
 * @param dest Pointer of the destination.
 * @param src Pointer of the source that is being copied.
 * @param n Number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dest;
	char	*temp;

	i = 0;
	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	while (i < n)
	{
		temp[i] = ptr_src[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = temp[i];
		i++;
	}
	return (dest);
}
