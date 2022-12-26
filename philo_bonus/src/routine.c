/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 07:31:05 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 09:15:15 by rkanmado         ###   ########.fr       */
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
		d->philos[i].id = i;
		d->philos[i].pid = fork();
		if (d->philos[i].pid == 0)
			routine(d, i);
		i++;
	}
	sem_post(d->i.start_sem);
	return (true);
}

t_b	take_forks(t_data *d, int i)
{
	sem_wait(d->forks);
	d->philos[i].is_lf_taken = true;
	outlog(&d->philos[i], "has taken left fork");
	sem_wait(d->forks);
	d->philos[i].is_rf_taken = true;
	outlog(&d->philos[i], "has taken right fork");
	return (true);
}


void	routine(t_data *d, int i)
{
	// init_child_semaphores(d);
	while (can_continue(&d->philos[i]))
	{
		thinking_event(d, i);
		take_forks(d, i);
		eating_event(d, i);
		drop_forks(d, i);
		sleeping_event(d, i);
	}
	return ;
}
