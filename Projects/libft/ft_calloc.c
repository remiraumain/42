/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:12:13 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/30 16:11:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocate and zero-initialize an array.
 *
 * Allocates memory for an array of `nmemb` elements of `size` bytes each and
 * initializes all bytes to zero. Returns `NULL` if allocation fails.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element in bytes.
 * @return Pointer to the allocated memory, or `NULL` on failure.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	long int	i;

	i = nmemb * size;
	if (i < 0 || ((int)nmemb < 0 && (int)size < 0))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}
