/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:49:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 07:39:53 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erases n bytes of the memory  at the location pointed by s.
 * 
 * The  ft_bzero()  function  erases  the data in the n bytes of the memory starting
 *  at the location pointed to by s, by writing zeros (bytes containing '\0') to
 *  that area.
 * 
 * @param s Pointer of the memory's location. 
 * @param n Number of bytes to erase.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
