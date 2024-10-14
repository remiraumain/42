/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:27:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 11:16:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Convert a string to an integer.
 *
 * The ft_atoi() function converts the initial portion of the string pointed to
 *  by nptr to an integer. ft_atoi() does not detect errors.
 *
 * @param nptr Pointer of the string to convert into an int.
 * @return The converted value or 0 on error.
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (nptr[i])
	{
		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			return (res);
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res);
}
