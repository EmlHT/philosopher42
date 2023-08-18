/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:06:28 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/18 17:22:47 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool    watcher(t_var *vars)
{
	int i;

	i = 0;
	pthread_mutex_lock(&vars->add_count);
    while (vars->eaters_count != vars->nb_philo)
	{
		pthread_mutex_unlock(&vars->add_count);
		if (i >= vars->nb_philo - 1)
			i = 0;
		pthread_mutex_lock(&vars->check_meals);
		if (get_time() - vars->philo[i].last_meal_time >= vars->die_time)
		{
			
			print_action(vars->philo, "die", i);
			return (true);
		}
		pthread_mutex_unlock(&vars->check_meals);
		i++;
		pthread_mutex_lock(&vars->add_count);
	}
	pthread_mutex_unlock(&vars->add_count);
	return (true);
}
