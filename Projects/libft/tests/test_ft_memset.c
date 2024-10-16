/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:08:00 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 14:15:10 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

/* Test de base pour ft_memset. */
void	test_ft_memset_basic(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 5;
	memset(buffer_std, 'A', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'A', 10);
	buffer_custom[10] = '\0';
	memset(buffer_std, 'A', n);
	ft_memset(buffer_custom, 'A', n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n], 1);
}

/* Test avec n = 0. */
void	test_ft_memset_zero_size(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 0;
	memset(buffer_std, 'B', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'B', 10);
	buffer_custom[10] = '\0';
	memset(buffer_std, 'B', n);
	ft_memset(buffer_custom, 'B', n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
}

/* Test de remplissage complet du buffer. */
void	test_ft_memset_full_size(void)
{
	char	buffer_std[16];
	char	buffer_custom[16];
	size_t	n;

	n = 15;
	memset(buffer_std, 'C', 15);
	buffer_std[15] = '\0';
	memset(buffer_custom, 'C', 15);
	buffer_custom[15] = '\0';
	memset(buffer_std, 'C', n);
	ft_memset(buffer_custom, 'C', n);
	asser_cmp_buf(buffer_std, buffer_custom, 15);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n], 1);
}

/* Test avec une taille grande (1024 octets). */
void	test_ft_memset_large_size(void)
{
	size_t	n;
	char	*buffer_std;
	char	*buffer_custom;

	n = 1024;
	buffer_std = malloc(n + 1);
	buffer_custom = malloc(n + 1);
	if (!buffer_std || !buffer_custom)
	{
		assert_eq(1, 0);
		return ;
	}
	memset(buffer_std, 'D', n);
	buffer_std[n] = '\0';
	memset(buffer_custom, 'D', n);
	buffer_custom[n] = '\0';
	memset(buffer_std, 'E', n);
	ft_memset(buffer_custom, 'E', n);
	asser_cmp_buf(buffer_std, buffer_custom, n);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n], 1);
	free(buffer_std);
	free(buffer_custom);
}

/* Test multiple appels de ft_memset sur le même buffer. */
void	test_ft_memset_multiple_calls(void)
{
	char	buffer_std[21];
	char	buffer_custom[21];
	size_t	n1;
	size_t	n2;

	n1 = 10;
	n2 = 10;
	memset(buffer_std, 'F', 20);
	buffer_std[20] = '\0';
	memset(buffer_custom, 'F', 20);
	buffer_custom[20] = '\0';
	memset(buffer_std, 'F', n1);
	ft_memset(buffer_custom, 'F', n1);
	memset(buffer_std + n1, 'S', n2);
	ft_memset(buffer_custom + n1, 'S', n2);
	asser_cmp_buf(buffer_std, buffer_custom, 20);
	asser_cmp_buf(&buffer_std[n1], &buffer_custom[n1], n2);
	asser_cmp_buf(&buffer_std[n1 + n2], &buffer_custom[n1 + n2], 1);
}

/* Test avec des buffers contenant déjà des zéros. */
void	test_ft_memset_already_zero(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 10;
	memset(buffer_std, 0, 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 0, 10);
	buffer_custom[10] = '\0';
	memset(buffer_std, 'Z', n);
	ft_memset(buffer_custom, 'Z', n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n], 1);
}

int	main(void)
{
	run_test(test_ft_memset_basic, "ft_memset_basic");
	run_test(test_ft_memset_zero_size, "ft_memset_zero_size");
	run_test(test_ft_memset_full_size, "ft_memset_full_size");
	run_test(test_ft_memset_large_size, "ft_memset_large_size");
	run_test(test_ft_memset_multiple_calls, "ft_memset_multiple_calls");
	run_test(test_ft_memset_already_zero, "ft_memset_already_zero");
	return (0);
}
