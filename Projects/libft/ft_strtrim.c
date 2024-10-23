/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:25:18 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/23 14:14:40 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Return a string without leading and trailing character's set.
 *
 * Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
 * specified in ’set’ removed from the beginning and the end of the string.
 *
 * @param s1 String to be trimmed.
 * @param set Reference set of characters to trim.
 *
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = 0;
	i = 0;
	while (is_in_set(s1[start], set))
		start++;
	while (s1[end])
		end++;
	while (end - start && is_in_set(s1[end - 1], set))
		end--;
	res = malloc((end - start) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (i < (end - start))
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
