/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:48:23 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/23 11:43:40 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_philo *philo, char *action, int id)
{
	long long	time;

	pthread_mutex_lock(&philo->vars->print);
	time = get_time() - philo->vars->begin_time;
	if (ft_strncmp(action, "think", 6) == 0)
		printf("%lld : %d is thinking\n", time, id);
	else if (ft_strncmp(action, "fork", 5) == 0)
		printf("%lld : %d has taken a fork\n", time, id);
	else if (strncmp(action, "eat", 4) == 0)
		printf("%lld : %d is eating\n", time, id);
	else if (ft_strncmp(action, "sleep", 6) == 0)
		printf("%lld : %d is sleeping\n", time, id);
	else if (ft_strncmp(action, "die", 4) == 0)
	{
		printf("%lld : %d died\n", time, id);
		return ;
	}
	pthread_mutex_unlock(&philo->vars->print);
}

static void	increment_eater(t_philo *philo)
{
	if (philo->vars->nb_x_eat == philo->eat_count)
	{
		pthread_mutex_lock(&philo->vars->add_count);
		philo->vars->eaters_count++;
		pthread_mutex_unlock(&philo->vars->add_count);
	}
}

static void	eat(t_philo *philo, int left_fork, int right_fork)
{
	increment_eater(philo);
	pthread_mutex_lock(&philo->vars->forks[right_fork]);
	print_action(philo, "fork", philo->philo_id);
	pthread_mutex_lock(&philo->vars->forks[left_fork]);
	print_action(philo, "fork", philo->philo_id);
	print_action(philo, "eat", philo->philo_id);
	pthread_mutex_lock(&philo->vars->check_meals);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->vars->check_meals);
	philo->eat_count++;
	ft_usleep(philo->vars->eat_time);
	pthread_mutex_unlock(&philo->vars->forks[left_fork]);
	pthread_mutex_unlock(&philo->vars->forks[right_fork]);
}

void	*thread_exec(void *arg)
{
	int		left_fork;
	int		right_fork;
	t_philo	*philo;

	philo = (t_philo *)arg;
	left_fork = philo->philo_id;
	right_fork = (philo->philo_id + 1) % philo->vars->nb_philo;
	if (philo->philo_id % 2 == 0)
		ft_usleep(philo->vars->eat_time / 2);
	while (1)
	{
		eat(philo, left_fork, right_fork);
		print_action(philo, "sleep", philo->philo_id);
		ft_usleep(philo->vars->sleep_time);
		print_action(philo, "think", philo->philo_id);
	}
	return (NULL);
}
