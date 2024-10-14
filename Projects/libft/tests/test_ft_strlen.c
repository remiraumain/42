/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:28:30 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 11:16:21 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"

/**
 * Test Standard string.
 */
TEST(test_ft_strlen_basic)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "Hello, World!";
	expected = 13;
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test Empty string.
 */
TEST(test_ft_strlen_empty)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "";
	expected = 0;
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

int	main(void)
{
	RUN_TEST(test_ft_strlen_basic, "ft_strlen_basic");
	RUN_TEST(test_ft_strlen_empty, "ft_strlen_empty");
	return (0);
}
