/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:20:47 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/17 11:34:20 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Utils/testy/testy.h"
#include "../libft.h"
#include <string.h>
#include <stdlib.h>

/**
 * @brief Vérifie que le bloc de mémoire est entièrement initialisé à zéro.
 *
 * @param ptr Pointeur vers le début du bloc de mémoire.
 * @param size Taille du bloc de mémoire en octets.
 * @return int Retourne 1 si tous les octets sont zéro, sinon 0.
 */
int	is_memory_zeroed(void *ptr, size_t size)
{
	unsigned char *byte_ptr = (unsigned char *)ptr;
	for (size_t i = 0; i < size; i++)
	{
		if (byte_ptr[i] != 0)
			return (0);
	}
	return (1);
}

/**
 * @brief Test de base avec des allocations simples.
 */
void	test_ft_calloc_basic(void)
{
	size_t nmemb = 5;
	size_t size = sizeof(int);

	// Allocation avec la fonction standard calloc
	int *std_ptr = calloc(nmemb, size);
	// Allocation avec la fonction personnalisée ft_calloc
	int *custom_ptr = ft_calloc(nmemb, size);

	// Vérifie que les deux pointeurs sont soit non-NULL, soit NULL
	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		// Vérifie que la mémoire allouée est initialisée à zéro
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec une allocation de grande taille.
 */
void	test_ft_calloc_large(void)
{
	size_t nmemb = 1000;
	size_t size = sizeof(double);

	double *std_ptr = calloc(nmemb, size);
	double *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec nmemb = 0 et size > 0.
 */
void	test_ft_calloc_zero_elements(void)
{
	size_t nmemb = 0;
	size_t size = 10;

	void *std_ptr = calloc(nmemb, size);
	void *custom_ptr = ft_calloc(nmemb, size);

	// Selon la spécification, si nmemb ou size est zéro, calloc peut retourner NULL ou un pointeur unique
	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec nmemb > 0 et size = 0.
 */
void	test_ft_calloc_zero_size(void)
{
	size_t nmemb = 10;
	size_t size = 0;

	void *std_ptr = calloc(nmemb, size);
	void *custom_ptr = ft_calloc(nmemb, size);

	// Selon la spécification, si nmemb ou size est zéro, calloc peut retourner NULL ou un pointeur unique
	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec nmemb = 0 et size = 0.
 */
void	test_ft_calloc_zero_elements_and_size(void)
{
	size_t nmemb = 0;
	size_t size = 0;

	void *std_ptr = calloc(nmemb, size);
	void *custom_ptr = ft_calloc(nmemb, size);

	// Selon la spécification, si nmemb ou size est zéro, calloc peut retourner NULL ou un pointeur unique
	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test pour vérifier que la mémoire allouée est correctement initialisée à zéro.
 */
void	test_ft_calloc_memory_zeroed(void)
{
	size_t nmemb = 20;
	size_t size = sizeof(char);

	char *std_ptr = calloc(nmemb, size);
	char *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec une allocation très grande pour vérifier la gestion des grandes tailles.
 */
void	test_ft_calloc_large_allocation(void)
{
	size_t nmemb = 1000000;
	size_t size = sizeof(long);

	long *std_ptr = calloc(nmemb, size);
	long *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec des types de données différents pour assurer la polyvalence de ft_calloc.
 */
void	test_ft_calloc_different_types(void)
{
	// Allocation pour un tableau de structures
	typedef struct s_example
	{
		int	a;
		float	b;
		char	c;
	}	t_example;

	size_t nmemb = 10;
	size_t size = sizeof(t_example);

	t_example *std_ptr = calloc(nmemb, size);
	t_example *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec des données binaires pour vérifier la gestion correcte de l'allocation et de l'initialisation.
 */
void	test_ft_calloc_binary_data(void)
{
	size_t nmemb = 256;
	size_t size = sizeof(unsigned char);

	unsigned char *std_ptr = calloc(nmemb, size);
	unsigned char *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));
	}

	free(std_ptr);
	free(custom_ptr);
}

/**
 * @brief Test avec des allocations consécutives pour vérifier qu'elles ne se chevauchent pas.
 */
void	test_ft_calloc_consecutive_allocations(void)
{
	size_t nmemb = 50;
	size_t size = sizeof(double);

	double *std_ptr1 = calloc(nmemb, size);
	double *custom_ptr1 = ft_calloc(nmemb, size);

	double *std_ptr2 = calloc(nmemb, size);
	double *custom_ptr2 = ft_calloc(nmemb, size);

	// Vérifie que toutes les allocations ont réussi ou ont échoué de manière cohérente
	assert_eq((std_ptr1 != NULL && std_ptr2 != NULL) || (std_ptr1 == NULL && std_ptr2 == NULL),
	          (custom_ptr1 != NULL && custom_ptr2 != NULL) || (custom_ptr1 == NULL && custom_ptr2 == NULL));

	if (std_ptr1 != NULL && std_ptr2 != NULL && custom_ptr1 != NULL && custom_ptr2 != NULL)
	{
		// Vérifie que chaque bloc est initialisé à zéro
		assert_eq(is_memory_zeroed(std_ptr1, nmemb * size), is_memory_zeroed(custom_ptr1, nmemb * size));
		assert_eq(is_memory_zeroed(std_ptr2, nmemb * size), is_memory_zeroed(custom_ptr2, nmemb * size));
	}

	free(std_ptr1);
	free(std_ptr2);
	free(custom_ptr1);
	free(custom_ptr2);
}

/**
 * @brief Test avec des chaînes de caractères pour vérifier l'allocation et l'initialisation.
 */
void	test_ft_calloc_strings(void)
{
	size_t nmemb = 100;
	size_t size = sizeof(char);

	char *std_ptr = calloc(nmemb, size);
	char *custom_ptr = ft_calloc(nmemb, size);

	assert_eq((std_ptr != NULL), (custom_ptr != NULL));

	if (std_ptr != NULL && custom_ptr != NULL)
	{
		assert_eq(is_memory_zeroed(std_ptr, nmemb * size), is_memory_zeroed(custom_ptr, nmemb * size));

		// Exemple de manipulation: assigner une chaîne et vérifier
		strcpy(std_ptr, "Hello, World!");
		strcpy(custom_ptr, "Hello, World!");

		assert_eq(strcmp(std_ptr, custom_ptr), 0);
	}

	free(std_ptr);
	free(custom_ptr);
}

// int	main(void)
// {
// 	run_test(test_ft_calloc_basic, "ft_calloc_basic");
// 	run_test(test_ft_calloc_large, "ft_calloc_large");
// 	run_test(test_ft_calloc_zero_elements, "ft_calloc_zero_elements");
// 	run_test(test_ft_calloc_zero_size, "ft_calloc_zero_size");
// 	run_test(test_ft_calloc_zero_elements_and_size, "ft_calloc_zero_elements_and_size");
// 	run_test(test_ft_calloc_memory_zeroed, "ft_calloc_memory_zeroed");
// 	run_test(test_ft_calloc_large_allocation, "ft_calloc_large_allocation");
// 	run_test(test_ft_calloc_different_types, "ft_calloc_different_types");
// 	run_test(test_ft_calloc_binary_data, "ft_calloc_binary_data");
// 	run_test(test_ft_calloc_consecutive_allocations, "ft_calloc_consecutive_allocations");
// 	run_test(test_ft_calloc_strings, "ft_calloc_strings");
// 	return (0);
// }