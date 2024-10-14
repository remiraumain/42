/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:43:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/14 11:09:36 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[j] && j < size)
	{
		if (size > 0)
		{
			if (i + j < size - 1)
				dst[i + j] = src[j];
			else
				dst[i + j] = '\0';
		}
		j++;
	}
	if (size > 0 && (i + j) <= size)
		dst[i + j] = '\0';
	return (i + j);
}
