/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:25:13 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/14 10:31:40 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		if (size > 0)
		{
			if (i < size)
				dst[i] = src[i];
			else
				dst[i] = '\0';
		}
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	return (i);
}
