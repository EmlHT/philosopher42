/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:42:06 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/07 22:51:28 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long realtime()
{
	long long		begin_time;
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	begin_time = (long long)tv.tv_sec * 1000LL + (long long)tv.tv_usec / 1000LL;
	return (begin_time);
}

long long get_time()
{
	struct timeval	time;
	long long 		actual_time;

	gettimeofday(&time, NULL);
	actual_time = (long long)time.tv_sec * 1000LL + (long long)time.tv_usec / 1000LL;
	return (actual_time);
}