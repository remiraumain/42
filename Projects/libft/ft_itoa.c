/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 08:35:54 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/24 11:37:03 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (0 < n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

// static	int	power(int multi)
// {
// 	int	p;

// 	p = 1;
// 	while (0 < multi)
// 	{
// 		p = p * 10;
// 		multi--;
// 	}
// 	return (p);
// }

char	*ft_itoa(int n)
{
	int	size;
	char	*res;

	size = get_size(n);
	res = malloc(size * sizeof(char) + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	if (n == -2147483648)
		return ("-2147483648");
	if(n < 0)
		{
			res[0] = '-';
			n = n * -1;
		}
	while (0 < n)
	{
		
			size--;
			res[size] = (n % 10) + '0';
			n = n / 10;
	}
	return (res);
}

// int	main(void)
// {
// 	char *test = ft_itoa(-2147483647 -1);
// 	free(test);
// 	return (0);
// }

// char	*ft_itoa(int n)
// {
// 	int	size;
// 	int	temp;
// 	int multi;
// 	int	i;
// 	char	*res;

// 	// 123
// 	i = 0;
// 	size = get_size(n);
// 	res = malloc(size * sizeof(char) + 1);
// 	if (!res)
// 		return (NULL);
// 	while (i < size)
// 	{
// 		temp = n;
// 		multi = power(i + 1);
// 		while (temp >= multi)
// 			temp = temp / 10;
// 		res[i] = (temp % 10) + '0';
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
// }