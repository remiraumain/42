/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:26:48 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 12:53:13 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Test de base pour ft_bzero.
void	test_ft_bzero_basic(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 5;
	memset(buffer_std, 'A', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'A', 10);
	buffer_custom[10] = '\0';
	bzero(buffer_std, n);
	ft_bzero(buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n]);
}

// Test avec n = 0.
void	test_ft_bzero_zero_size(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 0;
	memset(buffer_std, 'B', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'B', 10);
	buffer_custom[10] = '\0';
	bzero(buffer_std, n);
	ft_bzero(buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom);
}

// Test de zérotage complet du buffer.
void	test_ft_bzero_full_size(void)
{
	char	buffer_std[16];
	char	buffer_custom[16];
	size_t	n;

	n = 15;
	memset(buffer_std, 'C', 15);
	buffer_std[15] = '\0';
	memset(buffer_custom, 'C', 15);
	buffer_custom[15] = '\0';
	bzero(buffer_std, n);
	ft_bzero(buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n]);
}

// Test avec une taille grande (1024 caractères).
void	test_ft_bzero_large_size(void)
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
	bzero(buffer_std, n);
	ft_bzero(buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n]);
	free(buffer_std);
	free(buffer_custom);
}

// Test multiple appels de ft_bzero sur le même buffer.
void	test_ft_bzero_multiple_calls(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n1;
	size_t	n2;

	n1 = 5;
	n2 = 5;
	memset(buffer_std, 'E', 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 'E', 10);
	buffer_custom[10] = '\0';
	bzero(buffer_std, n1);
	ft_bzero(buffer_custom, n1);
	bzero(buffer_std + n1, n2);
	ft_bzero(buffer_custom + n1, n2);
	asser_cmp_buf(buffer_std, buffer_custom);
	asser_cmp_buf(&buffer_std[n1], &buffer_custom[n1]);
	asser_cmp_buf(&buffer_std[n1 + n2], &buffer_custom[n1 + n2]);
}

// Test avec des buffers contenant déjà des zéros.
void	test_ft_bzero_already_zero(void)
{
	char	buffer_std[11];
	char	buffer_custom[11];
	size_t	n;

	n = 10;
	memset(buffer_std, 0, 10);
	buffer_std[10] = '\0';
	memset(buffer_custom, 0, 10);
	buffer_custom[10] = '\0';
	bzero(buffer_std, n);
	ft_bzero(buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n]);
}

int	main(void)
{
	run_test(test_ft_bzero_basic, "ft_bzero_basic");
	run_test(test_ft_bzero_zero_size, "ft_bzero_zero_size");
	run_test(test_ft_bzero_full_size, "ft_bzero_full_size");
	run_test(test_ft_bzero_large_size, "ft_bzero_large_size");
	run_test(test_ft_bzero_multiple_calls, "ft_bzero_multiple_calls");
	run_test(test_ft_bzero_already_zero, "ft_bzero_already_zero");
	return (0);
}
 */