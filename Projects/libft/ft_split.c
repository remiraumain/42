/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 06:00:48 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/24 08:32:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/**
 * @brief Return an array of the split strings.
 * 
 * Allocates (with malloc(3)) and returns an array of strings obtained by 
 * splitting ’s’ using the character ’c’ as a delimiter. The array must end 
 * with a NULL pointer.
 * 
 * @param s String  string to be split.
 * @param start Delimiter characte.
 * 
 * @return The array of new strings resulting from the split.NULL if the 
 * allocation fails.
 */
static size_t	count_part(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int		was_in_part;

	i = 0;
	count = 0;
	was_in_part = 0;
	while (s[i])
	{
		if (!was_in_part && s[i] != c)
		{
			count++;
			was_in_part = 1;
		}
		if (was_in_part && s[i] == c)
			was_in_part = 0;
		i++;
	}
	return (count);
}

static size_t	partlen(char const *s_j, char c)
{
	size_t	i;

	i = 0;
	while (s_j[i] && s_j[i] != c)
		i++;
	return (i);
}

static void	clean(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		i--;
		free(arr[i]);
	}
	free(arr);
}

static size_t	fill_part(char **arr, const char *s, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (k < len)
	{
		arr[i][k] = s[j];
		k++;
		j++;
	}
	arr[i][k] = '\0';
	return (k);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	arr = malloc((count_part(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < count_part(s, c))
	{
		while (s[j] == c)
			j++;
		arr[i] = malloc(partlen(&s[j], c) * sizeof(char) + 1);
		if (!arr[i])
		{
			clean(arr);
			return (NULL);
		}
		j += fill_part(&arr[i], &s[j], partlen(&s[j], c));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
