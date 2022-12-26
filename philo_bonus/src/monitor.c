/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:50:16 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 14:00:02 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	can_continue(t_data *d)
{
	time_t	ms;

	ms = elapsed_ms();
	if (d->i.satiated_philos == d->i.philo_nbr)
		exit(EXIT_SUCCESS);
	sem_wait(d->i.death_sem);
	if (d->ph.time_of_starvation < ms)
	{
		printf("d->ph.time_of_starvation %lu < ms %lu \n\n", d->ph.time_of_starvation, ms);
		printf("satiated_philos %d \n\n", d->i.satiated_philos);
		outlog(d, "died");
		exit(EXIT_SUCCESS);
	}
	sem_post(d->i.death_sem);
	return (true);
}

void	*monitor(void *arg)
{
	int		i;
	t_data	*d;

	d = (t_data *) arg;
	while (42)
	{
		i = 0;
		while (i < d->i.philo_nbr)
		{
			if (!can_continue(d))
			{
				kill_processes(d, d->i.philo_nbr);
				exit(EXIT_SUCCESS);
				pthread_detach(d->th);
				printf("reached \n");
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
