/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 12:23:36 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/22 17:12:40 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool init_forks(t_var *vars)
{
    int i;

    vars->forks = malloc (sizeof(pthread_mutex_t) * vars->nb_philo);
    if (!vars->forks)
        return (false);
    i = -1;
	while (++i < vars->nb_philo)
	{
		if (pthread_mutex_init(&vars->forks[i], NULL) != 0)
            return (false);
	}
    return (true);
}

int init_mutex(t_var *vars)
{
    if (pthread_mutex_init(&vars->check_meals, NULL))
        return (-1);
    if (pthread_mutex_init(&vars->print, NULL))
        return (-1);
    if (pthread_mutex_init(&vars->add_count, NULL))
        return (-1);
    if (init_forks(vars) != true)
        return (-1);
    return (0);
}
