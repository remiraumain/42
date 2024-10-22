/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:30:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/22 09:42:43 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a character in a string.
 * 
 * The ft_strstr() function  returns  a  pointer to the first occurrence of 
 * 	the character c in the string s.

 * @param s Pointer of the string to search.
 * @param c Character for the occurence.
 * @return Return a pointer to the matched character or NULL if  the character 
 * 	is  not found. The terminating null byte is considered part of the string, 
 * 	so that if c is specified as '\0', these functions return a pointer to the 
 * 	terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}
