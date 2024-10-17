/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:38:01 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 19:56:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	i;

	i = 0;
	if (!count)
		return (0);
	while (i < count && string1[i])
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
		if (!(i < count))
			return (string1[i - 1] - string2[i - 1]);
	}
	return (string1[i] - string2[i]);
}
