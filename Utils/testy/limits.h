/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:09:16 by rraumain          #+#    #+#             */
/*   Updated: 2024/10/11 11:09:16 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTY_LIMITS_H
# define TESTY_LIMITS_H

/**
 * @brief Defines the max value for int.
 * @note todo: This functions only on 32bit system. Need to find a better alternative.
 */
# ifndef MAX_INT
#  define MAX_INT 2147483647
# endif

/**
 * @brief Defines the min value for int.
 * @note Todo: This functions only on 32bit system. Need to find a better alternative.
 */
# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

#endif