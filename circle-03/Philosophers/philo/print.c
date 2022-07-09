#include "../includes/philo.h"

void	print_info(void)
{
	t_info	*info;

	info = _info();
	printf("Time to eat:%d sleep:%d die:%d times:%d (%d)\n", info->time_to_eat, info->time_to_sleep, info->time_to_die, info->number_of_time_each_philosopher_must_eat, info->number_of_philosophers);
}

void	pretty_print(t_philo *philo, char *str)
{
	uint64_t	timestamp;

	timestamp = time_since_start();
	printf("%04lli\e[0;3%dm %d %s\e[0m\n", timestamp, philo->index, philo->index, str);
}