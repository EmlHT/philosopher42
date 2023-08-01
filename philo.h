/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot < ehouot@student.42nice.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:07:38 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/25 14:20:56 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_var
{
	int				nb_philo;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				nb_x_eat;
	int				philo_id;
	int				eat_count;
	pthread_t		*philosophers;
	pthread_mutex_t	*forks;
	long long 		time_since;
}				t_var;

typedef struct	s_philo
{
	t_var	*vars;
	int		philo_id;
}				t_philo;

/* -- LIBFT -- */

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	initialize(t_var *vars, t_philo **philo);
void	*thread_exec(void *vars);

/* -- PHILO -- */

int		parsing(int argc, char **argv, t_var *vars);

#endif