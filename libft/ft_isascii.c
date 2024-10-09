/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:29:06 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 08:44:35 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the value fits into the ASCII character set.
 * 
 * The ft_isascii() function checks if c is an alphanumeric character; it is
 *  equivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c Character (ASCII encoded) to check.
 * @return Zero (0) if false (does not fits into the ASCII character set) and
 *  One (1) if correct.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
