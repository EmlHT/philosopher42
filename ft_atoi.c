/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 11:20:45 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/03 17:22:43 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	i;
	unsigned int	nb;

	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
	{
		if ((str[i + 1] == '\0'))
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (nb > 2147483647)
		return (-1);
	return ((int)nb);
}
