/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:42:40 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/23 09:00:03 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Returns the concatenated string.
 * 
 * Allocates (with malloc(3)) and returns a new string, which is the result of 
 * the concatenation of ’s1’ and ’s2’.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * 
 * @return The new string.NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	res = malloc((i + j) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	res[i + j] = '\0';
	while (0 < j)
	{
		j--;
		res[i + j] = s2[j];
	}
	while (0 < i)
	{
		i--;
		res[i] = s1[i];
	}
	return (res);
}
