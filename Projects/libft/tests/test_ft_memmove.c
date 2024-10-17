/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:36:49 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/16 15:46:55 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <stdlib.h>
#include <string.h>

// Test de base pour ft_memmove sans chevauchement.
void	test_ft_memmove_basic(void)
{
	char	src[] = "HelloWorld";
	char	dest_std[20];
	char	dest_custom[20];
	size_t	n;

	n = 10;
	memset(dest_std, 'A', 19);
	dest_std[19] = '\0';
	memset(dest_custom, 'A', 19);
	dest_custom[19] = '\0';
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, n);
	asser_cmp_buf(&dest_std[n], &dest_custom[n], 10);
}

// Test de memmove avec chevauchement où dest > src.
void	test_ft_memmove_overlap_dest_after_src(void)
{
	char	buffer_std[20] = "1234567890";
	char	buffer_custom[20] = "1234567890";
	size_t	n;

	n = 6;
	memmove(buffer_std + 3, buffer_std, n);
	ft_memmove(buffer_custom + 3, buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom, 9);
	asser_cmp_buf(&buffer_std[9], &buffer_custom[9], 1);
}

// Test de memmove avec chevauchement où dest < src.
void	test_ft_memmove_overlap_dest_before_src(void)
{
	char	buffer_std[20] = "ABCDEFGHIJ";
	char	buffer_custom[20] = "ABCDEFGHIJ";
	size_t	n;

	n = 6;
	memmove(buffer_std, buffer_std + 4, n);
	ft_memmove(buffer_custom, buffer_custom + 4, n);
	asser_cmp_buf(buffer_std, buffer_custom, 10);
}

// Test de memmove avec size = 0.
void	test_ft_memmove_zero_size(void)
{
	char	src[] = "Test";
	char	dest_std[10] = "123456789";
	char	dest_custom[10] = "123456789";
	size_t	n;

	n = 0;
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, 9);
}

// Test de memmove avec size insuffisant, entraînant une troncature.
void	test_ft_memmove_truncate(void)
{
	char	src[] = "Truncate";
	char	dest_std[10] = "123456789";
	char	dest_custom[10] = "123456789";
	size_t	n;

	n = 5;
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, n);
	asser_cmp_buf(&dest_std[n], &dest_custom[n], 5);
}

// Test de memmove avec size exactement la taille nécessaire.
void	test_ft_memmove_exact_size(void)
{
	char	src[] = "ExactSize";
	char	dest_std[10];
	char	dest_custom[10];
	size_t	n;

	n = 9;
	memset(dest_std, 'A', 9);
	dest_std[9] = '\0';
	memset(dest_custom, 'A', 9);
	dest_custom[9] = '\0';
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, n);
	asser_cmp_buf(&dest_std[n], &dest_custom[n], 1);
}

// Test de memmove avec une très grande taille, aucune troncature.
void	test_ft_memmove_large_size(void)
{
	size_t	n;
	char	*src;
	char	*dest_std;
	char	*dest_custom;

	n = 1024;
	src = malloc(n + 1);
	dest_std = malloc(n + 1);
	dest_custom = malloc(n + 1);
	if (!src || !dest_std || !dest_custom)
	{
		assert_eq(1, 0);
		return ;
	}
	memset(src, 'E', n);
	src[n] = '\0';
	memset(dest_std, 'D', n);
	dest_std[n] = '\0';
	memset(dest_custom, 'D', n);
	dest_custom[n] = '\0';
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, n);
	asser_cmp_buf(&dest_std[n], &dest_custom[n], 1);
	free(src);
	free(dest_std);
	free(dest_custom);
}

// Test de memmove avec des appels multiples sur le même buffer.
void	test_ft_memmove_multiple_calls(void)
{
	char	buffer_std[30] = "FirstHelloWorld";
	char	buffer_custom[30] = "FirstHelloWorld";
	size_t	n1;
	size_t	n2;

	n1 = 5;
	n2 = 5;
	memmove(buffer_std + 5, buffer_std, n1);
	ft_memmove(buffer_custom + 5, buffer_custom, n1);
	memmove(buffer_std + 10, buffer_std + 5, n2);
	ft_memmove(buffer_custom + 10, buffer_custom + 5, n2);
	asser_cmp_buf(buffer_std, buffer_custom, 15);
	asser_cmp_buf(&buffer_std[15], &buffer_custom[15], 15);
}

// Test de memmove où src et dest sont identiques (aucune copie).
void	test_ft_memmove_same_src_dest(void)
{
	char	buffer_std[10] = "SameSrc";
	char	buffer_custom[10] = "SameSrc";
	size_t	n;

	n = 7;
	memmove(buffer_std, buffer_std, n);
	ft_memmove(buffer_custom, buffer_custom, n);
	asser_cmp_buf(buffer_std, buffer_custom, n);
	asser_cmp_buf(&buffer_std[n], &buffer_custom[n], 1);
}

// Test de memmove avec des caractères nulls dans la source.
void	test_ft_memmove_null_bytes(void)
{
	char	src[] = "Hello\0World";
	char	dest_std[20];
	char	dest_custom[20];
	size_t	n;

	n = 11;
	memset(dest_std, 'A', 19);
	dest_std[19] = '\0';
	memset(dest_custom, 'A', 19);
	dest_custom[19] = '\0';
	memmove(dest_std, src, n);
	ft_memmove(dest_custom, src, n);
	asser_cmp_buf(dest_std, dest_custom, n);
	asser_cmp_buf(&dest_std[n], &dest_custom[n], 9);
}

int	main(void)
{
	run_test(test_ft_memmove_basic, "ft_memmove_basic");
	run_test(test_ft_memmove_overlap_dest_after_src,
		"ft_memmove_overlap_dest_after_src");
	run_test(test_ft_memmove_overlap_dest_before_src,
		"ft_memmove_overlap_dest_before_src");
	run_test(test_ft_memmove_zero_size, "ft_memmove_zero_size");
	run_test(test_ft_memmove_truncate, "ft_memmove_truncate");
	run_test(test_ft_memmove_exact_size, "ft_memmove_exact_size");
	run_test(test_ft_memmove_large_size, "ft_memmove_large_size");
	run_test(test_ft_memmove_multiple_calls, "ft_memmove_multiple_calls");
	run_test(test_ft_memmove_same_src_dest, "ft_memmove_same_src_dest");
	run_test(test_ft_memmove_null_bytes, "ft_memmove_null_bytes");
	return (0);
}
 */