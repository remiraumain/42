/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:08:06 by rraumain          #+#    #+#             */
/*   Updated: 2025/01/26 14:17:18 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

static void	del_cmd(char **file)
{
	unsigned int	i;

	i = 0;
	while (file[i])
	{
		free(file[i]);
		file[i] = NULL;
		i++;
	}
	free(file);
	file = NULL;
}

void	clear_data(t_pipex *data)
{
	if (data->infile != NULL)
		data->infile = NULL;
	if (data->outfile != NULL)
		data->outfile = NULL;
	if (data->cmd1 != NULL)
		del_cmd(data->cmd1);
	if (data->cmd2 != NULL)
		del_cmd(data->cmd2);
}