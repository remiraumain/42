/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:07:13 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 06:55:02 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <ctype.h>

// Test des caractères imprimables.
void	test_ft_isprint_printable(void)
{
	assert_eq(isprint('A'), ft_isprint('A'));
	assert_eq(isprint('a'), ft_isprint('a'));
	assert_eq(isprint('0'), ft_isprint('0'));
	assert_eq(isprint('!'), ft_isprint('!'));
	assert_eq(isprint(' '), ft_isprint(' '));
	assert_eq(isprint('~'), ft_isprint('~'));
}

// Test des caractères non imprimables.
void	test_ft_isprint_non_printable(void)
{
	assert_eq(isprint('\n'), ft_isprint('\n'));
	assert_eq(isprint('\t'), ft_isprint('\t'));
	assert_eq(isprint('\0'), ft_isprint('\0'));
	assert_eq(isprint('\r'), ft_isprint('\r'));
	assert_eq(isprint('\v'), ft_isprint('\v'));
	assert_eq(isprint('\f'), ft_isprint('\f'));
}

// Test des cas limites.
void	test_ft_isprint_edge_cases(void)
{
	assert_eq(isprint(31), ft_isprint(31));
	assert_eq(isprint(32), ft_isprint(32));
	assert_eq(isprint(126), ft_isprint(126));
	assert_eq(isprint(127), ft_isprint(127));
	assert_eq(isprint(128), ft_isprint(128));
	assert_eq(isprint(255), ft_isprint(255));
}

// Test de tous les caractères ASCII.
void	test_ft_isprint_all_ascii(void)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		assert_eq(isprint(i), ft_isprint(i));
		i++;
	}
}

int	main(void)
{
	run_test(test_ft_isprint_printable, "ft_isprint_printable");
	run_test(test_ft_isprint_non_printable, "ft_isprint_non_printable");
	run_test(test_ft_isprint_edge_cases, "ft_isprint_edge_cases");
	run_test(test_ft_isprint_all_ascii, "ft_isprint_all_ascii");
	return (0);
}
 */