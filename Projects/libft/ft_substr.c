/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:22:43 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/23 08:40:32 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Returns a substring.
 * 
 * Allocates (with malloc(3)) and returns a substring from the string ’s’. The 
 * substring begins at index ’start’ and is of maximum size ’len’.
 * 
 * @param s String from which to create the substring.
 * @param start Index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * 
 * @return The substring.NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	while (s[i])
		i++;
	if (i < start)
		start = i;
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = malloc(i * sizeof(char) + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
