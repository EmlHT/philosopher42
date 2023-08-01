/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:05:25 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/25 15:42:21 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long realtime()
{
	long long time_since;
	struct	timeval	tv;
	
	gettimeofday(&tv, NULL);
	time_since = (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
	return (time_since);
}

int	main(int argc, char **argv)
{
	int				res;
	t_var			vars;
	t_philo			**philo;
	
	res = parsing(argc, argv, &vars);
	if (res != 0)
		return (0);
	vars.time_since = realtime();
	philo = (t_philo **) malloc (sizeof(t_philo *) * vars.nb_philo);
	if (!philo)
		return (0);
	
	initialize(&vars, philo);
	return (0);
}
