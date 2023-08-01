/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:48:23 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/25 14:51:43 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
	struct timeval time;
	long long actual_time;

	gettimeofday(&time, NULL);
	actual_time = (long long)time.tv_sec * 1000LL + (long long)time.tv_usec / 1000LL;
	return (actual_time);
}

void	*thread_exec(void *arg)
{
	// long long	timer;
	// long long	current_time;
	int 		left_fork;
    int 		right_fork;
	int 		philo_id;
	t_var *vars;

	//timer = get_time();
	t_philo *philo = (t_philo *)arg;
    vars = philo->vars;
    philo_id = philo->philo_id;
	left_fork = philo_id;
	right_fork = (philo_id + 1) % vars->nb_philo;
	while (1)
	{
		if (vars->philo_id % 2 == 0)
			usleep(vars->eat_time);
		printf("%lld : philo n°%d is thinking\n", get_time() - vars->time_since, philo_id);
		if (vars->nb_x_eat == vars->eat_count)
			break;
		pthread_mutex_lock(&vars->forks[left_fork]);
		pthread_mutex_lock(&vars->forks[right_fork]);
		printf("%lld : philo n°%d has taken a fork\n", get_time() - vars->time_since, philo_id);
		printf("%lld : philo n°%d has taken a fork\n", get_time() - vars->time_since, philo_id);
		printf("%lld : philo n°%d is eating\n", get_time() - vars->time_since, philo_id);
		vars->eat_count++;
		usleep(vars->eat_time);
		// timer = get_time();
		pthread_mutex_unlock(&vars->forks[left_fork]);
		pthread_mutex_unlock(&vars->forks[right_fork]); 
		printf("%lld : philo n°%d is sleeping\n", get_time() - vars->time_since, philo_id);
		usleep(vars->sleep_time);
		// current_time = get_time();
		// if (current_time - timer >= vars->die_time)
		// {
		// 	printf("%lld : philo n°%d died\n", get_time() - vars->time_since, philo_id);
		// 	return (NULL);
		// } WATCHER DANS LE MAIN
	}
	return (NULL);
}
