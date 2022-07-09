#include "../includes/philo.h"

void	print_info(void)
{
	t_info	*info;

	info = _info();
	printf("Time to eat:%d sleep:%d die:%d times:%d (%d)\n", info->time_to_eat, info->time_to_sleep, info->time_to_die, info->number_of_time_each_philosopher_must_eat, info->number_of_philosophers);
}