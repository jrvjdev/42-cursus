#include "../includes/philo.h"

void	_eat(t_philo *philo)
{
	pretty_print(philo, "EATING");
	pthread_mutex_lock(philo->f1->mutex);
	pthread_mutex_lock(philo->f2->mutex);

	usleep(_info()->time_to_sleep);
	philo->t_last_meal = gettimeofday_ms();
	philo->n_meal++;
	pthread_mutex_unlock(philo->f1->mutex);
	pthread_mutex_unlock(philo->f2->mutex);
	pretty_print(philo, "FINISHED");

}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("hello philo %d| with forks (%d, %d)\n", philo->index, philo->f1->index, philo->f2->index);
	for (int i = 0; i < 3; i++)
	{
		_eat(philo);
		// _sleep(philo);
		// _repeat(philo);
	}
	return (0);
}

int	init_threads(void)
{
	int		i;
	t_info	*info;

	info = _info();
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_create(&info->threads[i], NULL, &routine, &info->philos[i]) != 0)
		{
			perror("ERROR in creating threads- init_threads\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < info->number_of_philosophers)
	{
		if (pthread_join(info->threads[i], NULL) != 0)
		{
			perror("ERROR in joining threads- init_threads\n");
			return (0);
		}
		i++;
	}
	return (1);
}