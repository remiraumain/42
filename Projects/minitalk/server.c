/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:51:36 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/18 06:52:15 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*convert_uchar(unsigned char c)
{
	char	*s;

	s = malloc(sizeof(char) + 1);
	if (!s)
		return (NULL);
	s[0] = (char)c;
	s[1] = '\0';
	return (s);
}

static void	clear_memory(int stop_process)
{
	if (g_sigbyte.string)
		free(g_sigbyte.string);
	g_sigbyte.string = NULL;
	g_sigbyte.byte = 0;
	g_sigbyte.count = 0;
	if (stop_process)
		exit(1);
}

static int	add_to_string(unsigned char c)
{
	char	*new;
	char	*tmp;

	new = convert_uchar(c);
	if (!new)
		return (0);
	tmp = g_sigbyte.string;
	g_sigbyte.string = ft_strjoin(g_sigbyte.string, new);
	free(new);
	new = NULL;
	free(tmp);
	tmp = NULL;
	if (!g_sigbyte.string)
		return (0);
	return (1);
}

static void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (!g_sigbyte.string)
		g_sigbyte.string = ft_strdup("");
	if (!g_sigbyte.string)
		exit(1);
	if (signum == SIGUSR1)
		g_sigbyte.byte = g_sigbyte.byte << 1;
	else if (signum == SIGUSR2)
		g_sigbyte.byte = g_sigbyte.byte << 1 | 1;
	g_sigbyte.count++;
	if (g_sigbyte.count == 8)
	{
		if (!add_to_string(g_sigbyte.byte))
			clear_memory(1);
		if (g_sigbyte.byte == '\0')
		{
			ft_printf("%s\n", g_sigbyte.string);
			clear_memory(0);
		}
		g_sigbyte.count = 0;
		g_sigbyte.byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	signal_action;

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
