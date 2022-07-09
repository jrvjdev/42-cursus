#include "../includes/philo.h"

void	*_info(void)
{
	static t_info	info;

	return (&info);
}

static void	init_philo(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		info->philos[i].index = i;
		info->philos[i].t_last_meal = 0;
		info->philos[i].n_meal = 0;
		info->philos[i].f1 = &info->forks[i];
		info->philos[i].f2 = &info->forks[(i + 1) % info->number_of_philosophers];
		i++;
	}
}

void	init_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		info->forks[i].mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(info->forks[i].mutex, NULL);
		info->forks[i].index = i;
		i++;
	}
}

void	init_args(char **av)
{
	t_info	*info;
	int		n;

	n = 3; // n = ft_atoi(ag[1]);
	info = _info();
	info->number_of_philosophers = n;
	info->time_to_die = 300;
	info->time_to_eat = 200 * 1000; //milisecond conversion
	info->time_to_sleep = 100 * 1000; //milisecond conversion
	info->number_of_time_each_philosopher_must_eat = 0; //if no arg[5]

	info->forks = malloc(sizeof(t_fork) * n);
	info->philos = malloc(sizeof(t_philo) * n);
	info->threads = malloc(sizeof(pthread_t) * n);

	init_forks(info);
	init_philo(info);

}
