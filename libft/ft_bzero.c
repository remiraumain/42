/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:49:53 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 07:16:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Brief
 * 
 * Desc
 * 
 * @param s What is s
 * @param n What is n 
 */
void	bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
