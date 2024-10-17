/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:20:47 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 10:55:09 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

// Test de base où 6 bytes sous alloués.
void	test_ft_calloc_basic(void)
{
	char	*result_buff;
	char	*result_custom;
	size_t	n;
	size_t	c_buff;
	size_t	c_custom;

	n = 6;
	c_buff = 0;
	c_custom = 0;
	result_buff = calloc(3, sizeof(char));
	if (!result_buff)
		return assert_fail("Memory allocation fail line for result_buff in test_ft_calloc_basic");
	result_custom = ft_calloc(n, sizeof(char));
	if (!result_custom)
		return assert_fail("Memory allocation fail line for result_custom in test_ft_calloc_basic");
	result_buff = memmove(result_buff, "Hello", 2);
	result_custom = memmove(result_custom, "Hello", 5);
	while (n > 0)
	{
		if (result_buff[n] == '\0' )
			c_buff++;
		if (result_custom[n] == '\0')
			c_custom++;
		n--;
	}
	assert_eq(c_buff, c_custom);
	free(result_buff);
	free(result_custom);
}

int	main(void)
{
	run_test(test_ft_calloc_basic, "ft_calloc_basic");
	return (0);
}