/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:51:34 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/23 11:43:05 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	res_handler(int signum)
{
	(void)signum;
	g_res = 1;
}

static void	send_signal(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		while (!g_res)
			pause();
		g_res = 0;
	}
}

int	main(int ac, char **av)
{
	unsigned int	i;
	pid_t			pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", av[0]);
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid < 1 || kill(pid, 0))
	{
		ft_printf("<server_pid> is invalid\n", av[0]);
		return (1);
	}
	signal(SIGUSR1, res_handler);
	while (av[2][i])
	{
		send_signal(pid, av[2][i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
