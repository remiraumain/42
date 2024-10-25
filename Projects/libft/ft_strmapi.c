/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:49:24 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/25 11:15:01 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	i = ft_strlen(s);
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[i] = '\0';
	while (i)
	{
		i--;
		dup[i] = f(i, s[i]);
	}
	return (dup);
}
