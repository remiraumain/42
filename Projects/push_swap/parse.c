/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:11:09 by rraumain          #+#    #+#             */
/*   Updated: 2024/12/16 10:38:49 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_args(char	***args)
{
	char	**start;

	start = *args;
	while (**args)
	{
		free(**args);
		(*args)++;
	}
	free(start);
}

static int	init_stack(char **args, t_stack **a)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (args[i])
	{
		if (!is_arg_valid(args[i]))
			return (0);
		new = stack_new(ft_atoi(args[i]));
		if (!new)
			return (0);
		stack_add_back(a, new);
		i++;
	}
	return (1);
}

static char	**multiargs_split(int argc, char **argv)
{
	char	*concat_s;
	char	*temp;
	int		i;
	char	**args;

	i = 1;
	concat_s = ft_strdup("");
	if (!concat_s)
		return (NULL);
	while (i < argc)
	{
		temp = concat_s;
		concat_s = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!concat_s)
			return (NULL);
		i++;
	}
	args = ft_split(concat_s, ' ');
	free(concat_s);
	concat_s = NULL;
	return (args);
}

char	**set_args(int argc, char **argv)
{
	char	**args;

	if (argc > 2)
		args = multiargs_split(argc, argv);
	else
		args = ft_split(argv[1], ' ');
	return (args);
}

int	parse(int argc, char **argv, t_stack **a)
{
	char	**args;

	if (argc < 2)
		return (0);
	args = set_args(argc, argv);
	if (!args)
		return (0);
	if (!init_stack(args, a))
	{
		free_args(&args);
		stack_clear(a);
		return (0);
	}
	if (has_dup(a))
	{
		free_args(&args);
		stack_clear(a);
		return (0);
	}
	free_args(&args);
	set_index(*a, stack_size(*a));
	return (1);
}
