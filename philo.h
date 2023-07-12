/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:07:38 by ehouot            #+#    #+#             */
/*   Updated: 2023/07/11 18:50:40 by ehouot           ###   ########.fr       */
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
	int	nb_philo;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	nb_x_eat;
}				t_var;

typedef struct s_philo
{
	pthread_t	num;
	t_var		vars;
}				t_philo;

/* -- LIBFT -- */

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	initialize(t_philo *philo, t_var vars);
void	*thread_exec(void *arg);

/* -- PIPEX -- */

int		main(int argc, char **argv, char **envp);
int		parsing(int argc, char **argv, t_var *vars);

#endif