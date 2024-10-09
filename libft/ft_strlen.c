/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:15:44 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 08:21:11 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the length of a string.
 * 
 * The  ft_strlen() function calculates the length of the string pointed to by s,
 *  excluding the terminating null byte ('\0').
 * 
 * @param s Pointer of the string's first character (or the starting point).
 * @return The lenght of the string (number of bytes) pointed by s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
