/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:08 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 10:15:16 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	error(void)
{
	usage();
	exit(EXIT_FAILURE);
}

void	usage(void)
{
	printf("Usage: ./philo \n number_of_philosophers \n time_to_die \
			\n time_to_eat time_to_sleep \n \
			[number_of_times_each_philosopher_must_eat]");
	return ;
}

void	err_msg(char *title, char *message)
{
	printf("%s: %s", title, message);
	exit(EXIT_FAILURE);
	return ;
}

void	outlog(t_data *d, char *mes)
{
	time_t	ms;

	sem_wait(d->i.out_sem);
	ms = elapsed_ms();
	printf("%lu: philo %d %s\n", ms, d->ph.id + 1, mes);
	sem_post(d->i.out_sem);
	return ;
}
