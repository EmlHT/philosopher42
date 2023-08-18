/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:39:25 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/18 17:23:13 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool init_philo(t_var *vars)
{
    int i;

    vars->philo = malloc (sizeof(t_philo) * vars->nb_philo);
	if (!vars->philo)
		return (false);
    i = -1;
	while (++i < vars->nb_philo)
	{
        vars->philo[i].philo_id = i;
		vars->philo[i].eat_count = 0;
		vars->philo[i].vars = vars;
		if (pthread_create(&vars->philo[i].philosopher, NULL, thread_exec, &vars->philo[i]) != 0)
			return (false);
	}
	watcher(vars);
    i = -1;
    return (true);
}
