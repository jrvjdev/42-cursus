#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("hello philo %d| with forks (%d, %d)\n", philo->index, philo->f1->index, philo->f2->index);
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