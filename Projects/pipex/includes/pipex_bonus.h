/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:51:22 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/27 09:20:33 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	char	***cmds;
	int		argc;
}	t_pipex;

void	parse_arguments(int argc, char **argv, t_pipex *data);
int		create_pipe(int pipe_fd[2]);
void	close_and_wait(int pipe_fd[2]);
void	execute_child1(int pipe_fd[2], char **envp, t_pipex *data);
void	execute_child2(int pipe_fd[2], char **envp, t_pipex *data);
char	*get_command_path(char *cmd, char **envp);
void	clear_data(t_pipex *data);

#endif