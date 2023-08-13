/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:07:38 by ehouot            #+#    #+#             */
/*   Updated: 2023/08/08 00:51:56 by ehouot           ###   ########.fr       */
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
	int				eaters_count;
	int				nb_philo;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	int				nb_x_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	start;
	pthread_mutex_t	add_count;
	long long 		begin_time;
	pthread_t		watcher;
	struct s_philo	*philo;
}				t_var;

typedef struct	s_philo
{
	struct s_var	*vars;
	int				philo_id;
	int				eat_count;
	long long		last_meal_time;
	pthread_t		philosopher;
}				t_philo;

/* -- LIBFT -- */

int		ft_isdigit(int c);
int		ft_atoi(const char *str);

/* -- PHILO -- */

t_var		*parsing(int argc, char **argv);
long long	realtime();
long long	get_time();
int			init_mutex(t_var *vars);
bool		init_philo(t_var *vars);
void		*thread_exec(void *vars);
void    	*watcher(void *arg);

#endif