/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:11:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/10 14:56:45 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char	***args)
{
	char **start;

	start = *args;
	while (**args)
	{
		free(**args);
		(*args)++;	
	}
	free(start);
}

static int	is_arg_valid(char *arg)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (arg[i])
	{
		if (arg[i] == '-' || arg[i] == '+')
		{
			if (sign)
				return (0);
			sign++;
		}
		else if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	init_stack(char **args, t_stack **a)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_arg_valid(args[i]))
		{
			free_split(&args);
			stack_clear(a);
			return (0);
		}
		new = stack_new(ft_atoi(args[i]));
		if (!new)
		{
			free_split(&args);
			stack_clear(a);
			return (0);
		}		
		stack_add_back(a, new);
		i++;
	}

	return (1);
}

int	parse(int argc, char **argv, t_stack **a)
{
	char	**args;

	if (argc < 2)
		return (0);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (!init_stack(args, a))
		return (0);
	free_split(&args);
	return (1);
}
