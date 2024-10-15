/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:42:13 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 10:44:43 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test uppercase characters.
void	test_ft_isprint_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test lowercase characters.
void	test_ft_isprint_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test digit characters.
void	test_ft_isprint_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test symbol characters.
void	test_ft_isprint_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test punctuation characters.
void	test_ft_isprint_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test whitespace characters.
void	test_ft_isprint_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test boundery characters.
void	test_ft_isprint_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isprint_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test special characters.
void	test_ft_isprint_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test null characters.
void	test_ft_isprint_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isprint(c);
	actual = ft_isprint(c);
	ASSERT_EQ(expected, actual);
}

// Test extended characters.
void	test_ft_isprint_extended(void)
{
	char	c;
	int		start;
	int		end;
	size_t	expected;
	size_t	actual;

	start = 128;
	end = 255;
	while (start <= end)
	{
		c = start;
		expected = isprint(c);
		actual = ft_isprint(c);
		if (expected != actual)
			ASSERT_EQ(expected, actual);
		start++;
	}
	ASSERT_EQ(expected, actual);
}

int	main(void)
{
	RUN_TEST(test_ft_isprint_upper, "ft_isprint_upper");
	RUN_TEST(test_ft_isprint_lower, "ft_isprint_lower");
	RUN_TEST(test_ft_isprint_digit, "ft_isprint_digit");
	RUN_TEST(test_ft_isprint_symbol, "ft_isprint_symbol");
	RUN_TEST(test_ft_isprint_punctuation, "ft_isprint_punctuation");
	RUN_TEST(test_ft_isprint_whitespace, "ft_isprint_whitespace");
	RUN_TEST(test_ft_isprint_boundery, "ft_isprint_boundery");
	RUN_TEST(test_ft_isprint_non_ascii, "ft_isprint_non_ascii");
	RUN_TEST(test_ft_isprint_special, "ft_isprint_special");
	RUN_TEST(test_ft_isprint_null, "ft_isprint_null");
	RUN_TEST(test_ft_isprint_extended, "ft_isprint_extended");
	return (0);
}
 */