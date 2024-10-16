/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:28:23 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 14:15:56 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTY_H
# define TESTY_H

#include <stdio.h>

// MACROS
void	run_test(void (*test)(void), const char *test_name);

// ASSERTIONS
void	assert_eq(int expected, int actual);
void	assert_str_eq(char *expected, char *actual);
void	assert_fail(char *message);
int		asser_cmp_buf(const char *expected, const char *actual, size_t n);

#endif
