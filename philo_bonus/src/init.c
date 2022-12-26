/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:29:38 by rkanmado          #+#    #+#             */
/*   Updated: 2022/12/26 08:37:07 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	init(t_data *d)
{
	d->i.meal_required = -1;
	d->i.philo_nbr = 0;
	d->i.to_die = 0;
	d->i.to_eat = 0;
	d->i.to_sleep = 0;
	d->i.satiated_philos = 0;
	d->philos = NULL;
	d->forks = NULL;
	return ;
}

void	init_philos(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->i.philo_nbr)
	{
		d->philos[i].id = i + 1;
		d->philos[i].is_lf_taken = false;
		d->philos[i].is_rf_taken = false;
		d->philos[i].time_of_starvation = d->i.to_die;
		d->philos[i].i = &d->i;
		i++;
	}
	return ;
}

t_b	alloc_philos_and_forks(t_data *d)
{
	d->philos = malloc(sizeof(t_philo) * d->i.philo_nbr);
	if (d->philos == NULL)
		return (false);

	return (true);
}

t_b	init_main_semaphores(t_data *d)
{
	if (open_sem_main(&d->forks, FORKS, d->i.philo_nbr))
		return (false);
	if (open_sem_main(&d->i.death_sem, DEATH_SEM, 1))
		return (destroy_sems(d, 1));
	if (open_sem_main(&d->i.eat_sem, EAT_SEM, 1))
		return (destroy_sems(d, 2));
	if (open_sem_main(&d->i.start_sem, START_SEM, 1))
		return (destroy_sems(d, 3));
	if (open_sem_main(&d->i.sleep_sem, SLEEP_SEM, 1))
		return (destroy_sems(d, 4));
	if (open_sem_main(&d->i.starv_sem, STARV_SEM, 1))
		return (destroy_sems(d, 5));
	if (open_sem_main(&d->i.out_sem, OUT_SEM, 1))
		return (destroy_sems(d, 6));
	return (true);
}

t_b	init_child_semaphores(t_data *d)
{
	if (open_sem_child(&d->forks, FORKS, d->i.philo_nbr))
		return (false);
	if (open_sem_child(&d->i.death_sem, DEATH_SEM, 1))
		return (destroy_sems(d, 1));
	if (open_sem_child(&d->i.eat_sem, EAT_SEM, 1))
		return (destroy_sems(d, 2));
	if (open_sem_child(&d->i.start_sem, START_SEM, 1))
		return (destroy_sems(d, 3));
	if (open_sem_child(&d->i.sleep_sem, SLEEP_SEM, 1))
		return (destroy_sems(d, 4));
	if (open_sem_child(&d->i.starv_sem, STARV_SEM, 1))
		return (destroy_sems(d, 5));
	if (open_sem_child(&d->i.out_sem, OUT_SEM, 1))
		return (destroy_sems(d, 6));
	return (true);
}

void	init_table(t_data *d)
{
	int	i;

	i = 0;
	close_semaphores(d);
	if (alloc_philos_and_forks(d) == false)
		error();
	init_main_semaphores(d);
	init_philos(d);
	return ;
}
