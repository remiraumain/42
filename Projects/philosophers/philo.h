/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:51:37 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/20 21:36:39 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "struct.h"
# include "utils/utils.h"


int	parse(int ac, char **av, t_data *data);
int	init(t_data *data);

#endif