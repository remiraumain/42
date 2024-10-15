/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:15:29 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 09:03:49 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Check for an alphabetic character.
 * 
 * The ft_isalpha() function checks if c is an alphabetic character; it is
 *  equivalent to (isupper(c) || islower(c)).
 * 
 * @param c Character (ASCII encoded) to check.
 * @return 0 if false (not an alphabetic character) and 1024 if
 *  correct.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1024);
	return (0);
}
