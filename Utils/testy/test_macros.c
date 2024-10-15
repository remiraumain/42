/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:43:28 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/15 07:44:51 by rraumain         ###   ########.fr       */
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
 * @note Do not use, this function was made only for the `RUN_TEST` macro.
 */
void	run_test(void (*test)(void), const char *test_name)
{
	printf("Running: %s...\n", test_name);
	test();
}
