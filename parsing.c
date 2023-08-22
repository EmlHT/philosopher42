/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:07:18 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/22 16:10:22 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void fill_vars(int argc, char **argv, t_var *vars)
{
	vars->eaters_count = -1;
	vars->begin_time = get_time();
	vars->nb_philo = ft_atoi(argv[1]);
	vars->die_time = ft_atoi(argv[2]);
	vars->eat_time = ft_atoi(argv[3]);
	vars->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		vars->eaters_count = 0;
		vars->nb_x_eat = ft_atoi(argv[5]);
	}
}

static int	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong nb of args\n", 18));
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) == -1)
			return (write(2, "Argument problem\n", 18));
	}
	return (0);
}

t_var	*parsing(int argc, char **argv)
{
	t_var	*vars;

	if (check_args(argc, argv) != 0)
		return (NULL);
	vars = malloc (sizeof(t_var));
	if (!vars)
		return (NULL);
	fill_vars(argc, argv, vars);
	if (init_mutex(vars) != 0)
		return (NULL);
	return (vars);
}
