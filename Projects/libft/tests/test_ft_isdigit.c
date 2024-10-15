/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:47:33 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 09:04:34 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test digit characters.
void	test_ft_isdigit_digit(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '9';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test uppercase characters.
void	test_ft_isdigit_upper(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'H';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test lowercase characters.
void	test_ft_isdigit_lower(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = 'h';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test symbol characters.
void	test_ft_isdigit_symbol(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '@';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test punctuation characters.
void	test_ft_isdigit_punctuation(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '.';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test whitespace characters.
void	test_ft_isdigit_whitespace(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = ' ';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test boundery characters.
void	test_ft_isdigit_boundery(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '`';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test non-ASCII characters.
void	test_ft_isdigit_non_ascii(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = -87;
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test special characters.
void	test_ft_isdigit_special(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = EOF;
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test null characters.
void	test_ft_isdigit_null(void)
{
	char	c;
	size_t	expected;
	size_t	actual;

	c = '\0';
	expected = isdigit(c);
	actual = ft_isdigit(c);
	ASSERT_EQ(expected, actual);
}

// Test extended characters.
void	test_ft_isdigit_extended(void)
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
		expected = isdigit(c);
		actual = ft_isdigit(c);
		if (expected != actual)
			ASSERT_EQ(expected, actual);
		start++;
	}
	ASSERT_EQ(expected, actual);
}

int	main(void)
{
	RUN_TEST(test_ft_isdigit_digit, "ft_isdigit_digit");
	RUN_TEST(test_ft_isdigit_upper, "ft_isdigit_upper");
	RUN_TEST(test_ft_isdigit_lower, "ft_isdigit_lower");
	RUN_TEST(test_ft_isdigit_symbol, "ft_isdigit_symbol");
	RUN_TEST(test_ft_isdigit_punctuation, "ft_isdigit_punctuation");
	RUN_TEST(test_ft_isdigit_whitespace, "ft_isdigit_whitespace");
	RUN_TEST(test_ft_isdigit_boundery, "ft_isdigit_boundery");
	RUN_TEST(test_ft_isdigit_non_ascii, "ft_isdigit_non_ascii");
	RUN_TEST(test_ft_isdigit_special, "ft_isdigit_special");
	RUN_TEST(test_ft_isdigit_null, "ft_isdigit_null");
	RUN_TEST(test_ft_isdigit_extended, "ft_isdigit_extended");
	return (0);
}
 */