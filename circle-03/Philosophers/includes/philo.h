/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:49:49 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 18:27:37 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# include <pthread.h>
# include <sys/time.h>

typedef struct	s_fork
{
	int				index;
	pthread_mutex_t	*mutex;
}				t_fork;


typedef struct s_philo
{
	int				index;
	int				n_meal; //number of meals
	long int		t_last_meal; //time last meal
	t_fork			*f1;
	t_fork			*f2;
	//probably status
	// pthread_mutex_t	*slf;
}					t_philo;

typedef struct	s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_time_each_philosopher_must_eat;

	t_philo			*philos;
	t_fork			*forks;
	pthread_mutex_t	slf;
	pthread_t		*threads;
}				t_info;

//inits
void	init_args(char **av);
void	*_info(void);

//thread
int	init_threads(void);

//time
uint64_t	gettimeofday_ms(void);
uint64_t	time_since_start(void);


//print
void	print_info(void);

#endif
