/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:00:43 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 11:57:49 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	unlink_semaphores(void)
{
	sem_unlink(DEATH_SEM);
	sem_unlink(EAT_SEM);
	sem_unlink(START_SEM);
	sem_unlink(SLEEP_SEM);
	sem_unlink(OUT_SEM);
	return (true);
}

t_b	destroy_sems(t_data *d, int nbr_to_del)
{
	int	i;

	i = 0;
	while (i < nbr_to_del)
	{
		if (i == 0)
			sem_close(d->i.death_sem);
		if (i == 1)
			sem_close(d->i.eat_sem);
		if (i == 2)
			sem_close(d->i.start_sem);
		if (i == 3)
			sem_close(d->i.sleep_sem);
		if (i == 4)
			sem_close(d->i.out_sem);
		i++;
	}
	return (true);
}

void	close_semaphores(t_data *d)
{
	sem_close(d->i.forks);
	sem_close(d->i.death_sem);
	sem_close(d->i.eat_sem);
	sem_close(d->i.sleep_sem);
	sem_close(d->i.out_sem);
	sem_close(d->i.start_sem);
	return ;
}
