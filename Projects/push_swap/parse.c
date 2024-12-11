/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:11:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/11 10:30:33 by rraumain         ###   ########.fr       */
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

static int	check_size(char *s)
{
	int	len;
	int	sign;

	sign = 0;
	len = ft_strlen(s);
	if (s[0] == '-' || s[0] == '+')
	{
		len--;
		sign++;
	}
	if (len > 10 || len < 1)
		return (0);
	if (len < 10)
		return (1);
	if (s[0 + sign] > '2' 
	|| (s[0 + sign] == '2' && s[len + sign - 1] > '7' && s[0] != '-'))
		return (0);
	if (s[0 + sign] > '2' 
	|| (s[0 + sign] == '2' && s[len + sign - 1] > '8' && s[0] == '-'))
		return (0);
	return (1);
}		

static int	is_arg_valid(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9') 
			&& !((arg[i] == '-' || arg[i] == '+') && i == 0))
			return (0);
		i++;
	}
	if (!check_size(arg))
		return (0);
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
	if (has_dup(a))
	{
		free_split(&args);
		stack_clear(a);
		return (0);
	}
	free_split(&args);
	return (1);
}
