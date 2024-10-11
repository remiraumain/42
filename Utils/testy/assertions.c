/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assertions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:50:31 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/10 16:20:12 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	do
	{
		if (expected != actual)
		{
			printf("❌ %s:%d: Expected %d, got %d\n", __FILE__, __LINE__,
				expected, actual);
		}
		else
		{
			printf("✅ %s:%d\n", __FILE__, __LINE__);
		}
	} while (0);
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
	do
	{
		if (strcmp(expected, actual) != 0)
		{
			printf("❌ %s:%d: Expected %s, got %s\n", __FILE__, __LINE__,
				(expected), (actual));
		}
		else
		{
			printf("✅ %s:%d\n", __FILE__, __LINE__);
		}
	} while (0);
}
