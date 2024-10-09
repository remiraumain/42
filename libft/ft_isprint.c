/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:34:21 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 08:43:37 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for a printable character.
 * 
 * The ft_isprint() function checks if c is a printable character (including
 *  space).
 * 
 * @param c Character (ASCII encoded) to check.
 * @return Zero (0) if false (not a printable character) and One (1) if correct.
 */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
