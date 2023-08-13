/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:06:28 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/08 00:37:00 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *watcher(void *arg)
{
    t_var *vars;

	vars = (t_var *)arg;
    while(vars->eaters_count != vars->nb_philo || vars->)
	    if (current_time - timer >= vars->die_time)
	return ;
}
