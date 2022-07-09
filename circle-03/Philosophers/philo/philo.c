/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: V <V@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:53:11 by joaribei          #+#    #+#             */
/*   Updated: 2022/07/09 19:18:28 by V                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


int	main(int ac, char **av)
{
	/*1 vaidate args */
	/*2 initialize*/ init_args(av);
	/*3 threads routine*/ init_threads();
	/*4 free and exit (mutext destroy)*/

	print_info();
}
