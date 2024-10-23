/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:19:54 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/23 07:20:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Duplicate a string.
 * 
 * The  ft_strdup() function returns a pointer to a new string which is a 
 * duplicate of the string s. Memory for the new string is obtained with 
 * malloc, and can be freed with free.
 * 
 * @param s Pointer of the string to duplicate.
 * 
 * @return A pointer to the duplicated string or NULL if insufficient memory 
 * was available.
 */
char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dup;

	i = 0;
	while (s[i])
		i++;
	dup = malloc(i * sizeof(char) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
