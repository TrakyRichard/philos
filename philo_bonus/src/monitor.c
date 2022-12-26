/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:50:16 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 09:16:29 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	can_continue(t_philo *ph)
{
	time_t	ms;

	ms = elapsed_ms();
	if (ph->i->satiated_philos == ph->i->philo_nbr)
		return (false);
	sem_wait(ph->i->death_sem);
	if (ph->time_of_starvation < ms)
	{
		outlog(ph, "died");
		// sem_post(ph->i->death_sem);
		return (false);
	}
	sem_post(ph->i->death_sem);
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
			if (!can_continue(&d->philos[i]))
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
