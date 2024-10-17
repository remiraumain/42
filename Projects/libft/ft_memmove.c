/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:17:26 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 15:46:31 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr_src;
	char	*ptr_dest;

	i = 0;
	ptr_src = (char *)src;
	ptr_dest = (char *)dest;
	if (!dest || !src)
		return (NULL);
	while (i < n)
	{
		if (dest > src)
			ptr_dest[n - i - 1] = ptr_src[n - i - 1];
		else
			ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
