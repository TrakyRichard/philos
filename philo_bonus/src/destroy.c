/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:08 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 08:45:58 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

t_b	drop_forks(t_data *d, int i)
{
	sem_post(d->forks);
	d->philos[i].is_rf_taken = false;
	outlog(&d->philos[i], "dropped the right fork");
	sem_post(d->forks);
	d->philos[i].is_lf_taken = false;
	outlog(&d->philos[i], "dropped the left fork");
	return (true);
}

t_b	kill_processes(t_data *d, int thread_nbr)
{
	int	i;

	i = 0;
	while (i < thread_nbr)
	{
		if (kill(d->philos[i++].pid, 9) != 0)
			return (false);
	}
	return (true);
}

void	close_semaphores(t_data *d)
{
	sem_close(d->forks);
	sem_close(d->i.death_sem);
	sem_close(d->i.eat_sem);
	sem_close(d->i.sleep_sem);
	sem_close(d->i.out_sem);
	sem_close(d->i.starv_sem);
	sem_close(d->i.start_sem);
	return ;
}

t_b	destroy_sems(t_data *d, int nbr_to_del)
{
	int	i;

	i = 0;
	while (i < nbr_to_del)
	{
		if (sem_close(d->i.death_sem) != 0 && i == 0)
			return (false);
		if (sem_close(d->i.eat_sem) != 0 && i == 1)
			return (false);
		if (sem_close(d->i.start_sem) != 0 && i == 2)
			return (false);
		if (sem_close(d->i.sleep_sem) != 0 && i == 3)
			return (false);
		if (sem_close(d->i.starv_sem) != 0 && i == 4)
			return (false);
		if (sem_close(d->i.out_sem) != 0 && i == 5)
			return (false);
		i++;
	}
	return (true);
}

t_b	unlink_semaphores(void)
{
	sem_unlink(DEATH_SEM);
	sem_unlink(EAT_SEM);
	sem_unlink(START_SEM);
	sem_unlink(SLEEP_SEM);
	sem_unlink(STARV_SEM);
	sem_unlink(OUT_SEM);
	return (true);
}

void	free_table(t_data *d)
{
	// free(d->forks);
	free(d->philos);
	unlink_semaphores();
	close_semaphores(d);
	destroy_sems(d, MUTEXES);
	return ;
}
