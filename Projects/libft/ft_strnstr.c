/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:06:22 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/22 06:23:17 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// H E L L O \0 (6)
// L L O \0 (2)
//
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle || len < 1)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[j + i] == needle[j])
		{
			if (needle[j] == '\0' || j == len - 1)
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
#include <stdio.h>

int	main(void)
{
	printf("%s", ft_strnstr("lorem ipsum dolor", "ispum", 3));
	return (0);
}
