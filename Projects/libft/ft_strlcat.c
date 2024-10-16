/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:43:02 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 15:03:08 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
