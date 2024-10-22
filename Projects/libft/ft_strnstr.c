/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:06:22 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/22 09:17:26 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring in a string.
 * 
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * 	string needle in the string haystack, where not more than len characters are
 * 	searched. Characters that appear after a ‘\0’ character are not searched.
 *
 * @param haystack Pointer of the string to search.
 * @param needle Pointer of the occurence's string.
 * @return (If needle is an empty string, haystack is returned); if needle
 * 	occurs nowhere in haystack, NULL is re‐turned; otherwise a pointer to
 * 	the first character of the first occurrence of needle is re‐turned.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[j + i] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
