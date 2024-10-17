/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strnstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 08:57:51 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 10:43:56 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <bsd/string.h>

// Test de base où le caractère est présent au milieu de la chaîne.
void	test_ft_strnstr_basic(void)
{
	const char	*big_std = "Hello, World!";
	const char	*little_std = "world";
	size_t		len;
	char		*result_std;
	char		*result_custom;

	len = 5;
	result_std = strnstr(big_std, little_std, len);
	result_custom = ft_strnstr(big_std, little_std, len);
	assert_eq((result_std != NULL), (result_custom != NULL));
	if (result_std && result_custom)
	{
		assert_eq(strcmp(result_std, result_custom), 0);
	}
}

int	main(void)
{
	run_test(test_ft_strnstr_basic, "ft_strnstr_basic");
	return (0);
}
 */