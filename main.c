/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:05:25 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/11 18:52:27 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv, char **envp)
{
	int		res;
	t_philo	*philo;
	t_var	*vars;

	(void)envp;
	(void)philo;
	vars = NULL;
	res = parsing(argc, argv, vars);
	if (res != 0)
		return (0);
	initialize(philo, *vars);
	return (0);
}
