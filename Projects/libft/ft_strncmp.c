/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:38:01 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/22 06:05:54 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two strings not more than n characters.
 *
 * The ft_strncmp() functions lexicographically compare the null-terminated
 * 	string1 and string2.
 *
 * The ft_strncmp() function compares not more than n characters.  Because
 * 	ft_strncmp() is designed for comparing strings rather than binary data,
 * 	characters that appear after a ‘\0’ character are not compared.
 *
 * @param string1 Pointer of the first string.
 * @param string2 Pointer of the second string.
 * @return Return an integer greater than, equal to, or less than 0, according
 * 	as the string1 is greater than, equal to, or less than the string2.
 * 	The comparison is done using unsigned characters, so that ‘\200’ is
 * 	greater than ‘\0’.
 */
int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	i = 0;
	s1 = (const unsigned char *)string1;
	s2 = (const unsigned char *)string2;
	if (!count)
		return (0);
	while (i < count && s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		if (!(i < count))
			return (s1[i - 1] - s2[i - 1]);
	}
	return (s1[i] - s2[i]);
}
