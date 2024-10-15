/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:17:55 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 09:03:51 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for a numeric character.
 * 
 * The ft_isdigit() function checks if c is a numeric character (0 through 9).
 * 
 * @param c Character (ASCII encoded) to check.
 * @return 0 if false (not a numeric character) and 2048 if correct.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}
