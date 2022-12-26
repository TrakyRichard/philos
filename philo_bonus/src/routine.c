/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 07:31:05 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 12:49:24 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	create_processes(t_data *d)
{
	int	i;

	i = 0;
	sem_wait(d->i.start_sem);
	while (i < d->i.philo_nbr)
	{
		d->ph.id = i;
		d->ph.pid = fork();
		d->pids[i] = d->ph.pid;
		if (d->ph.pid == 0)
			routine(d);
		i++;
	}
	sem_post(d->i.start_sem);
	return (true);
}

t_b	routine(t_data *d)
{
	while (42)
	{
		thinking_event(d);
		take_forks(d);
		eating_event(d);
		drop_forks(d);
		sleeping_event(d);
	}
	return (true);
}
