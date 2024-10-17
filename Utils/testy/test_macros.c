/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:43:28 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:19:48 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * @brief Runs a test function and displays its name.
 *
 * This macro is used to execute a test function that was defined using the
 *  `TEST` macro. It prints the name of the test before executing it, which
 *  helps in tracking test execution.
 *
 * @param test The test function to run.
 * @param test_name The name of the test function to run.
 *
 * @code
 * --- Example usage ---
 *
 * int main(void)
 * {
 *     run_test(my_test_function, my_test_function_name);
 *     return (0);
 * }
 * @endcode
 */
void	run_test(void (*test)(void), const char *test_name)
{
	printf("Running: %s...\n", test_name);
	test();
}
