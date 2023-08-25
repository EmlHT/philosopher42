/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:42:06 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/25 10:12:41 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (long long)time.tv_sec * 1000LL + \
		(long long)time.tv_usec / 1000LL;
	return (actual_time);
}

int	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(1000);
	return (0);
}
