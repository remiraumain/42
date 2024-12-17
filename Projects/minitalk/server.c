/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:51:36 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/17 16:00:13 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (signum == SIGUSR1)
		sigbyte.byte = sigbyte.byte << 1;
	else if (signum == SIGUSR2)
		sigbyte.byte = sigbyte.byte << 1 | 1;
	sigbyte.count++;
	// ft_printf("%d", sigbyte.count);
	// if (sigbyte.count == 8)
	// 	sigbyte.count = 0;
	if (sigbyte.count == 8)
	{
		ft_printf("%c", sigbyte.byte);
		if (sigbyte.byte == '\0')
			ft_printf("\n");
		sigbyte.count = 0;
		sigbyte.byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction signal_action;

	ft_printf("Server's PID: %d\n", getpid());

	signal_action.sa_sigaction = signal_handler;
	signal_action.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_action.sa_mask);
	sigaction(SIGUSR1, &signal_action, NULL);
	sigaction(SIGUSR2, &signal_action, NULL);
	while (1)
		pause();
	return (0);
}