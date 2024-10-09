/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:22:14 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/09 08:23:09 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks for an alphanumeric character.
 * 
 * The ft_isalnum() function checks if c is an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).
 * 
 * @param c Character (ASCII encoded) to check.
 * @return Zero (0) if false (not an alphanumeric character) and One (1) if correct.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
