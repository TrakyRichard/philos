/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:38 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 12:55:53 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	init(t_data *d)
{
	d->i.meal_required = -1;
	d->i.philo_nbr = 0;
	d->i.to_die = 0;
	d->i.to_eat = 0;
	d->pids = NULL;
	d->i.to_sleep = 0;
	d->i.satiated_philos = 0;
	d->i.sleep_sem = NULL;
	d->i.eat_sem = NULL;
	d->i.out_sem = NULL;
	d->i.start_sem = NULL;
	d->i.forks = NULL;
	d->i.death_sem = NULL;
	unlink_semaphores();
	return ;
}

void	init_philos(t_data *d)
{
	int	i;

	d->pids = malloc(sizeof(int) * d->i.philo_nbr);
	if (d->pids == NULL)
		return ;
	i = 0;
	while (i < d->i.philo_nbr)
	{
		d->ph.id = i + 1;
		d->ph.is_lf_taken = false;
		d->ph.is_rf_taken = false;
		d->ph.time_of_starvation = d->i.to_die;
		i++;
	}
	return ;
}

t_b	open_semaphores(t_data *d)
{
	d->i.forks = sem_open(FORKS, O_CREAT, S_IRWXU, 10);
	if (d->i.forks == SEM_FAILED)
		return (false);
	d->i.death_sem = sem_open(DEATH_SEM, O_CREAT, S_IRWXU, 1);
	if (d->i.death_sem == SEM_FAILED)
		return (false);
	d->i.eat_sem = sem_open(EAT_SEM, O_CREAT, S_IRWXU, 1);
	if (d->i.eat_sem == SEM_FAILED)
		return (false);
	d->i.start_sem = sem_open(START_SEM, O_CREAT, S_IRWXU, 1);
	if (d->i.start_sem == SEM_FAILED)
		return (false);
	d->i.sleep_sem = sem_open(SLEEP_SEM, O_CREAT, S_IRWXU, 1);
	if (d->i.sleep_sem == SEM_FAILED)
		return (false);
	d->i.out_sem = sem_open(OUT_SEM, O_CREAT, S_IRWXU, 1);
	if (d->i.out_sem == SEM_FAILED)
		return (false);
	return (true);
}

t_b	init_child_semaphores(t_data *d)
{
	if (open_sem_child(&d->i.forks, FORKS, d->i.philo_nbr))
		return (false);
	if (open_sem_child(&d->i.death_sem, DEATH_SEM, 1))
		return (destroy_sems(d, 1));
	if (open_sem_child(&d->i.eat_sem, EAT_SEM, 1))
		return (destroy_sems(d, 2));
	if (open_sem_child(&d->i.start_sem, START_SEM, 1))
		return (destroy_sems(d, 3));
	if (open_sem_child(&d->i.sleep_sem, SLEEP_SEM, 1))
		return (destroy_sems(d, 4));
	if (open_sem_child(&d->i.out_sem, OUT_SEM, 1))
		return (destroy_sems(d, 5));
	return (true);
}

t_b	init_table(t_data *d)
{
	int	i;

	i = 0;
	if (!open_semaphores(d))
	{
		printf("Error while creating the semaphore\n");
		return (false);
	}
	init_philos(d);
	return (true);
}
