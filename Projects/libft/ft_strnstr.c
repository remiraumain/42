/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:06:22 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 09:02:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i])
	{
		j = 0;
		while(big[j + i] == little[j])
		{
			if (little[j] == '\0' || j == len)
				return (&big[i]);
			j++;
		}
		i = j + 1;
	}
	return (NULL);
}
