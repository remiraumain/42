/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:28:30 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 20:24:44 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

/**
 * Test Standard string.
 */
TEST(test_ft_strlen_basic)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "Hello, World!";
	expected = strlen(str);
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
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test one character.
 */
TEST(test_ft_strlen_only_one)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "A";
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test white spaces.
 */
TEST(test_ft_strlen_whitespaces)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "     ";
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test special characters.
 */
TEST(test_ft_strlen_special)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "\n\t\r\b\\\'\"";
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test if stop at null-terminated character.
 */
TEST(test_ft_strlen_null_terminated)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "He\0llo";
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test counting of UTF-8 multibyte characters.
 */
TEST(test_ft_strlen_utf8_character)
{
	const char	*str;
	size_t		expected;
	size_t		actual;

	str = "Héllo";
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
}

/**
 * Test ft_strlen with a very long string.
 */
TEST(test_ft_strlen_long_string)
{
	char	*str;
	size_t	length;
	size_t	expected;
	size_t	actual;
	size_t	i;

	length = 1000000;
	i = 0;
	str = malloc((length + 1) * sizeof(char));
	if (!str)
	{
		ASSERT_FAIL("Memory allocation failed");
		return ;
	}
	while (i < length)
	{
		str[i] = 'a';
		i++;
	}
	str[length] = '\0';
	expected = strlen(str);
	actual = ft_strlen(str);
	ASSERT_EQ(expected, actual);
	free(str);
}

int	main(void)
{
	RUN_TEST(test_ft_strlen_basic, "ft_strlen_basic");
	RUN_TEST(test_ft_strlen_empty, "ft_strlen_empty");
	RUN_TEST(test_ft_strlen_long_string, "test_ft_strlen_long_string");
	RUN_TEST(test_ft_strlen_null_terminated, "test_ft_strlen_null_terminated");
	RUN_TEST(test_ft_strlen_only_one, "test_ft_strlen_only_one");
	RUN_TEST(test_ft_strlen_special, "test_ft_strlen_special");
	RUN_TEST(test_ft_strlen_utf8_character, "test_ft_strlen_utf8_character");
	RUN_TEST(test_ft_strlen_whitespaces, "test_ft_strlen_whitespaces");
	return (0);
}
