/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:07:18 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/25 14:33:19 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv, t_var *vars)
{
	int		i;
	int		j;
	int		*tmp;

	i = 0;
	j = -1;
	vars->eat_count = -1;
	tmp = malloc (sizeof(int) * argc - 1);
	if (!tmp)
		return (write(2, "Allocation problem", 19));
	if (argc != 5 && argc != 6)
		return (write(2, "Wrong nb of args", 17));
	while (argv[++i])
	{
		tmp[++j] = ft_atoi(argv[i]);
		if (tmp[j] == -1)
			return (write(2, "Argument problem", 17));
	}
	vars->nb_philo = tmp[0];
	vars->die_time = tmp[1];
	vars->eat_time = tmp[2];
	vars->sleep_time = tmp[3];
	if (tmp[4])
	{
		vars->eat_count = 0;
		vars->nb_x_eat = tmp[4];
	}
	return (0);
}
