/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:00:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/11/04 14:09:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Output the integer `n`.
 * 
 * @param n The integer to output.
 * @return The length of the nbr.
 */
int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		len++;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10);
		len++;
	}
	n = n % 10 + '0';
	write(1, &n, 1);
	return (len);
}
