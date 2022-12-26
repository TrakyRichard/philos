/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:50:16 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 12:12:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	can_continue(t_data *d)
{
	time_t	ms;

	ms = elapsed_ms();
	if (d->i.satiated_philos == d->i.philo_nbr)
		return (false);
	sem_wait(d->i.death_sem);
	if (d->ph.time_of_starvation < ms)
	{
		outlog(d, "died");
		return (false);
	}
	sem_post(d->i.death_sem);
	return (true);
}

void	monitor(t_data *d)
{
	int	i;

	while (42)
	{
		i = 0;
		while (i < d->i.philo_nbr)
		{
			if (!can_continue(d))
			{
				kill_processes(d, d->i.philo_nbr);
				printf("reached \n");
				return ;
			}
			i++;
		}
	}
	return ;
}
