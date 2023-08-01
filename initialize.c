/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:48:10 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/25 13:36:51 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_var *vars, t_philo **philo)
{
	int	i;

	vars->forks = (pthread_mutex_t *) malloc \
				(sizeof(pthread_mutex_t) * vars->nb_philo + 1);
	if (!vars->forks)
		return ;
	vars->philosophers = (pthread_t *) malloc \
				(sizeof(pthread_t) * vars->nb_philo + 1);
	if (!vars->philosophers)
		return ;
	i = -1;
	while (++i < vars->nb_philo)
	{
		philo[i] = (t_philo *) malloc (sizeof(t_philo) * vars->nb_philo + 1);
		if (!philo[i])
			return ;
		philo[i]->vars = vars;
		philo[i]->philo_id = i;
		if (pthread_create(&vars->philosophers[i], NULL, thread_exec, philo[i]) != 0)
			return ;
		pthread_mutex_init(&vars->forks[i], NULL);
	}
}
 