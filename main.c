/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:05:25 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/08 00:35:26 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*vars;

	vars = NULL;
	vars = parsing(argc, argv);
	if (!vars)
		return (EXIT_FAILURE);
	if (init_philo(vars) != true)
		return (EXIT_FAILURE);
	// philo = (t_philo **) malloc (sizeof(t_philo *) * vars.nb_philo);
	// initialize(vars, philo);
	return (EXIT_SUCCESS);
}
