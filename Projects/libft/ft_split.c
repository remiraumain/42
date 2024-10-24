/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 06:00:48 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/24 06:25:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	count_part(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

size_t	partlen(char const *s_j, char c)
{
	size_t	i;

	i = 0;
	while (s_j[i] && s_j[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = 0;
	size = count_part(s, c);
	arr = malloc(size * sizeof(char *) + 1);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		len = partlen(&s[j], c);
		arr[i] = malloc(len * sizeof(char) + 1);
		if (!arr[i])
		{
			while (0 < i)
			{
				i--;
				free(arr[i]);
			}
			free(arr);
			return (NULL);
		}
		k = 0;
		while (k < len)
		{
			arr[i][k] = s[j];
			k++;
			j++;
		}
		arr[i][k] = '\0';
		i++;
	}
	arr[size] = 0;
	return (arr);
}
#include <stdio.h>

int	main(void)
{
	char s[] = "Hello world and younes";
	int i = 0;
	char **arr = ft_split(s, ' ');
	while (arr[i])
	{
		printf("%s", arr[i]);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}