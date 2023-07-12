/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:35:39 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/11 19:34:00 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_philo *philo, t_var vars)
{
	int				i;
	pthread_mutex_t	*mutex;
	pthread_t		*thread;

	mutex = (pthread_mutex_t *) malloc \
				(sizeof(pthread_mutex_t) * vars.nb_philo + 1);
	if (!mutex)
		return ;
	thread = (pthread_t *) malloc \
				(sizeof(pthread_t) * vars.nb_philo + 1);
	if (!philo)
		return ;
	i = -1;
	while (++i < vars.nb_philo)
	{
		thread[i] = philo->num++;
		if (pthread_create(philo->num, NULL, thread_exec(&vars), &vars) != 0)
			return ;
		pthread_mutex_init(&mutex, NULL);
	}
}
