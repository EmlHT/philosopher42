/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 14:55:28 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/17 16:18:25 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_free(t_var *vars)
{
    int i;

    i = -1;
    while (++i < vars->nb_philo)
    {
        pthread_mutex_destroy(&vars->forks[i]);
        free(&vars->philo[i]);
    }
    free(&vars->philo);
    pthread_mutex_destroy(&vars->print);
    pthread_mutex_destroy(&vars->add_count);
}