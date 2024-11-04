/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:52 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 14:09:15 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Output the string `s`.
 * 
 * @param s The string to output.
 * @return The length of `s`.
 */
int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
	return (i);
}