/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:34:34 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:22:07 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>

// Test digit characters.
void	test_ft_atoi_digit(void)
{
	char	*c[6];
	size_t	expected;
	size_t	actual;
	int		i;

	c[0] = "123";
	c[1] = "0";
	c[2] = "-4156";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test whitespace characters.
void	test_ft_atoi_whitespace(void)
{
	char	*c[15];
	size_t	expected;
	size_t	actual;
	int		i;

	c[0] = "   123";
	c[1] = "\t\n  -456";
	c[2] = " \t +789 9";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test non-numeric characters after the number.
void	test_ft_atoi_non_numeric_after(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "123abc";
	c[1] = "-456def";
	c[2] = "+789ghi";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test non-numeric characters before the number.
void	test_ft_atoi_non_numeric_before(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "abc123";
	c[1] = "def-456";
	c[2] = "ghi+789";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test empty strings and strings with only whitespaces.
void	test_ft_atoi_empty_and_whitespaces(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "";
	c[1] = "    ";
	c[2] = "\t\n ";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test strings with leading zeros.
void	test_ft_atoi_leading_zeros(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "000123";
	c[1] = "-000456";
	c[2] = "+000789";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test integer limits and overflows.
void	test_ft_atoi_limits(void)
{
	char	*c[4];
	int		expected;
	int		actual;
	int		i;

	c[0] = "2147483647";
	c[1] = "-2147483648";
	c[2] = "2147483648";
	c[3] = "-2147483649";
	i = 0;
	while (i < 4)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test strings with multiple signs.
void	test_ft_atoi_multiple_signs(void)
{
	char	*c[5];
	int		expected;
	int		actual;
	int		i;

	c[0] = "+-123";
	c[1] = "--123";
	c[2] = "-+123";
	c[3] = "++123";
	c[4] = "12-34";
	i = 0;
	while (i < 5)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test strings with spaces between signs and digits.
void	test_ft_atoi_spaces_between_signs_and_digits(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "+ 123";
	c[1] = "- 456";
	c[2] = "  + 789";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test strings with special characters within the number.
void	test_ft_atoi_special_characters(void)
{
	char	*c[3];
	int		expected;
	int		actual;
	int		i;

	c[0] = "123\n456";
	c[1] = "789\t012";
	c[2] = "345\r678";
	i = 0;
	while (i < 3)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test strings with non-standard numeric prefixes.
void	test_ft_atoi_non_standard_prefixes(void)
{
	char	*c[2];
	int		expected;
	int		actual;
	int		i;

	c[0] = "0123";
	c[1] = "0x1A3";
	i = 0;
	while (i < 2)
	{
		expected = atoi(c[i]);
		actual = ft_atoi(c[i]);
		if (expected != actual)
			assert_eq(expected, actual);
		i++;
	}
	if (expected == actual)
		assert_eq(expected, actual);
}

// Test NULL input.
void	test_ft_atoi_null_input(void)
{
	int	expected;
	int	actual;

	expected = 0;
	actual = ft_atoi(NULL);
	assert_eq(expected, actual);
}

int	main(void)
{
	run_test(test_ft_atoi_digit, "ft_atoi_digit");
	run_test(test_ft_atoi_whitespace, "ft_atoi_whitespace");
	run_test(test_ft_atoi_non_numeric_after, "ft_atoi_non_numeric_after");
	run_test(test_ft_atoi_non_numeric_before, "ft_atoi_non_numeric_before");
	run_test(test_ft_atoi_empty_and_whitespaces,
		"ft_atoi_empty_and_whitespaces");
	run_test(test_ft_atoi_leading_zeros, "ft_atoi_leading_zeros");
	run_test(test_ft_atoi_limits, "ft_atoi_limits");
	run_test(test_ft_atoi_multiple_signs, "ft_atoi_multiple_signs");
	run_test(test_ft_atoi_spaces_between_signs_and_digits,
		"ft_atoi_spaces_between_signs_and_digits");
	run_test(test_ft_atoi_special_characters, "ft_atoi_special_characters");
	run_test(test_ft_atoi_non_standard_prefixes,
		"ft_atoi_non_standard_prefixes");
	run_test(test_ft_atoi_null_input, "ft_atoi_null_input");
	return (0);
}
 */