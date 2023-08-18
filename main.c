/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:05:25 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/18 12:05:06 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*vars;

	vars = NULL;
	vars = parsing(argc, argv);
	if (!vars)
		return (-1);
	if (init_philo(vars) != true)
		return (-1);
	return (0);
}
