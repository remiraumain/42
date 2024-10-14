/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 20:17:25 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

/**
 * @brief Check if two integers are equal.
 *
 * This function checks if the expected value is equal to the actual value.
 * If they are not equal, it prints an error message indicating the
 * file and line number, as well as the expected and actual values.
 *
 * @param expected The expected value (int).
 * @param actual The actual value (int).
 *
 * @note Do not use, this function was made only for the `ASSERT_EQ` macro.
 * @note Ensure that both `expected` and `actual` are of compatible types.
 */
void	assert_eq(int expected, int actual)
{
	if (expected != actual)
	{
		printf("❌ Expected %d, got %d\n", expected, actual);
	}
	else
	{
		printf("✅ Expected %d, got %d\n", expected, actual);
	}
}

/**
 * @brief Check if two strings are equal.
 *
 * This function checks if the expected value is equal to the actual value.
 * If they are not equal, it prints an error message indicating the
 * file and line number, as well as the expected and actual values.
 *
 * @param expected The expected value (char *).
 * @param actual The actual value (char *).
 *
 * @note Do not use, this function was made only for the `ASSERT_STR_EQ` macro.
 * @note Ensure that both `expected` and `actual` are of compatible types.
 */
void	assert_str_eq(char *expected, char *actual)
{
	if (strcmp(expected, actual) != 0)
	{
		printf("❌ Expected %s, got %s\n", expected, actual);
	}
	else
	{
		printf("✅ Expected %s, got %s\n", expected, actual);
	}
}

/**
 * @brief Show an error message if assertion fail
 *
 * This function show on the console an error message.
 *
 * @param message The error message.
 */
void	assert_fail(char *message)
{
	printf("%s", message);
}
